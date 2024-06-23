/**
    @file boardSolver.cpp
    @author Amodh Dhakal

    Includes definitions for functions required to solve the board
 */

#include "boardSolver.hpp"

using namespace std;

/**
    Verifies whether a board piece is a valid board piece for that location
    @param charBoard is the board where the board piece is
    @param index is the location of the board piece
    @return true if the number of the board piece is valid, false otherwise
 */
bool isValidPiece(char charBoard[], int index) {
    // Check row
    int row = index / 9;
    int startingRowIdx = row * 9;
    set<char> rowChars;
    for (int rowIndex = startingRowIdx; rowIndex < startingRowIdx + 9; rowIndex++) {
        char ch = charBoard[rowIndex];
        if (ch == 'X' || ch == '\0') {
            continue;
        }
        if (rowChars.contains(ch)) {
            return false;
        }
        rowChars.insert(ch);
    }

    // Check col
    int col = index % 9;
    set<char> colChars;
    for (int colIndex = col; colIndex < 81; colIndex += 9) {
        char ch = charBoard[colIndex];
        if (ch == 'X' || ch == '\0') {
            continue;
        }
        if (colChars.contains(ch)) {
            return false;
        }
        colChars.insert(ch);
    }

    // Check sub board
    //* Don't optimize the places becauses we are multpying and dividing by the same numbers
    //* Optimizing would break the code, because we depending on integer division giving an integer
    int rowPlace = (index / 27) * 27;
    int colPlace = ((col) / 3) * 3;
    int startingIndex = rowPlace + colPlace;

    int indexesList[9] = {startingIndex,      startingIndex + 1,  startingIndex + 2,
                          startingIndex + 9,  startingIndex + 10, startingIndex + 11,
                          startingIndex + 18, startingIndex + 19, startingIndex + 20};

    set<char> subChars;
    for (int charIndex : indexesList) {
        char ch = charBoard[charIndex];
        if (ch == 'X' || ch == '\0') {
            continue;
        }
        if (subChars.contains(ch)) {
            return false;
        }
        subChars.insert(ch);
    }

    return true;
}

/**
   Tries to solve the sudoku board using a backtracking algorithm
   @param charBoard is the board being solved
   @param possiblePieces is the possible pieces each board piece could be
   @param index is the current index that is being solved
   @return true if board is solved, false otherwise
 */
bool hasSudokuSolved(char charBoard[], vector<set<char>> &possiblePieces, int index) {
    if (index == 81) {
        return true;
    }

    if (charBoard[index] != 'X') {
        return hasSudokuSolved(charBoard, possiblePieces, index + 1);
    }

    for (char ch : possiblePieces[index]) {
        charBoard[index] = ch;
        if (isValidPiece(charBoard, index) && hasSudokuSolved(charBoard, possiblePieces, index + 1)) {
            return true;
        }
        charBoard[index] = 'X';
    }

    return false;
}
