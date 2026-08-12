SHELL := /bin/bash
CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type -Werror=uninitialized -Wno-sign-compare
RM = rm -rf

HEADERS = point.hpp polygon.hpp gis.hpp
OBJECTS = main.o point.o polygon.o gis.o
TESTS = test-1-point test-2-polygon test-3-polygon-advanced test-4-gis
CATCH = test/catch/catch.o

all: main $(TESTS)

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(CATCH): test/catch/catch.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

simple-run: main
	echo -e "bad-file-name.zz\nsimple-polygons.txt\n1\n1\n3\n3\n7\n7\nq\n" | ./main

complex-run: main
	echo -e "polygons.txt\n2\n14\n0\n2\n2\n8\n5\n9\n5\n5\n5\n0\n7\n4\nq\n" | ./main

test-all: $(TESTS)

test-1-point: test/test-1-point.o point.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-2-polygon: test/test-2-polygon.o polygon.o point.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-3-polygon-advanced: test/test-3-polygon-advanced.o point.o polygon.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-4-gis: test/test-4-gis.o point.o polygon.o gis.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-mem1: test-2-polygon
	valgrind --error-exitcode=1 --leak-check=full ./test-2-polygon

test-mem2: test-4-gis
	valgrind --error-exitcode=1 --leak-check=full ./test-4-gis

test-mem: test-mem1 test-mem2

clean:
	$(RM) *.dSYM test/*.dSYM *.o *.gc* main test/*.o $(CATCH) $(TESTS)

.PHONY: all main simple-run complex-run test-all test-mem1 test-mem2 test-mem clean test-1-point test-2-polygon test-3-polygon-advanced test-4-gis
