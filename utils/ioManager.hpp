#pragma once

#include <set>
#include <vector>

void getBoardFromFile(int argc, char **argv, char board[81], std::vector<std::set<char>>& possiblePieces);

void printBoard(char *board);