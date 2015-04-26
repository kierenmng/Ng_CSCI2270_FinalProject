#include "Board.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

Board::Board()
{
    //ctor
}

Board::~Board()
{
    //dtor
}

/*
Function Prototype:
void Board::setUpBoard();

Function Description:
This method fills the 2-D array with zeroes, which represent empty spaces.

Example:
Board b;
b.setUpBoard();

Precondition:
There needs to be a 2-D array of ints called connectBoard in Board.h

Postcondition:
The 2-D array of ints are filled with zeroes.
*/
void Board::setUpBoard()
{
    //Cycles through using nested for loops to populate the entire board.
    for(int i = 0;i<7;i++)
    {
        for(int k = 0;k<7;k++)
        {
            connectBoard[i][k]=0;
        }
    }
}

/*
Function Prototype:
void Board::setPieceInColumn(int,int);

Function Description:
This method sets an integer, dependent on the player number, down on the board. Pieces are subject to gravity,
so pieces automatically fall to the lowest row possible.

Example:
Board b;
b.setPieceInColumn(0,2);

Precondition:
There needs to be a 2-D array of ints called connectBoard in Board.h

Postcondition:
The board gets one piece in the specified column.
*/
void Board::setPieceInColumn(int player, int column)
{
    int i;
    //Checks which player's turn it is.
    if(player==0)
    {
        //Checks to find the first row that isn't populated to go to the bottom.
        for(i = 7; i>=0;i--)
        {
            if(connectBoard[i][column-1]==0)
            {
                //Since this is player 1, the 1 gets placed at the spot desired.
                connectBoard[i][column-1] = 1;
                break;
            }
        }
    }
    else if(player==1)
    {
        for(i = 7; i>=0;i--)
        {
            if(connectBoard[i][column-1]==0)
            {
                connectBoard[i][column-1] = 2;
                break;
            }
        }
    }
}

/*
Function Prototype:
void Board::setRandomPiece(int);

Function Description:
This method sets an integer, based on the player number, in a random column.
Pieces are subject to gravity and fall as far as possible down.

Example:
Board b;
b.setRandomPiece(0);

Precondition:
There needs to be a 2-D array of ints called connectBoard in Board.h

Postcondition:
The board gets one piece to a random column.
*/
void Board::setRandomPiece(int player)
{
    //Makes a random column to go for (simulates an actual response from the user)
    srand(time(NULL));
    int randNum = rand() % 7+1;
    //Checks who's turn it is.
    if(player==0)
    {
        //Finds the lowest row possible
        for(int i = 7; i>=0; i--)
        {
            if(connectBoard[i][randNum-1]==0)
            {
                connectBoard[i][randNum-1] = 1;
                break;
            }
        }
    }
    else if(player==1)
    {
        for(int i = 7; i>=0; i--)
        {
            if(connectBoard[i][randNum-1]==0)
            {
                connectBoard[i][randNum-1] = 2;
                break;
            }
        }
    }
    cout<<"The random column was: "<<randNum<<endl;
}

/*
Function Prototype:
void Board::takeTopPieceFromColumn(int);

Function Description:
This method takes the top-most piece from the specified column.

Example:
Board b;
b.takeTopPieceFromColumn(1);

Precondition:
There needs to be a 2-D array of ints called connectBoard in Board.h

Postcondition:
The board is unchanged except for the one piece that is turned into a zero.
*/
void Board::takeTopPieceFromColumn(int column)
{
    //Looks for the first place in the column that isn't 0.
    for(int i = 0; i<7;i++)
    {
        if(connectBoard[i][column-1] !=0)
        {
            connectBoard[i][column-1] = 0;
            break;
        }
    }
}

