CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		solution

solution:	solution.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f solution

test:		test-easy

test-easy:	solution
	@echo Testing input/output 1...
	@diff --suppress-common-lines -y <(./solution < easy.txt) output1

test-medium:   solution
	@echo Testing input/output 2...
	@diff --suppress-common-lines -y <(./solution < medium.txt) output2

ec:	solution
	@echo Testing input/output3...
	@diff --suppress-common-lines -y <(./solution < cc1.txt) output3

