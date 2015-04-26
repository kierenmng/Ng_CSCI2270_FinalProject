#include <iostream>
#include "Board.h"

using namespace std;

void printMenu()
{
    cout<<"Welcome to Connect 4. Your goal is to get 4 pieces in a row before \nyour opponent does."<<endl;
}

void printOptions(int playerNumber)
{
    if(playerNumber==1)
    {
        cout<<"Player 1"<<endl;
        cout<<"Your options are-"<<endl;
        cout<<"1. Place a piece at a column of your choice (Columns 1-7)"<<endl;
        cout<<"2. Place a piece at a random column"<<endl;
        cout<<"42. Remove a piece from a row of your choice (Don't use this unless you want to ruin a friendship)"<<endl;

    }
    else if(playerNumber==2)
    {
        cout<<"Player 2"<<endl;
        cout<<"Your options are-"<<endl;
        cout<<"1. Place a piece at a column of your choice"<<endl;
        cout<<"2. Place a piece at a random column"<<endl;
        cout<<"42. Remove a piece from a row of your choice (Don't use this unless you want to ruin a friendship)"<<endl;
    }
}

int main()
{
    int counter = 0;
    Board b;
    int choice;
    bool inGame = true;
    printMenu();
    b.setUpBoard();
    b.printBoard();
    while(inGame == true)
    {
        if(counter%2 == 1 || counter==0)
        {
            printOptions(1);
            counter++;
        }
        else if(counter%2 == 0 || counter==1)
        {
            printOptions(2);
            counter++;
        }
        cin>>choice;
        cin.ignore();
        if(choice==1)
        {
            cout<<"What column (1-7) would you like to choose?"<<endl;
            cin>>choice;
            if(counter%2==1 || counter == 0)
            {
                b.setPieceInColumn(0,choice);
            }
            else if(counter%2==0 || counter==1)
            {
                b.setPieceInColumn(1,choice);
            }
        }
        else if(choice==2)
        {
            cout<<"Chose random column."<<endl;
            if(counter%2==1 || counter == 0)
            {
                b.setRandomPiece(0);
            }
            else if(counter%2==0 || counter==1)
            {
                b.setRandomPiece(1);
            }
        }
        else if (choice==42)
        {
            cout<<"Friendship ruiner. What column (1-7) would you like to take the \ntop piece out of?"<<endl;
            cin>>choice;
            b.takeTopPieceFromColumn(choice);
        }
        b.printBoard();
        if(b.checkHorizontal() || b.checkVertical() || b.checkDiagonalGoingDown() || b.checkDiagonalGoingUp())
        {
            if(counter%2==1 || counter == 0)
            {
                cout<<"Player 1 wins!"<<endl;
                inGame = false;
            }
            else if(counter%2==0 || counter==1)
            {
                cout<<"Player 2 wins!"<<endl;
                inGame = false;
            }
        }
    }
    return 0;
}
