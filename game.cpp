///////////////////////////////// game.cpp ///////////////////////////////////
/*******************************************************************************
Implementation file name: game.cpp
Desc: The following is the source code for the functions defined in game.hpp. It
 controls the logic and rules of the game battleship.
*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
#include "game.hpp"

/****************************SetShip()*********************************
 Public Method Name: SetShip()
 Desc: This method sets a ship's column, row, and direction. It will
 need to be passed a string containing the ship entered (e.g., F7H) by
 value, and the ship struct to be set up by reference. Such ship struct
 contains its column, row, and direction.
**********************************************************************/
void game::SetShip(std::string shipEntered, BoardUtility::ShipCraft& ship) {
    ship.col = ReturnColumn(shipEntered[0]);
    ship.row = ReturnRow(shipEntered[1]);
    ship.direction = ReturnDirection(shipEntered[2]);
}

/****************************SetShot()*********************************
 Public Method Name: SetShot()
 Desc: This method sets a shot's column and row. It needs to be passed
 a string containing the shot entered (e.g., a7) by value, and the shot
 struct to be set up by reference. Such shot struct contains its column,
 and row.
**********************************************************************/
void game::SetShot(std::string shotEntered, BoardUtility::Fire& shot) {
    shot.col = ReturnColumn(shotEntered[0]);
    shot.row = ReturnRow(shotEntered[1]);
}

/****************************ReturnColumn()****************************
Private Method Name: ReturnColumn()
Desc: This method is a helper of SetShip() and SetShot(). It takes a
char and returns the corresponding enum value. The char should be the
column on the board.
**********************************************************************/
BoardUtility::Column game::ReturnColumn(char pos) {
    switch(pos){
        case 'a':
        case 'A':
            return BoardUtility::Column::a;
        case 'b':
        case 'B':
            return BoardUtility::Column::b;
        case 'c':
        case 'C':
            return BoardUtility::Column::c;
        case 'd':
        case 'D':
            return BoardUtility::Column::d;
        case 'e':
        case 'E':
            return BoardUtility::Column::e;
        case 'f':
        case 'F':
            return BoardUtility::Column::f;
        case 'g':
        case 'G':
            return BoardUtility::Column::g;
        case 'h':
        case 'H':
            return BoardUtility::Column::h;
        case 'i':
        case 'I':
            return BoardUtility::Column::i;
        case 'j':
        case 'J':
            return BoardUtility::Column::j;
        case 'q':
        case 'Q':
            return BoardUtility::Column::q;
    }
}

/****************************ReturnRow()*******************************
Private Method Name: ReturnRow()
Desc: This method is a helper of SetShip() and SetShot(). It takes a
char and returns the corresponding enum value. The char should be the
row on the board.
**********************************************************************/
BoardUtility::Row game::ReturnRow(char pos) {
    switch(pos) {
        case '0':
            return BoardUtility::Row::r0;
        case '1':
            return BoardUtility::Row::r1;
        case '2':
            return BoardUtility::Row::r2;
        case '3':
            return BoardUtility::Row::r3;
        case '4':
            return BoardUtility::Row::r4;
        case '5':
            return BoardUtility::Row::r5;
        case '6':
            return BoardUtility::Row::r6;
        case '7':
            return BoardUtility::Row::r7;
        case '8':
            return BoardUtility::Row::r8;
        case '9':
            return BoardUtility::Row::r9;
    }
}

/****************************ReturnDirection()*******************************
Private Method Name: ReturnDirection()
Desc: This method is a helper of SetShip() and SetShot(). It takes a
char and returns the corresponding enum value. The char should be the
direction on the board (either vertical or horizontal).
**********************************************************************/
BoardUtility::Direction game::ReturnDirection (char orientation) {
    switch (orientation) {
        case 'v':
        case 'V':
            return BoardUtility::Direction::vertical;
        case 'h':
        case 'H':
            return BoardUtility::Direction::horizontal;
    }
}

