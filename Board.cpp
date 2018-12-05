/**************************************************************************************************************
** Author: Derrick Li
** Date: Nov. 23, 2016
**
** Description:
** This class implementation file contains the member function definitions for the Board class.
***************************************************************************************************************/

#include "Board.hpp"	//contains the Board class declaration
#include <iostream>

using std::cout;
using std::endl;

/***************************************************************************************************************
** Description: Board() is the default constructor. It initializes each element of the 3x3 gameBoard array
** with the char '.' to indicate the space is available for a move.
***************************************************************************************************************/
Board::Board()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			gameBoard[row][col] = '.';
}

/***************************************************************************************************************
** Description: makeMove(char, int, int) takes in a player's turn ('X' or 'O') and their coordinates inputed
** (row and column) and attempts to make the move on the gameBoard array. If the move is unavailable (i.e. the space
** is already occupied) then no move is made and false is returned by the function. If the move can be made (i.e.
** the space is free as indicated with a '.' char), then the move is executed and the space will be occupied by the player's
** character (either an 'x' or 'o') and true will be returned by the function.
***************************************************************************************************************/
bool Board::makeMove(char player, int row, int col)
{
	bool moveRecorded = false;

	if (gameBoard[row][col] == '.')
	{
		if (player == 'X')
		{
			gameBoard[row][col] = 'x';
			moveRecorded = true;
		}
		else if (player == 'O')
		{
			gameBoard[row][col] = 'o';
			moveRecorded = true;
		}
	}

	return moveRecorded;
}

/***************************************************************************************************************
** Description: gameState() evaluates the state of the game and returns one of four enumerated types: X_WON, O_WON,
** DRAW, or UNFINISHED. The function evaluates 8 different possible win combinations for each player, 'X' and 'O',
** and returns either X_WON or O_WON in such occurrence. If all free space is depleted and there are no winners,
** then DRAW is returned. Else, the game is still in progress and gameState returns UNFINISHED.
***************************************************************************************************************/
State Board::gameState()
{
	State gameStatus = UNFINISHED;

	//Evaluates a total of 8 possible ways 'X' can win

	//Evaluates 4 of 8 possible ways 'X' can win, involving gameBoard[1][1] (the array center)
	if (gameBoard[1][1] == 'x')
	{
		if (gameBoard[0][0] == 'x' && gameBoard[2][2] == 'x')
			gameStatus = X_WON;
		else if (gameBoard[1][0] == 'x' && gameBoard[1][2] == 'x')
			gameStatus = X_WON;
		else if (gameBoard[2][0] == 'x' && gameBoard[0][2] == 'x')
			gameStatus = X_WON;
		else if (gameBoard[0][1] == 'x' && gameBoard[2][1] == 'x')
			gameStatus = X_WON;
	}

	//Evaluates 2 of 8 possible ways 'X' can win, involving gameBoard[0][2] (the upper-right element)
	if (gameBoard[0][2] == 'x')
	{
		if (gameBoard[0][0] == 'x' && gameBoard[0][1] == 'x')
			gameStatus = X_WON;
		else if (gameBoard[1][2] == 'x' && gameBoard[2][2] == 'x')
			gameStatus = X_WON;
	}

	//Evaluates 2 of 8 possible ways 'X' can win, involving gameBoard[2][0] (the bottom-left element)
	if (gameBoard[2][0] == 'x')
	{
		if (gameBoard[0][0] == 'x' && gameBoard[1][0] == 'x')
			gameStatus = X_WON;
		else if (gameBoard[2][1] == 'x' && gameBoard[2][2] == 'x')
			gameStatus = X_WON;
	}

	//Evaluates a total of 8 possible ways 'O' can win
	if (gameStatus == UNFINISHED)
	{
		//Evaluates 4 of 8 possible ways 'O' can win, involving gameBoard[1][1] (the array center)
		if (gameBoard[1][1] == 'o')
		{
			if (gameBoard[0][0] == 'o' && gameBoard[2][2] == 'o')
				gameStatus = O_WON;
			else if (gameBoard[1][0] == 'o' && gameBoard[1][2] == 'o')
				gameStatus = O_WON;
			else if (gameBoard[2][0] == 'o' && gameBoard[0][2] == 'o')
				gameStatus = O_WON;
			else if (gameBoard[0][1] == 'o' && gameBoard[2][1] == 'o')
				gameStatus = O_WON;
		}

		//Evaluates 2 of 8 possible ways 'O' can win, involving gameBoard[0][2] (the upper-right element)
		if (gameBoard[0][2] == 'o')
		{
			if (gameBoard[0][0] == 'o' && gameBoard[0][1] == 'o')
				gameStatus = O_WON;
			else if (gameBoard[1][2] == 'o' && gameBoard[2][2] == 'o')
				gameStatus = O_WON;
		}

		//Evaluates 2 of 8 possible ways 'O' can win, involving gameBoard[2][0] (the bottom-left element)
		if (gameBoard[2][0] == 'o')
		{
			if (gameBoard[0][0] == 'o' && gameBoard[1][0] == 'o')
				gameStatus = O_WON;
			else if (gameBoard[2][1] == 'o' && gameBoard[2][2] == 'o')
				gameStatus = O_WON;
		}
	}

	//Evaluates the game for a draw. A draw has occurred if there is no declared winner and no additional possible move that can be made.
	if (gameStatus == UNFINISHED)
	{
		bool movesRemaining = false;	//movesRemaining is initialized to false until a possible move is proven

		//Iterates through each element of the gameBoard array and checks for the presence of '.' to indicate a free space.
		//If it exists, then movesRemaining is changed to true.
		int row = 0;
		while (!movesRemaining && row < 3)
		{
			int col = 0;
			while (!movesRemaining && col < 3)
			{
				if (gameBoard[row][col] == '.')
					movesRemaining = true;
				col++;
			}
			row++;
		}

		if (!movesRemaining)	//If there are no free spaces then no possible moves can be made, and gameStatus is changed to DRAW.
			gameStatus = DRAW;
	}

	return gameStatus;
}

/***************************************************************************************************************
** Description: Print() displays the contents of the gameBoard array.
***************************************************************************************************************/
void Board::print()
{
	cout << "  " << 0 << " " << 1 << " " << 2 << endl;
	for (int row = 0; row < 3; row++)
	{
		cout << row << " ";
		for (int col = 0; col < 3; col++)
		{
			cout << gameBoard[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
}