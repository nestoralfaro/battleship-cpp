/*******************************************************************************
Header file name: board.hpp
Desc: This header contains a class with function definitions for board.cpp
********************************************************************************/
#pragma once
#include <vector>

namespace BoardUtility {

    enum class Ship {
        empty, carrier, battleship, cruiser,
        submarine, destroyer
    };
    enum class Column { a, b, c, d, e, f, g, h, i, j, q };
    enum class Row { r0, r1, r2, r3, r4, r5, r6, r7, r8, r9 };
    enum class Direction { horizontal, vertical };
    //Starting at one so the constructor does not build a board
    //with default data types 'hit', but it builds zero values.
    enum class Result {hit = 1, miss, sunk};
    enum class State {alive, sunk, shot};

    struct ShipCraft {
        Ship craft;
        State state;
        Column col;
        Row row;
        Direction direction;
        int size;
    };
    struct Cell {
        Ship ship;
        State state;
        Result result;
    };

    using BoardRow = std::vector<Cell>;
    using Boardtype = std::vector<BoardRow>;

    struct Fire {
        Column col;
        Row row;
    };

    using Ships = std::vector<ShipCraft>;
}

class board {
private:
    const short int MANY_SHIPS = 6;
    const short int BOARD_SIZE = 10;
    void SetUpShipSizes(BoardUtility::Ships&);
    BoardUtility::Boardtype battleground;
    BoardUtility::Fire fire;
    BoardUtility::Ships pieces;

public:
    /****************************board()*********************************
     Constructor Name: board()
     Desc: This default constructor builds a board of size 10x10 and the
     5 pieces (ships) for the game.
    **********************************************************************/
    board() : battleground(BOARD_SIZE, BoardUtility::BoardRow (BOARD_SIZE)), pieces(MANY_SHIPS) {
        SetUpShipSizes(this->pieces);
    };

    void PlaceShip(BoardUtility::Boardtype&, BoardUtility::ShipCraft);

    /****************************GetBoard()********************************
     Public Method Name: GetBoard()
     Desc: This getter returns the board.
    **********************************************************************/
    BoardUtility::Boardtype GetBoard(){
        return this->battleground;
    }

    /****************************GetShips()********************************
     Public Method Name: GetShips()
     Desc: This getter returns the pieces (ships).
    **********************************************************************/
    BoardUtility::Ships GetShips(){
        return this->pieces;
    }

    /****************************GetFire()*********************************
     Public Method Name: GetFire()
     Desc: This getter returns the a fire struct, which are the coordinates
     for a shot.
    **********************************************************************/
    BoardUtility::Fire GetFire(){
        return this->fire;
    }

};