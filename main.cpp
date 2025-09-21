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

void inputPlayer(Player *p){
    cout<< "Name: ";
    getline(cin, p->name);

    cout<< "Position: ";
    getline(cin, p->position);

    cout<< "Jersey # ";
    cin>>p->jerseyNumber;

    cout<< "Game played; ";
    cin>>p->games;

    if (p->games > 0){
        p->minutes = new int [p->games];
    }else{
        p->minutes = nullptr;
    }

    for (int k=0; k < p->games; k++){
        cout << "Minutes in game " << k+1 <<":";
        cin >> p->minutes[k];
    }
    cin.ignore();

}

void displayPlayer(Player *p){
    cout << p->name << " #" << p->jerseyNumber << " Position: "<< p->position<< endl;
    cout << "Games: " << p->games << "\n Minutes in game: ";
    for (int k =0; k < p->games; k++){
        cout << p->minutes[k] << 
    }
}