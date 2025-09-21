#include <iostream>
#include <string>
using namespace std;

//Stats of each player
struct Player{
    string name;
    string position;
    int jerseyNumber;

    int* minutes = nullptr; //inner dynamic array: this will be the minutes played per game
    int games = 0; // how many games

    ~Player(){
        delete[] minutes;
    }

};

struct Team
{
    Player *roster = nullptr; //Outer dynamic array: player in the team
    int count = 0;

    ~Team(){
        delete[] roster;
    }

};



