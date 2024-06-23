solver:
	g++ -Wall -std=c++20 solver.cpp -o solver
test:
	./solver input.txt > output.txt
	diff output.txt expected.txt