#include <iostream>
#include <set>
#include <vector>

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
            possiblePieces.insert(ch);
            board[readerIndex++] = possiblePieces;
            continue;
        }

        cerr << "Unexpected charcter encountered: " << ch << endl;
        exit(1);
    }

    fclose(file);

    // TODO: Optimize the board

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