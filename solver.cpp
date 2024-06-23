#include <iostream>
#include <set>

int main(int argc, char **argv) {
    using namespace std;

    // Create file reader
    if (argc != 2) {
        cerr << "usage: ./solve [input-file]" << endl;
        exit(1);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        cerr << "Unable to open file: " << filename << endl;
        exit(1);
    }

    // Read files into the board vector
    set<char> board[81];
    int readerIndex = 0;
    while (readerIndex < 81) {
        char ch = fgetc(file);
        if (ch == '\n' || ch == ' ') {
            continue;
        }

        if (ch == EOF) {
            cerr << "Unexpected EOF encountered" << endl;
            exit(1);
        }

        if ('1' <= ch && ch <= '9') {
            set<char> possiblePieces = set<char>();
            possiblePieces.insert(ch);
            board[readerIndex++] = possiblePieces;
            continue;
        }

        if (ch == 'X') {
            set<char> possiblePieces = set<char>();
            possiblePieces.insert('1');
            possiblePieces.insert('2');
            possiblePieces.insert('3');
            possiblePieces.insert('4');
            possiblePieces.insert('5');
            possiblePieces.insert('6');
            possiblePieces.insert('7');
            possiblePieces.insert('8');
            possiblePieces.insert('9');
            board[readerIndex++] = possiblePieces;
            continue;
        }

        cerr << "Unexpected charcter encountered: " << ch << endl;
        exit(1);
    }

    fclose(file);

    // Optimize the rows
    int rowPreviousKnownVals = 0;
    while (true) {
        for (int rowIdx = 0; rowIdx < 9; rowIdx++) {
            set<char> knownValSet = set<char>();

            // Find known characters and add it to the list
            for (int colIdx = 0; colIdx < 9; colIdx++) {
                set<char> piece = board[rowIdx * 9 + colIdx];
                if (piece.size() != 1) {
                    continue;
                }

                for (char ch : piece) {
                    knownValSet.insert(ch);
                }
            }

            // Go through column and remove the known values
            for (char knownVal : knownValSet) {
                for (int colIdx = 0; colIdx < 9; colIdx++) {
                    if (board[rowIdx * 9 + colIdx].size() == 1) {
                        continue;
                    }

                    board[rowIdx * 9 + colIdx].erase(knownVal);
                }
            }
        }

        int currentKnownVals = 0;
        for (set<char> piece : board) {
            if (piece.size() == 1) {
                currentKnownVals++;
            }
        }

        if (currentKnownVals == rowPreviousKnownVals) {
            break;
        }

        rowPreviousKnownVals = currentKnownVals;
    }
    // Optimize the cols
    int colPreviousKnownVals = 0;
    while (true) {
        for (int colIdx = 0; colIdx < 9; colIdx++) {
            set<char> knownValSet = set<char>();

            // Find known characters and add it to the list
            for (int rowIdx = 0; rowIdx < 9; rowIdx++) {
                set<char> piece = board[rowIdx * 9 + colIdx];
                if (piece.size() != 1) {
                    continue;
                }

                for (char ch : piece) {
                    knownValSet.insert(ch);
                }
            }

            // Go through rows and remove the known values
            for (char knownVal : knownValSet) {
                for (int rowIdx = 0; rowIdx < 9; rowIdx++) {
                    if (board[rowIdx * 9 + colIdx].size() == 1) {
                        continue;
                    }

                    board[rowIdx * 9 + colIdx].erase(knownVal);
                }
            }
        }

        int currentKnownVals = 0;
        for (set<char> piece : board) {
            if (piece.size() == 1) {
                currentKnownVals++;
            }
        }

        if (currentKnownVals == colPreviousKnownVals) {
            break;
        }

        colPreviousKnownVals = currentKnownVals;
    }

    // Optimize the sub boards
    int subPreviousKnownVals = 0;
    while (true) {
        for (int subIdx = 0; subIdx < 81; subIdx += 3) {
            int rowPlace = subIdx / 27;
            int colPlace = (subIdx % 9) / 3;

            int startingIndex = 0;
            switch (rowPlace) {
            case 0:
                startingIndex += 0;
                break;
            case 1:
                startingIndex += 27;
                break;
            default:
                startingIndex += 54;
                break;
            }

            switch (colPlace) {
            case 0:
                startingIndex += 0;
                break;
            case 1:
                startingIndex += 3;
                break;
            default:
                startingIndex += 6;
                break;
            }

            int indexesList[9] = {
                startingIndex,      startingIndex + 1,  startingIndex + 2,
                startingIndex + 9,  startingIndex + 10, startingIndex + 11,
                startingIndex + 18, startingIndex + 19, startingIndex + 20};

            for (int index : indexesList) {
                set<char> knownValSet = set<char>();

                // Find known characters and add it to the list
                for (int rowIdx = 0; rowIdx < 9; rowIdx++) {
                    set<char> piece = board[index];
                    if (piece.size() != 1) {
                        continue;
                    }

                    for (char ch : piece) {
                        knownValSet.insert(ch);
                    }
                }

                // Go through rows and remove the known values
                for (char knownVal : knownValSet) {
                    for (int rowIdx = 0; rowIdx < 9; rowIdx++) {
                        if (board[index].size() == 1) {
                            continue;
                        }

                        board[index].erase(knownVal);
                    }
                }
            }
        }

        int currentKnownVals = 0;
        for (set<char> piece : board) {
            if (piece.size() == 1) {
                currentKnownVals++;
            }
        }

        if (currentKnownVals == subPreviousKnownVals) {
            break;
        }

        subPreviousKnownVals = currentKnownVals;
    }

    // TODO: Use backtracking algorithm

    // Print the board
    int printerIndex = 0;
    while (printerIndex < 81) {
        set<char> possiblePieces = board[printerIndex];
        if (possiblePieces.size() != 1) {
            cout << 'X';
        } else {
            for (char ch : possiblePieces) {
                cout << ch;
            }
        }

        if (printerIndex % 9 == 8) {
            cout << "\n";
        } else {
            cout << " ";
        }

        printerIndex++;
    }

    return 0;
}