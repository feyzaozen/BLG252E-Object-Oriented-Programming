//////////////////////////////////
/* Name: <Feyza Özen>        */
/* Student ID : <150190014>  */
/* Date: <26.04.2021>        */

//////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

class Player{
protected:
    
    string name;
    int gameScore;
    
public:
    
    Player(string, int); //constructor for Player class
    
    void print() const {
        cout <<"Name: " <<name<< " score: "<<gameScore<<endl;
    }
    
    int operator+(const Player &player_x){return gameScore + player_x.gameScore;}
    
};

class ExpertPlayer: public Player {
    
    string skills;
    
public:
    
    ExpertPlayer(string, int, string); //constructor for ExpertPlayer class
    
    void print() const {
        Player::print(); //It calls the print function of the base class. There is no need to repeat.
        
        cout <<"skill: " <<skills<<endl;
    }

};


int main()
{
  
    ExpertPlayer e1 = ExpertPlayer("ExpertPlayer 1", 10, "time");
    ExpertPlayer e2 = ExpertPlayer("ExpertPlayer 2", 30, "space");
    const Player p1 = Player("player 1", 40);
    e1.print();
    e2.print();
    p1.print();
    int sum = e1 + e2;
    cout << sum << endl;

    return 0;
}


Player::Player(string name_x,int score_x){ //constructor for Player class
    cout <<  "constructor of player" << endl;
    this->name = name_x;
    this->gameScore = score_x;

}

ExpertPlayer::ExpertPlayer(string name_x,int score_x,string skills_x):Player(name_x, score_x){ //constructor for ExpertPlayer class
    cout <<  "constructor of expert player" << endl;
    this->skills = skills_x;

}
