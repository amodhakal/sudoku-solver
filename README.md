## Sudoku Solver
Solves sudoku board using backtracking algorithm, written in C++.

To run the application, you need the unsolved board to look like input.txt file where X represents an unknown value,
while the numbers represent the known values. Once you have that:

1. Run `make solver` to create the C++ executable.
2. Run `./solver [input.txt]` where the `[input.txt]` is the relative path of the input file discussed above from the executable.

The application will solve the board, and return the board in the standard output, which will look very similar to the
formatting of the `expected.txt` file. If you want the solved board to be written to a certain file, run `./solver [input.txt] > [output.txt]` where the `[input.txt]` is the relative path of the input file discussed above from the executable and the `[output.txt]` is relative path to the file where you want the solved board to be written to.