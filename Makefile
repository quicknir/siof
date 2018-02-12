CXX=clang++
CXXFLAGS=-std=c++11 -O2 -fPIC -g -Wall -fsanitize=address
LDFLAGS="-Wl,-rpath,."

all: maina mainb mainab mainba

a.o: a.cpp constants.hpp
	${CXX} -o a.o -c a.cpp ${CXXFLAGS}

b.o: b.cpp constants.hpp
	${CXX} -o b.o -c b.cpp ${CXXFLAGS}

a.so: a.o
	${CXX} -shared -o a.so a.o ${CXXFLAGS} ${LDFLAGS}

b.so: b.o
	${CXX} -shared -o b.so b.o ${CXXFLAGS} ${LDFLAGS}

main.o: main.cpp
	${CXX} -o main.o -c main.cpp ${CXXFLAGS}

maina: main.o a.so
	${CXX} -o maina main.o a.so ${CXXFLAGS} ${LDFLAGS}

mainb: main.o b.so
	${CXX} -o mainb main.o b.so ${CXXFLAGS} ${LDFLAGS}

mainab: main.o a.so b.so
	${CXX} -o mainab main.o a.so b.so ${CXXFLAGS} ${LDFLAGS}

mainba: main.o a.so b.so
	${CXX} -o mainba main.o b.so a.so ${CXXFLAGS} ${LDFLAGS}

clean:
	rm -f a.o b.o a.so b.so main.o maina mainb mainab mainba

run: maina mainb mainab mainba
	@echo "Running maina:"; ./maina; echo "Running mainb:"; ./mainb; echo "Running mainab:"; ./mainab; echo "Running mainba:"; ./mainba

.PHONY: all clean
