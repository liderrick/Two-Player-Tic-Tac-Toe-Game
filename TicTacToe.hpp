/**************************************************************************************************************
** Author: Derrick Li
** Date: Nov. 23, 2016
**
** Description:
** This class specification file contains the TicTacToe class declaration. Its private data members includes a Board
** class object used to store data of the current game and a char variable, playerTurn, used to indicate which player
** is set to make a move (either 'X' or 'O'). The public member functions consist of a one-parameter constructor
** that takes in a player's turn (either 'X' or 'O') and creates a new game of Tic Tac Toe, and a function - play - that
** plays the game.
***************************************************************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"	//needed to use Board class objects

class TicTacToe
{
private:
	Board game;			//a Board class object used to store current game data
	char playerTurn;

public:
	TicTacToe(char playerInput);	//one-parameter constructor
	void play();		//function that plays the game
};

#endif