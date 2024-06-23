#pragma once
#include <set>
#include <vector>

bool hasSudokuSolved(char charBoard[], std::vector<std::set<char>> &possiblePieces, int index);
bool isValidPiece(char charBoard[], int index);