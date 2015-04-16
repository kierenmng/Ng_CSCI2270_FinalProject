//Kieren Ng, Brett Israelsen, Recitation Thursday 930
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <json/json.h>
#include "MovieTree.h"

using namespace std;

//function to print the menu
void printMenu()
{
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Rent a movie"<<endl;
    cout<<"2. Print the inventory"<<endl;
    cout<<"3. Delete a movie"<<endl;
    cout<<"4. Count the movies"<<endl;
    cout<<"5. Quit"<<endl;
}

void readFileIntoTree(MovieTree * mt);

//main function, loop for the menu for the user
int main()
{
    MovieTree *MT = new MovieTree();
    readFileIntoTree(MT);
    int input;
    string choice;
    bool inmenu = true;
    while (inmenu == true)
    {
        printMenu();
        cin>>input;
        cin.ignore();
        /*
        if (input == 1)
        {
            cout<<"Enter title:"<<endl;
            getline(cin, choice);
            MT.findMovie(choice);
        }*/
        if (input ==1)
        {
            cout<<"Enter title:"<<endl;
            getline(cin, choice);
            MT->rentMovie(choice);
        }
        else if (input == 2)
        {
            MT->printMovieInventory();
        }
        else if (input == 3)
        {
            cout<<"Enter title to delete"<<endl;
            getline(cin, choice);
            MT->deleteMovieNode(choice);
        }
        else if (input ==4)
        {
            cout<<MT->countMovieNodes()<<endl;
        }
        else if (input == 5)
        {
            cout<<"Goodbye!"<<endl;
            inmenu = false;
        }
    }
    //write json to file
    ofstream myfile;
    myfile.open("Assignment6Output.txt");
    myfile << json_object_to_json_string_ext(MT->getJsonObject(),JSON_C_TO_STRING_PRETTY);
    myfile.close();

    delete MT;
    return 0;
}

void readFileIntoTree(MovieTree* mt)
{
    ifstream in_stream;
    in_stream.open("Assignment5Movies.txt");
    if(!in_stream)
    {
        cout<<"Could not open file"<<endl;
        return;
    }
    string ranking;
    string title;
    string releaseYear;
    string quantity;

    while(!in_stream.eof())
    {
        title = "";
        getline(in_stream,ranking,',');
        getline(in_stream,title,',');
        getline(in_stream,releaseYear,',');
        getline(in_stream,quantity);
        if(title!="")
        {
            //cout<<"adding: " <<title<<endl;
            mt->addMovieNode(atoi(ranking.c_str()),title,atoi(releaseYear.c_str()),atoi(quantity.c_str()));
        }
    }
}
