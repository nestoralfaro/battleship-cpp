/*******************************************************************************
Header file name: io.hpp
Desc: This header contains a class with function definitions for io.cpp
********************************************************************************/

#pragma once
#include "board.hpp"
#include <vector>
#include <string>

class io {
private:
    void DisplayShip (BoardUtility::Result result, BoardUtility::Ship ship);
    void DisplayShot (std::string);
    void DisplaySunk (BoardUtility::Ship);

public:
    std::vector<std::string> EnterShips();
    std::string EnterShot();
    void DisplayBoard(BoardUtility::Boardtype board);
    void DisplayFeedback(std::string, BoardUtility::Ship, BoardUtility::Result);
    void DisplayWin(int);
    void DisplayQuit();
};
