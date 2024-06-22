g++ -Wall -std=c++17 solver.cpp -o solver
./solver input.txt > output.txt
diff output.txt expected.txt