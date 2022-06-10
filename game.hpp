/*******************************************************************************
Header file name: game.hpp
Desc: This header contains a class with function definitions for game.cpp
********************************************************************************/
#pragma once
#include "board.hpp"
#include <vector>
#include <string>

class game {
private:
    bool AllAreSunk (BoardUtility::Ships);
    bool AllAreHit(BoardUtility::ShipCraft&, BoardUtility::Boardtype&);
    bool IsSunk (BoardUtility::ShipCraft&, BoardUtility::Boardtype&);
    BoardUtility::Column ReturnColumn(char);
    BoardUtility::Row ReturnRow(char);
    BoardUtility::Direction ReturnDirection (char);
    void SinkShip(BoardUtility::ShipCraft &ship, BoardUtility::Boardtype &battleground);
public:
    void SetShip(std::string shipEntered, BoardUtility::ShipCraft &ship);
    void SetShot(std::string shotEntered, BoardUtility::Fire &shot);
    bool IsOver (BoardUtility::Ships);
    BoardUtility::Result ReturnResult(BoardUtility::Fire, BoardUtility::Boardtype&, BoardUtility::Ships&);
    void IncrementTurn(int&);
    bool Quit(BoardUtility::Fire);
};