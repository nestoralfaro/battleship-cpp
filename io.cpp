///////////////////////////////// io.cpp ///////////////////////////////////
/*******************************************************************************
Implementation file name: io.cpp
Desc: The following is the source code for the functions defined in io.hpp. It
 controls the input and output flow to play a battleship game.
*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "io.hpp"

/****************************EnterShips()*****************************
 Public Method Name: EnterShips()
 Desc: This method will allow to input five groups of three characters,
 where the column, row, and direction of a ship are entered and then
 returned as a vector of strings.
**********************************************************************/
std::vector<std::string> io::EnterShips() {
    const short int MAX_SHIPS = 6;
    std::vector<std::string> ships{ MAX_SHIPS };

    for (int ship = 1; ship < ships.size(); ship++){
        std::cin >> ships[ship];
    }

    return ships;
}

/****************************DisplayBoard()*****************************
 Public Method Name: DisplayBoard()
 Desc: This method displays a board passed by value of type Boardtype,
 which is within the BoardUtility namespace. The format should be:

   ABCDEFGHIJ
0 CCCCCCCCCC
1 CCCCCCCCCC
2 CCCCCCCCCC
3 CCCCCCCCCC
4 CCCCCCCCCC
5 CCCCCCCCCC
6 CCCCCCCCCC
7 CCCCCCCCCC
8 CCCCCCCCCC
9 CCCCCCCCCC

 Where every 'C' is replaced by 'X' if a shot hit, 'O' if a shot missed,
 and '.' if it has not been shot.
**********************************************************************/
void io::DisplayBoard(BoardUtility::Boardtype board) {

    std::cout << "  ABCDEFGHIJ" << std::endl;

    for (int row = 0; row < board.size(); row++){
        std::cout << row << " ";
        for (int col = 0; col < board.size(); col++){

            switch (board[row][col].result){
                case BoardUtility::Result::sunk:
                case BoardUtility::Result::hit:
                    std::cout << "X";
                    break;
                case BoardUtility::Result::miss:
                    std::cout << "O";
                    break;
                default:
                    std::cout << ".";
                    break;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/****************************EnterShot()*****************************
 Public Method Name: EnterShot()
 Desc: This method allows user to input a shot and returns it as a
 string.
**********************************************************************/
std::string io::EnterShot() {
    std::string shot;
    std::cin >> shot;
    return shot;
}

/****************************DisplayFeedback()*****************************
 Public Method Name: DisplayFeedback()
 Desc: This method displays the result of a shot in the following format:

 If it missed:
 [shot entered] : [miss]

 If it hit:
 [shot entered] : [Hit] [Ship]

 If the ship is sunk:
 [shot entered] : [Hit] [Ship]
 You sank my [ship]

 It will need the shot entered, ship or cell affected, and the result
 (hit, sink, or miss) to be passed by value.
**********************************************************************/
void io::DisplayFeedback(std::string shot, BoardUtility::Ship ship, BoardUtility::Result result) {
    DisplayShot(shot);
    std::cout << ": ";
    DisplayShip(result, ship);
    if (result == BoardUtility::Result::sunk) {
        std::cout << std::endl;
        DisplaySunk(ship);
    }
    std::cout<< std::endl << std::endl;
}

/****************************DisplayShot()*****************************
 Private Method Name: DisplayShot()
 Desc: This method is a helper of DisplayFeedback(). It displays the
 shot entered in the following format:

 [column][row]
 e.g., h3, h2, a0, etc.

 It will need the shot entered to be passed by value.
**********************************************************************/
void io::DisplayShot (std::string shot){
    std::cout << shot;
}

/****************************DisplayShip()*****************************
 Private Method Name: DisplayShip()
 Desc: This method is a helper of DisplayFeedback(). If it hit, It
 displays 'Hit' and the ship affected, otherwise it displays 'Miss'.
 It does it in the following format:

 Hit [ship]
 e.g., Hit Submarine, Hit Carrier, etc.

 It will need the result (hit, miss, or sink) and the ship to be passed
 by value.
**********************************************************************/
void io::DisplayShip(BoardUtility::Result result, BoardUtility::Ship ship){
    if (result == BoardUtility::Result::hit || result == BoardUtility::Result::sunk){
        std::cout << "Hit ";

        switch (ship) {
            case BoardUtility::Ship::carrier:
                std::cout << "Carrier";
                break;
            case BoardUtility::Ship::battleship:
                std::cout << "Battleship";
                break;
            case BoardUtility::Ship::cruiser:
                std::cout << "Cruiser";
                break;
            case BoardUtility::Ship::submarine:
                std::cout << "Submarine";
                break;
            case BoardUtility::Ship::destroyer:
                std::cout << "Destroyer";
                break;
        }
    } else {
        std::cout << "Miss";
    }

}

/****************************DisplaySunk()*****************************
 Private Method Name: DisplaySunk()
 Desc: This method is a helper of DisplayFeedback(). It displays the
 ship sunk in the following format.

 You sank my [ship]
 e.g., You sank my Battleship, You sank my Cruiser, etc.
**********************************************************************/
void io::DisplaySunk(BoardUtility::Ship ship){
    std::cout << "You sank my ";
    switch (ship) {
        case BoardUtility::Ship::carrier:
            std::cout << "Carrier";
            break;
        case BoardUtility::Ship::battleship:
            std::cout << "Battleship";
            break;
        case BoardUtility::Ship::cruiser:
            std::cout << "Cruiser";
            break;
        case BoardUtility::Ship::submarine:
            std::cout << "Submarine";
            break;
        case BoardUtility::Ship::destroyer:
            std::cout << "Destroyer";
            break;
    }}

/****************************DisplayWin()*****************************
 Public Method Name: DisplayWin()
 Desc: This method displays a win screen with the many turns that it
 took to finish the game in the following format:

 You won in [many turns] turns.

 e.g., You won in 21 turns.
**********************************************************************/
void io::DisplayWin(int turns) {
    std::cout << "You won in " << turns << " turns" << std::endl;
}

/****************************DisplayQuit()*****************************
 Public Method Name: DisplayQuit()
 Desc: This method displays a quit screen when it is called.

 e.g., You lost.
**********************************************************************/
void io::DisplayQuit() {
    std::cout << "You lost" << std::endl;
}