/*
Function Prototype:
bool Board::checkHorizontal()

Function Description:
This method checks each row horizontally if there are four (same int) pieces in a row. If there are, returns true; if not, returns false.

Example:
Board b;
b.checkHorizontal();

Precondition:
There needs to be a 2-D array of ints called connectBoard in Board.h

Postcondition:
Nothing on the board is changed.
*/
bool Board::checkHorizontal()
{
    //Checks only to the right of each row.
    for(int i = 0; i<7; i++)
    {
        for(int k = 0; k<=3; k++)
        {
            if(connectBoard[i][k]==1 && connectBoard[i][k+1]==1 && connectBoard[i][k+2]==1 && connectBoard[i][k+3]==1)
            {
                return true;
            }
            else if(connectBoard[i][k]==2 && connectBoard[i][k+1]==2 && connectBoard[i][k+2]==2 && connectBoard[i][k+3]==2)
            {
                return true;
            }
        }
    }
    return false;
}

/*
Function Prototype:
bool Board.checkVertical();

Function Description:
This method checks each column vertically if there are four (same int) pieces in a row. If there are, returns true; if not, returns false.

Example:
Board b;
b.checkVertical;

Precondition:
There needs to be a 2-D array of ints called connectBoard in Board.h

Postcondition:
Nothing on the board is changed
*/
bool Board::checkVertical()
{
    //Checks downward from each column.
    for(int i = 0; i < 7; i++)
    {
        for(int k = 0; k<=3; k++)
        {
            if(connectBoard[k][i]==1 && connectBoard[k+1][i]==1 && connectBoard[k+2][i]==1 && connectBoard[k+3][i]==1)
            {
                return true;
            }
            else if(connectBoard[k][i]==2 && connectBoard[k+1][i]==2 && connectBoard[k+2][i]==2 && connectBoard[k+3][i]==2)
            {
                return true;
            }
        }
    }
    return false;
}

/*
Function Prototype:
bool Board.checkDiagonalGoingUp();

Function Description:
This method checks diagonals (from bottom left to top right). If there are, returns true; if not, returns false.

Example:
Board b;
b.checkDiagonalGoingUp();

Precondition:
There needs to be a 2-D array of ints called connectBoard in Board.h

Postcondition:
Nothing on the board is changed
*/
bool Board::checkDiagonalGoingUp()
{
    //Checks diagonally from the bottom left to the top right.
    for(int i = 6; i>=3; i--)
    {
        for(int k = 0; k<=3; k++)
        {
            if(connectBoard[i][k]==1 && connectBoard[i-1][k+1]==1 && connectBoard[i-2][k+2]==1 && connectBoard[i-3][k+3]==1)
            {
                return true;
            }
            else if(connectBoard[i][k]==2 && connectBoard[i-1][k+1]==2 && connectBoard[i-2][k+2]==2 && connectBoard[i-3][k+3]==2)
            {
                return true;
            }
        }
    }
    return false;
}

/*
Function Prototype:
bool Board.checkDiagonalGoingDown();

Function Description:
This method checks diagonals (from top left to bottom right). If there are, returns true; if not, returns false.

Example:
Board b;
b.checkDiagonalGoingDown();

Precondition:
There needs to be a 2-D array of ints called connectBoard in Board.h

Postcondition:
Nothing on the board is changed
*/
bool Board::checkDiagonalGoingDown()
{
    //Checks from the top left to the bottom right.
    for(int i = 0; i<=3; i++)
    {
        for(int k = 0; k<=3; k++)
        {
            if(connectBoard[i][k]==1 && connectBoard[i+1][k+1]==1 && connectBoard[i+2][k+2]==1 && connectBoard[i+3][k+3]==1)
            {
                return true;
            }
            else if(connectBoard[i][k]==2 && connectBoard[i+1][k+1]==2 && connectBoard[i+2][k+2]==2 && connectBoard[i+3][k+3]==2)
            {
                return true;
            }
        }
    }
    return false;
}

/*
Function Prototype:
void Board::printBoard();

Function Description:
This method prints the board.

Example:
Board b;
b.printBoard();

Precondition:
There needs to be a 2-D array of ints called connectBoard in Board.h

Postcondition:
Board is unchanged.
*/
void Board::printBoard()
{
    //Cycles through entire array and prints the board.
    for(int i = 0;i<7;i++)
    {
        cout<<"[";
        for(int k = 0; k<7; k++)
        {
            cout<<connectBoard[i][k];
            if(k<6)
            {
                cout<<" ";
            }
        }
        cout<<"]"<<endl;
    }
}
