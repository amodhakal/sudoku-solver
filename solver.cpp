/**
    @file solver.cpp
    @author Amodh Dhakal

    The starting file of the Sudoku Solver CLI application
 */

#include "utils/boardSolver.hpp"
#include "utils/ioManager.hpp"

#include <iostream>
#include <set>
#include <vector>

using namespace std;

/**
    The starting function of the Sudoku Solver CLI application
    @param argc is the count of arguments given
    @param argv is the list of arguments given
 */
int main(int argc, char **argv) {
    // Initialize the board and possible pieces
    char board[81];
    vector<set<char>> possiblePieces(81);
    getBoardFromFile(argc, argv, board, possiblePieces);

    // Solve the Sudoku
    if (hasSudokuSolved(board, possiblePieces, 0)) {
        printBoard(board);
    } else {
        cerr << "No solution found\n";
    }

    return 0;
}
