solver:
	g++ -Wall -std=c++20 utils/ioManager.cpp solver.cpp -o solver
test:
	rm -rf solver
	make solver
	./solver resources/input.txt > output.txt
	diff output.txt resources/expected.txt