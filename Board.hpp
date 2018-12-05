/**************************************************************************************************************
** Author: Derrick Li
** Date: Nov. 23, 2016
**
** Description:
** This class specification file contains the Board class declaration. Its only private data member is a 3-by-3
** array of char type used to represent a tic-tac-toe game board. The public member functions consists of a default
** constructor used to initialize the gameBoard array, a function - makeMove - that is used to make a move on the
** gameBoard array based on the player's input, a function - gameState - that reports the current state of the game,
** and a function - print - that displays the contents of the gameBoard.
***************************************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

//State is an enumerated data type that defines the current state of the game.
enum State {X_WON, O_WON, DRAW, UNFINISHED}; 

class Board
{
private:
	char gameBoard[3][3];

public:
	Board();	//Default constructor.
	bool makeMove(char player, int x, int y);
	State gameState();
	void print();
};

#endif