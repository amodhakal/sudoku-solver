#include "utils/boardSolver.hpp"
#include "utils/ioManager.hpp"

#include <iostream>
#include <set>
#include <vector>

using namespace std;

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