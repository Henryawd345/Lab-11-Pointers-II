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

void inputPlayer(Player *p);
void displayPlayer(Player *p);

int main(){
Team teamNum;

cout<< "How many players? ";
cin>>teamNum.count;
cin.ignore();

if (teamNum.count > 0){
    teamNum.roster = new Player[teamNum.count];
    
}else{
    teamNum.roster = nullptr;
}


}

