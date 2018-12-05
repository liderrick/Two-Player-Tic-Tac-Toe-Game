/**************************************************************************************************************
** Author: Derrick Li
** Date: Nov. 23, 2016
**
** Description:
** This class implementation file contains the member function definitions for the TicTacToe class.
***************************************************************************************************************/

#include <iostream>
#include "TicTacToe.hpp"	//contains the TicTacToe class declaration

using std::cout;
using std::cin;
using std::endl;

/***************************************************************************************************************
** Description: TicTacToe(char) is the default constructor. It initializes the playerTurn member data to indicate
** which player will go first in turn. A Board class object is also created as part of the TicTacToe instance.
***************************************************************************************************************/
TicTacToe::TicTacToe(char playerInput)
{
	playerTurn = playerInput;
}

/***************************************************************************************************************
** Description: play() is used to play the game of Tic Tac Toe.
***************************************************************************************************************/
void TicTacToe::play()
{
	int row, col;	//used to store players' move input
	
	//This while loop will execute as long as there is space available to make a move and no declared winner.
	while (game.gameState() == UNFINISHED)
	{
		//Displays the game board.
		system("clear");
		game.print();

		//Gets the player's move.
		cout << "Player " << playerTurn << " - Please enter your move as \"<row> <col>\": ";
		cin >> row >> col;

		//Validates the move.
		while (row < 0 || row > 2 || col < 0 || col > 2)
		{
			cout << endl << "Invalid move. Try again. Please enter your move as \"<row> <col>\": ";
			cin >> row >> col;
		}

		//Send the move to makeMove function.
		//If makeMove returns false, it means that the space is unavailable and the program will ask for another move.
		while (!game.makeMove(playerTurn, row, col))
		{
			cout << endl << "Move is unavailable. Try again. Please enter your move as \"<row> <col>\": ";
			cin >> row >> col;

			while (row < 0 || row > 2 || col < 0 || col > 2)		//Validates the move.
			{
				cout << endl << "Invalid move. Try again. Please enter your move as \"<row> <col>\": ";
				cin >> row >> col;
			}
		}

		//Changes players.
		if (playerTurn == 'X')
			playerTurn = 'O';
		else
			playerTurn = 'X';
	}

	//Displays the final gameboard.
	system("clear");
	game.print();

	//Notifies the players of the final state of the game.
	if (game.gameState() == X_WON)
		cout << "Player X has won!" << endl;
	else if (game.gameState() == O_WON)
		cout << "Player O has won!" << endl;
	else if (game.gameState() == DRAW)
		cout << "No Winners! Draw." << endl;

	cout << endl << "Thanks for playing!" << endl;
}

