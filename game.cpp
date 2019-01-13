//Pawan Sarma, yash Gupta, Saurabh Narain, Austin Chen
//January 8th, 2019
//Connect 4 Final Program
//Creates game where two players are able to play the game Connect 4

#include <iostream>
using namespace std;

const int columns = 7;

int printGameboard(char gameBoard[][columns], int rows)
{
    for (int i = 0; i < columns; i++) //Prints numbers at the top of the board
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
    return 0;
    
}

int gameStart(char gameBoard[][columns], int rows, bool isWin, bool isX)
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

    return 0;
}

int dropPiece (char gameBoard[][columns], int rows, bool isX) //Drops icon into gameboard
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
    int row = 6;
	while (gameBoard[row][userInput] != ' ' && row > -1)
    {
        row--;
    }
    if (row == - 1)
    {
        cout << "Invalid move, try different column: ";
        dropPiece(gameBoard, rows, isX);
    }

    gameBoard[row][userInput] = gameLetter;
    printGameboard(gameBoard, rows);

    return 0;
}

bool checkForWin(char gameBoard[][columns])
{
    // checking vertical
    for (int column = 6; column >= 0; column--)
    {
        for (int row = 5; row >= 3; row--)
        {
            if(gameBoard[row][column] == 'O')
            {
                if(gameBoard[row][column] != ' ' && gameBoard[row][column] == gameBoard[row-1][column] && gameBoard[row][column] == gameBoard[row-2][column] && gameBoard[row][column] == gameBoard[row-3][column]) 
                {
                    return true;
                }

            }

        }
    }
    for (int column = 6; column >= 3; column--)
    {
    	for (int row = 2; row >=0; row--)
    	{
    		if(gameBoard[row][column] != ' ' && gameBoard[row][column] == gameBoard[row+1][column-1] && gameBoard[row][column] == gameBoard[row+2][column-2] && gameBoard[row][column] == gameBoard[row+3][column-3] )
    		{
    			return true;
    		}
    	}

    }
    for (int column = 0; column <= 3; column ++)
    {
    	for (int row = 2; row >=0; row--)
    	{ 
    		if(gameBoard[row][column] != ' ' && gameBoard[row][column] == gameBoard[row+1][column+1] && gameBoard[row][column] == gameBoard[row+2][column+2] && gameBoard[row][column] == gameBoard[row+3][column+3])
   			{
   				return true;	
   			}
   		}

    }

}


int gamePlay()
{
    const int rows = 6;
    char gameBoard[rows][columns];
    bool isWin;
    bool isX;

    gameStart(gameBoard, rows, isWin, isX);

    while(!isWin)
    {
        dropPiece(gameBoard, rows, isX);
        isWin = checkForWin(gameBoard);
        isX = !isX;
    }

    return 0;

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