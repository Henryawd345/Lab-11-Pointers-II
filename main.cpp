#include <iostream>
#include <string>
using namespace std;

//Stats of each player
struct Player{
    string name;
    string position;
    int jerseyNumber;

    int* minutes = nullptr; //inner dynamic array: this will be the minutes played per game
    int games = 0; // how many games(thisis the size of minutes[])

    ~Player(){
        delete[] minutes;
    }

};

//The roster of the team
struct Team{
    Player *roster = nullptr; //Outer dynamic array: player in the team
    int count = 0; //number of player

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

//Allocate the roster if there is at least 1 player
if (teamNum.count > 0){
    teamNum.roster = new Player[teamNum.count];
}else{
    teamNum.roster = nullptr;
}

//Fill each player information
for (int i = 0; i < teamNum.count; i++){
    cout << "Player #" << i+1 << endl;
    inputPlayer(&teamNum.roster[i]);
}
//Show the summary of a player
for (int i = 0; i < teamNum.count; i++){
    cout << "Player #" << i+1 << endl;
    displayPlayer(&teamNum.roster[i]);
    cout<< endl;
}

return 0;

}

void inputPlayer(Player *p){
    cout<< "Name: ";
    getline(cin, p->name);

    cout<< "Position: ";
    getline(cin, p->position);

    cout<< "Jersey # ";
    cin>>p->jerseyNumber;

    cout<< "Game played; ";
    cin>>p->games;// This decide the Inner array size for this player 

    //Allocate the minutes if they played at least 1 match
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
    cout << "\n";

}

void displayPlayer(Player *p){
    cout << "----------------------------------------\n";
    cout << "Name:      " << p->name << "\n";
    cout << "Position:  " << p->position << "\n";
    cout << "Jersey #:  " << p->jerseyNumber << "\n";
    cout << "Games:     " << p->games << "\n";
    cout << "Games:     " << p->games << "\nMinutes in game: ";
    for (int k =0; k < p->games; k++){
        cout << " " << p->minutes[k];
        if (k+1 != p->games){
            cout << " ";
        }
    }
    cout << "\n";
}