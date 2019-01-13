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

void dropPiece()
{

}

bool checkForWin()
{
    return true;
}

void gameEnd()
{
    cout << "The game is over. Would you like to play again?";
}

void gamePlay()
{
    int rows = 6;
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

    gameEnd();

}

int main()
{
    gamePlay();
    return 0;
}