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

void Board::setUpBoard()
{
    for(int i = 0;i<7;i++)
    {
        for(int k = 0;k<7;k++)
        {
            connectBoard[i][k]=0;
        }
    }
}

void Board::setPieceInColumn(int player, int column)
{
    int i;
    if(player==0)
    {
        for(i = 7; i>=0;i--)
        {
            if(connectBoard[i][column-1]==0)
            {
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

void Board::setRandomPiece(int player)
{
    srand(time(NULL));
    int randNum = rand() % 7+1;
    if(player==0)
    {
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

void Board::takeTopPieceFromColumn(int column)
{
    for(int i = 0; i<7;i++)
    {
        if(connectBoard[i][column-1] !=0)
        {
            connectBoard[i][column-1] = 0;
            break;
        }
    }
}

bool Board::checkHorizontal()
{
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

bool Board::checkVertical()
{
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

bool Board::checkDiagonalGoingUp()
{
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

bool Board::checkDiagonalGoingDown()
{
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

void Board::printBoard()
{
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
