/**
    @file boardSolver.hpp
    @author Amodh Dhakal

    Includes declarations for functions required to solve the board
 */

#pragma once
#include <set>
#include <vector>

/**
   Tries to solve the sudoku board using a backtracking algorithm
   @param charBoard is the board being solved
   @param possiblePieces is the possible pieces each board piece could be
   @param index is the current index that is being solved
   @return true if board is solved, false otherwise
 */
bool hasSudokuSolved(char charBoard[], std::vector<std::set<char>> &possiblePieces, int index);
