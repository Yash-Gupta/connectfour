//Pawan Sarma, yash Gupta, Saurabh Narain, Austin Chen
//January 8th, 2019
//Connect 4 Final Program
//Creates game where two players are able to play the game Connect 4

#include <iostream>
using namespace std;

const int columns = 7;

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
            cout << "|" << gameBoard[j][i];
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

void gameStart(char gameBoard[][columns], int rows, bool isWin, bool isX)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            gameBoard[i][j] = ' ';
        }
    }
    
    printGameboard(gameBoard, rows);
    
    isX = true;
    isWin = false;
}

void dropPiece (char gameBoard[][columns], int rows, bool isX) //Drops icon into gameboard
{
	int userInput;
	cout << "Pick number from 0-6 to drop icon: " << endl;
	cin >> userInput;
	
	while (userInput < 0 || userInput > 6)
	{
		cout << "Invalid number. Pick from 0-6: " << endl;
		cin >> userInput;
	}

	char gameLetter = isX ? 'X' : 'O'; //Shortcut to true/false ternary
	for (int i = (rows - 1); i >= 0; i--)
	{
		if (gameboard[i][userInput] == ' ')
		{
			if (isX == true)
			gameboard[i][userInput] == 'X'
		} 
		if (gameboard[i][userInput] != ' ')
		{
			gameboard[i][userInput] == 
		}
	}
}

bool checkForWin()
{
    return true;
}

void gamePlay()
{
    const int rows = 6;
    char gameBoard[rows][columns];
    bool isWin;
    bool isX;

    gameStart(gameBoard, rows, isWin, isX);

    while(!isWin)
    {
        dropPiece();
        isWin = checkForWin();
        isX = !isX;
    }

}

int gameEnd()
{
    cout << "The game is over. Would you like to play again? (Y/N)" << endl;
    
    char input;
    cin >> input;
    
    if (input == 'Y')
    {
        gamePlay();
    }

    if (input == 'N')
    {
        return 0;
    }
}

int main()
{
    gamePlay();
    gameEnd();
    return 0;
}