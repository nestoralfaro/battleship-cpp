///////////////////////////////// board.cpp ///////////////////////////////////
/*******************************************************************************
Implementation file name: board.cpp
Desc: The following is the source code for the functions defined in board.hpp. It
 makes the pieces and board needed to play a battleship game.
*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
#include "board.hpp"

/**************************SetUpShipSizes()****************************
Public Method Name: SetUpShipSizes()
Desc: This method sets all the ship's sizes and names.
**********************************************************************/
void board::SetUpShipSizes(BoardUtility::Ships& ships) {
    board::pieces[0].craft = BoardUtility::Ship::empty;

    board::pieces[1].craft = BoardUtility::Ship::carrier; // carrier
    board::pieces[2].craft = BoardUtility::Ship::battleship; // battleship
    board::pieces[3].craft = BoardUtility::Ship::cruiser; // cruiser
    board::pieces[4].craft = BoardUtility::Ship::submarine; // submarine
    board::pieces[5].craft = BoardUtility::Ship::destroyer; // destroyer

    board::pieces[1].size = 5; // carrier
    board::pieces[2].size = 4; // battleship
    board::pieces[3].size = 3; // cruiser
    board::pieces[4].size = 3; // submarine
    board::pieces[5].size = 2; // destroyer
}

/**************************PlaceShip()****************************
Public Method Name: PlaceShip()
Desc: This method places a ship on the board. It takes the board
by reference and the ship to place. The ship to place would be a
struct with all its properties (name, coordinates, state, and size).
**********************************************************************/
void board::PlaceShip(BoardUtility::Boardtype& battleboard, BoardUtility::ShipCraft shipToPlace ) {
    for (int s = 0; s < shipToPlace.size; s++) {
        if (shipToPlace.direction == BoardUtility::Direction::vertical) {
            battleboard [int(shipToPlace.row) + s][int(shipToPlace.col)].ship = shipToPlace.craft;
        }
        else {
            battleboard [int(shipToPlace.row)][int(shipToPlace.col) + s].ship = shipToPlace.craft;
        }
    }
}