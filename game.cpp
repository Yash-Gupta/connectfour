//Pawan Sarma, yash Gupta, Saurabh Narain, Austin Chen
//January 8th, 2019
//Connect 4 Final Program
//Creates game where two players are able to play the game Connect 4

#include <iostream>
#include <math.h>  
#include <cmath>
using namespace std;

const int columns = 7; //Make global constant for columns to pass through array

void printGameboard(char gameBoard[][columns], int rows)
{
	for (int i = 1; i <= columns; i++) //Prints numbers at the top of the board
	{
		cout << " " << i;
	}
	cout << endl;
	for (int i = 0; i < columns; i++) //Prints first row of +-
	{
		cout << "+-";
	}
	cout << "+";
	cout << endl;
	for (int j = 0; j < rows; j++) //Prints row of | | |...
	{
		for (int i = 0; i < columns; i++)
		{
			cout << "| ";
		}
		cout << "|";
		cout << endl;
		for (int i = 0; i < columns; i++) //Prints row of +-
		{
			cout << "+-";
		}
		cout << "+";
		cout << endl;
	}

}

int main()
{
	const int rows = 6;
	char gameBoard[rows][columns]; //Making the gameboard
	printGameboard(gameBoard, rows);
	return 0;
}