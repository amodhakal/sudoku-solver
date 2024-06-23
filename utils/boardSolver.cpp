#include "boardSolver.hpp"

using namespace std;

bool hasSudokuSolved(char charBoard[], vector<set<char>> &possiblePieces, int index) {
    if (index == 81) {
        return true;
    }

    if (charBoard[index] != 'X') {
        return hasSudokuSolved(charBoard, possiblePieces, index + 1);
    }

    for (char ch : possiblePieces[index]) {
        charBoard[index] = ch;
        if (isValidPiece(charBoard, index)) {
            if (hasSudokuSolved(charBoard, possiblePieces, index + 1)) {
                return true;
            }
        }
        charBoard[index] = 'X';
    }

    return false;
}

bool isValidPiece(char charBoard[], int index) {
    // Check row
    int row = index / 9;
    int startingRowIdx = row * 9;
    set<char> rowChars;
    for (int rowIndex = startingRowIdx; rowIndex < startingRowIdx + 9; rowIndex++) {
        char ch = charBoard[rowIndex];
        if (ch == 'X' || ch == '\0')
            continue;
        if (rowChars.find(ch) != rowChars.end()) {
            return false;
        }
        rowChars.insert(ch);
    }

    // Check col
    int col = index % 9;
    set<char> colChars;
    for (int colIndex = col; colIndex < 81; colIndex += 9) {
        char ch = charBoard[colIndex];
        if (ch == 'X' || ch == '\0')
            continue;
        if (colChars.find(ch) != colChars.end()) {
            return false;
        }
        colChars.insert(ch);
    }

    // Check sub board
    int rowPlace = (index / 27) * 27;
    int colPlace = ((index % 9) / 3) * 3;
    int startingIndex = rowPlace + colPlace;
    int indexesList[9] = {startingIndex,      startingIndex + 1,  startingIndex + 2,
                          startingIndex + 9,  startingIndex + 10, startingIndex + 11,
                          startingIndex + 18, startingIndex + 19, startingIndex + 20};

    set<char> subChars;
    for (int charIndex : indexesList) {
        char ch = charBoard[charIndex];
        if (ch == 'X' || ch == '\0')
            continue;
        if (subChars.find(ch) != subChars.end()) {
            return false;
        }
        subChars.insert(ch);
    }

    return true;
}
