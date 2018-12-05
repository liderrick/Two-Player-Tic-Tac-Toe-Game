#include <iostream>
#include <cctype>			//needed for toupper function
#include <string>
#include <limits>
#include "Board.hpp"
#include "TicTacToe.hpp"

using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::toupper;		//used to change user input from lowercase to uppercase character

/***************************************************************************************************************
** Description: This is the main function. It asks the user to input which player will go first and passes the
** input as an argument to the TicTacToe constructor to start and play a game of Tic Tac Toe.
***************************************************************************************************************/
int main()
{
	string input;
	char startPlayer;

	system("clear");
	cout << "Which player goes first (Enter 'x' or 'o')? ";
	cin >> input;
	startPlayer = toupper(input[0]);		//Converts lowercase character to uppercase equivalent if necessary.

	while (startPlayer != 'X' && startPlayer != 'O')	//Validates the user input.
	{
		//cin.ignore(std::numeric_limits<std::streamsize>::max());
		cout << endl << "Invalid choice. Try again. Enter 'x' or 'o': ";
		cin >> input;
		startPlayer = toupper(input[0]);
	}

	TicTacToe ticTacToeGame(startPlayer);	//Initializes a TicTacToe class object with the user's input.

	ticTacToeGame.play();	//Plays a game of Tic Tac Toe using the class object.

	return 0;
}