/**
    @file ioManager.hpp
    @author Amodh Dhakal

    Includes declarations for functions to interact with the IO
 */

#pragma once

#include <set>
#include <vector>

/**
    From the argument list, takes the file name, reads the board, and fills up the relevant vectors
    @param argc is the count of arguments given
    @param argv is the list of arguments given
    @param board represents the sudoku board as an array
    @param possiblePieces is a vector of sets of characters represnting a set of characters the certain piece can be
 */
void getBoardFromFile(int argc, char **argv, char board[81], std::vector<std::set<char>> &possiblePieces);

/**
    Prints the board to the terminal
    @param board that is being printed
 */
void printBoard(char *board);