/****************************ReturnResult()*********************************
 Public Method Name: ReturnResult()
 Desc: This method shoots the board and returns the result (e.g., hit, miss
 or sunk). It needs to be passed a struct by value (that is the shot
 with its column and row), the board by reference, and all the ships by
 reference too, to find out the ship affected. The 'ships' is a vector of
 structs, where each struct is a ShipCraft which contains the craft (e.g.,
 carrier, battleship, etc.), the state of it (e.g., alive or sunk), its
 coordinate on the board (column and row), its direction (vertical or
 horizontal), and its size.
**********************************************************************/
BoardUtility::Result game::ReturnResult(BoardUtility::Fire shot, BoardUtility::Boardtype& board, BoardUtility::Ships& ships) {
    for (int i = 1; i < ships.size(); i++) {

        if (ships[i].craft == board[(int)shot.row][(int)shot.col].ship){

            if ((board[(int)shot.row][(int)shot.col].result != BoardUtility::Result::sunk)) {
                board[(int)shot.row][(int)shot.col].result = BoardUtility::Result::hit;
            }

            //If it's not sunk
            if (ships[i].state != BoardUtility::State::sunk) {
                //SINK IT!
                if (IsSunk(ships[i], board)) {
                    //call 'IsSunk' functions here, that way it doesn't have to call them everytime
                    //In other words, sink the ship here!
                    ships[i].state = BoardUtility::State::sunk;
                    return BoardUtility::Result::sunk;
                }
                else {
                    return BoardUtility::Result::hit;
                }
            }
            //Otherwise, it is sunk already
            else {
                //Therefore
                return BoardUtility::Result::sunk;
            }
        }
    }
    board[(int)shot.row][(int)shot.col].result = BoardUtility::Result::miss;
    return BoardUtility::Result::miss;
}

/****************************IsSunk()*********************************
 Private Method Name: IsSunk()
 Desc: This method is a helper of ReturnResult(). It needs to be passed
 the ship struct by reference, and the board by reference as well. It
 evaluates if such ship is sunk. It returns true if it is, otherwise
 false.

 Due to performance purposes, it will also sink the ship on the board
 if it is sunk.
**********************************************************************/
bool game::IsSunk (BoardUtility::ShipCraft& ship, BoardUtility::Boardtype& board) {

    if (AllAreHit(ship, board)){
        SinkShip(ship, board);
        return true;
    }
    else {
        return false;
    }
}

/****************************IncrementTurn()***************************
 Public Method Name: IncrementTurn()
 Desc: This method will take a counter integer by reference, and
 increment it by 1.
**********************************************************************/
void game::IncrementTurn (int& counter) {
    ++counter;
}

/****************************Quit()************************************
 Public Method Name: Quit()
 Desc: This method evaluates if the user decided to quit or not by
 checking the shot. It returns true if the user quit, otherwise false.
 It needs the shot to be passed by value.
**********************************************************************/
bool game::Quit (BoardUtility::Fire shot) {
    return ((shot.col == BoardUtility::Column::q) && (shot.row == BoardUtility::Row::r0));
}

/****************************AllAreHit()*******************************
 Private Method Name: AllAreHit()
 Desc: This method is a helper of IsSunk(). It evaluates if all the
 cells of a ship on the board are hit. It returns true if they are,
 otherwise, false.

 It needs a struct ShipCraft to be passed by reference, and the board
 to be passed by reference as well.
**********************************************************************/
bool game::AllAreHit(BoardUtility::ShipCraft& ship, BoardUtility::Boardtype& battleground) {
    for (int s = 0; s < ship.size; s++) {
        if (ship.direction == BoardUtility::Direction::vertical){
            if ((battleground [int(ship.row) + s][int(ship.col)].result != BoardUtility::Result::hit)){
                return false;
            }}
        else {
            if ((battleground [int(ship.row)][int(ship.col) + s].result != BoardUtility::Result::hit)){
                return false;
            }
        }
    }

    return true;
}

/****************************SinkShip()*******************************
 Private Method Name: SinkShip()
 Desc: This method is a helper of AllAreHit()

 It needs a struct ShipCraft to be passed by reference, and the board
 to be passed by reference as well.
**********************************************************************/
void game::SinkShip(BoardUtility::ShipCraft& ship, BoardUtility::Boardtype& battleground) {
    for (int s = 0; s < ship.size; s++) {
        if (ship.direction == BoardUtility::Direction::vertical){
            battleground [int(ship.row) + s][int(ship.col)].result = BoardUtility::Result::sunk;
        }
        else {
            battleground [int(ship.row)][int(ship.col) + s].result = BoardUtility::Result::sunk;
        }
    }
}

/****************************IsOver()**********************************
 Public Method Name: IsOver()
 Desc: This method verifies if the game is over by checking the state
 of all the ships. If it is over returns true, otherwise false.

 It needs a struct ShipCraft to be passed by reference, and the board
 to be passed by reference as well.
**********************************************************************/
bool game::IsOver (BoardUtility::Ships ships) {
    return AllAreSunk(ships);
}

/****************************AllAreSunk()******************************
 Private Method Name: AllAreSunk()
 Desc: This method is a helper of IsOver(). It verifies if all the ships
 are sunk. Returns true if they are, otherwise false.
 It takes a struct ShipCraft passed by value.
**********************************************************************/
bool game::AllAreSunk (BoardUtility::Ships ships) {
    for (int ship = 1; ship < ships.size(); ship++){
        if (ships[ship].state != BoardUtility::State::sunk) {
            return false;
        }
    }
    return true;
}