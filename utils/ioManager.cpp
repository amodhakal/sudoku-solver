#include "ioManager.hpp"
#include <iostream>

using namespace std;

void getBoardFromFile(int argc, char **argv, char *board, vector<set<char>> &possiblePieces) {
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
            board[readerIndex] = ch;
            possiblePieces[readerIndex].insert(ch);
            readerIndex++;
            continue;
        }
        if (ch == 'X') {
            board[readerIndex] = 'X';
            for (char num = '1'; num <= '9'; num++) {
                possiblePieces[readerIndex].insert(num);
            }
            readerIndex++;
            continue;
        }
        cerr << "Unexpected character encountered: " << ch << endl;
        exit(1);
    }
    fclose(file);
}