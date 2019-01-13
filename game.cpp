// CONNECT 4 made with love by Yash, Saurabh, Pawan, Austin, and Roshan

#include <iostream>
using namespace std;

const int columns = 7;

int printGameboard(char gameBoard[][columns], int rows)
{
    // Prints numbers at the top of the board
    for (int i = 0; i < columns; i++) 
    {   
        cout << " " << i;
    }
    cout << endl;

    // Prints first row of +-
    for (int i = 0; i < columns; i++) 
    {
        cout << "+-";
    }
    cout << "+";
    cout << endl;

    // Prints row of | | |...
    for (int j = 0; j < rows; j++) 
    {
        for (int i = 0; i < columns; i++)
        {
            cout << "|" << gameBoard[j][i];
        }
        cout << "|";
        cout << endl;

        // Prints row of +-
        for (int i = 0; i < columns; i++) 
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
    // initialize game board with spaces
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            gameBoard[i][j] = ' ';
        }
    }
    
    printGameboard(gameBoard, rows);

    return 0;
}

int dropPiece (char gameBoard[][columns], int rows, bool isX) // Drops icon into gameboard
{
    // user input for column
	int userInput;
	cout << "Pick number from 0-6 to drop icon: " << endl;
	cin >> userInput;
	
	while (userInput < 0 || userInput > 6)
	{
		cout << "Invalid number. Pick from 0-6: " << endl;
		cin >> userInput;
	}

	char gameLetter = isX ? 'X' : 'O';

    // add X or O to available slot in column
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
            if(gameBoard[row][column] != ' ' && gameBoard[row][column] == gameBoard[row-1][column] && gameBoard[row][column] == gameBoard[row-2][column] && gameBoard[row][column] == gameBoard[row-3][column]) 
            {
                return true;
            }
        }
    }


    // checking left down diagonal
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

    // checking right down diagonal
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

    // checking horizontal
    for (int row = 5; row >= 0; row--)
    {
        for (int column = 0; column <= 3; column++)
        {
            if(gameBoard[row][column] != ' ' && gameBoard[row][column] == gameBoard[row][column+1] && gameBoard[row][column] == gameBoard[row][column+2] && gameBoard[row][column] == gameBoard[row][column+3]) 
            {
                return true;
            }
        }
    }

    return false;
}


int gamePlay()
{
    // initialize game
    const int rows = 6;
    char gameBoard[rows][columns];
    bool isWin = false;
    bool isX = true;

    gameStart(gameBoard, rows, isWin, isX);

    // drop coins, change turns until win
    while(!isWin)
    {
        dropPiece(gameBoard, rows, isX);
        isX = !isX;
        isWin = checkForWin(gameBoard);   
    }

    char winner = !isX ? 'X' : 'O';

    cout << "The game is over! Player " << winner << " is the winner! Write 'yes' to start again. Write anything else to exit." << endl;
    string userInput;
    cin >> userInput;
    
    if(userInput == "yes")
    {
        gamePlay();
    }

    return 0;
}

int main()
{
    gamePlay();
    return 0;
}