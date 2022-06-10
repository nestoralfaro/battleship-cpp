# Battleship C++
This C++ program is a 1-player Battleship game. It is played on a 10x10 grid representing the ocean and containing ships. Each cell in the grid is identified by a letter representing a column and a number representing a row. Ships are comprised of a sequence of contiguous cells, either all in the same row or all in the same column. There are five ships having different lengths.

- Carrier, length 5
- Battleship, length 4
- Cruiser, length 3
- Submarine, length 3
- Destroyer, length 2

The ships are placed in random locations. Two ships cannot contain the same cell.

>The picture below gives one possible setup of the game board (taken directly from Dr. Foust's [project description](https://cs.harding.edu/gfoust/classes/comp3450/project05.html)).

<img width="500" alt="Screen Shot 2022-06-09 at 11 17 11 PM" src="https://user-images.githubusercontent.com/83131937/172995332-9364079e-0528-49c6-8c71-434f82db2cd2.png">

When the game begins, the player does not know where the ships are on the board. The player may “shoot” in different cells in an attempt to hit one of the ships. Cells of the gameboard are identified by their column letter and row number—e.g., “B9” or “H4”. After each shot, the game responds by reporting which ship was hit by the shot, or that no ship was hit by the shot. If a ship has been hit in all of its cells, it sinks. You must sink all the ships to win the game.

## Demo
![bcpp-demo](https://user-images.githubusercontent.com/83131937/173004782-22e1ae0c-9055-4361-b9d4-86e7786ddc23.gif)

## The Program
This is a console application with no UI (no prompts, etc.). The application will be defined simply in terms of the input and output.

### Input
The input to the program begins with five groups of three letters. These five groups represent the positions of the five ships in this order: carrier, battleship, cruiser, submarine, and destroyer. The first character will be a column letter; the second character will be a row number; and the third character will be either the letter H or the letter V representing either Horizontal or Vertically, respectively. The first two characters define the upper-left corner of the ship, and the third character defines whether the ship proceeds to the right (for H) or down (for V). The input that defines the board in the picture above would be the following.

```
F7H B1V D6V F3H I3V
```

Following these five groups of three characters, there will come zero or more groups of two characters representing shots. Each two characters will be either the column letter and row number of a cell, or else “Q0” indicating that the user quits.

### Output
Each gameboard representation should match the following pattern, where each letter `C` is replaced with either `X`, `O`, or a period (`.`). The letter `X` means the player has shot there and it was a hit. The letter `Y` means the player has shot there and it was a miss. The period means the player has not yet shot there.

| |A|B|C|D|E|F|G|H|I|J|
|-|-|-|-|-|-|-|-|-|-|-|
|0|C|C|C|C|C|C|C|C|C|C|
|1|C|C|C|C|C|C|C|C|C|C|
|2|C|C|C|C|C|C|C|C|C|C|
|3|C|C|C|C|C|C|C|C|C|C|
|4|C|C|C|C|C|C|C|C|C|C|
|5|C|C|C|C|C|C|C|C|C|C|
|6|C|C|C|C|C|C|C|C|C|C|
|7|C|C|C|C|C|C|C|C|C|C|
|8|C|C|C|C|C|C|C|C|C|C|
|9|C|C|C|C|C|C|C|C|C|C|

A shot description always begins with the column letter and row number of the shot, followed by a colon, followed by a description of the result. If the shot was a miss, it outputs the word "Miss". For example, if a shot at column J row 5 was a miss, the output would look like the following.

>J5: Miss

If the shot was a hit, it outputs the word "Hit" followed by the name of the ship that was hit. For example, if a shot at column J row 5 hit the Carrier, the output would look like the following.

>J5: Hit Carrier

If the ship that was hit has been sunk it outputs "You sank my" and the name of the ship. For example, if a shot at column J row 5 hit the Carrier, and the Carrier was sunk, the output would look like the following.

>J5: Hit Carrier  
You sank my Carrier

### Game Over
The game ends when all ships are sunk. The program prints the message "You won in N turns", where N is the number of shots it took to sink all ships.

Additionally, the player may enter a shot of "Q0" to indicate a forfeit. In this case the game ends immediately and the player loses. The program prints the message "You lost".
