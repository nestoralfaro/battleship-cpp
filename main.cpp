///////////////////////////////// main.cpp ///////////////////////////////////
/*******************************************************************************
Nestor Alfaro | 02/01/21

Desc: The following is an example of how combining the io module (input/output),
game module (logic and rules), and board module (pieces) can make a game of
battleship.
*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
#include "board.hpp"
#include "io.hpp"
#include "game.hpp"

int main () {
    game game;
    io io;
    board board;
    bool quit;
    bool playing;
    bool gameOver;
    int shotCounter = 0;

    //get board utilities
    BoardUtility::Result result;
    BoardUtility::Ships shipcrafts;
    BoardUtility::Boardtype battleBoard;
    BoardUtility::Fire shot;
    battleBoard = board.GetBoard();
    shipcrafts = board.GetShips();
    shot = board.GetFire();

    std::string shotEntered;
    std::vector<std::string> shipsEntered;

    //Enter ships
    shipsEntered  = io.EnterShips();

    //For each ship
    for (int ship = 1; ship < shipsEntered.size(); ship++){
        //Set ship
        game.SetShip(shipsEntered[ship], shipcrafts[ship]);
        //Place ship on board
        board.PlaceShip(battleBoard, shipcrafts[ship]);
    }
    
    do {
        //Display Board
        io.DisplayBoard(battleBoard);

        //Enter shot
        shotEntered = io.EnterShot();
        game.SetShot(shotEntered, shot);

        quit = game.Quit(shot);
        gameOver = game.IsOver(shipcrafts);
        playing = (!quit && !gameOver);


        if (playing){
            game.IncrementTurn(shotCounter);
            result = game.ReturnResult(shot, battleBoard, shipcrafts);
            //Fire entered | Fire Ship | Result
            io.DisplayFeedback(shotEntered, battleBoard[(int)shot.row][(int)shot.col].ship, result);

            //This double check is necessary when hitting a perfect score.
            if (game.IsOver(shipcrafts)) {
                io.DisplayBoard(battleBoard);
                io.DisplayWin(shotCounter);
                playing = false;
            }
        }
        else if (gameOver){
            io.DisplayWin(shotCounter);
        } else if (quit) {
            io.DisplayQuit();
        } else;


    }while (playing);

    return 0;
}

