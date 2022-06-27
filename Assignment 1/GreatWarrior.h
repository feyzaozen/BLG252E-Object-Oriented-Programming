
#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Land{
    
    string name;
    string holding;

    
    public:
   
    Land* next = nullptr;
    Land(); //default constructor
    Land(string,string); //constructor with argument
    Land(Land&); //copy constructor
    
    string getName()const{return name;} // getter function for name
    string getHolding()const{return holding;} // getter function for holding
    void setName(string name_x){name = name_x;}
    void setHolding(string holding_x){holding = holding_x;}
};


class Character{
    string name;
    int manpower;
    int gold;
    int numOfLands;
    Land *lands;
    
    public:
    Character(); //default constructor
    Character(string, int, int, int); //constructor with argument
    Character(Character &); //copy constructor
    
//    ~Character(); //destructor
    
    void getTaxes();
    void addLand(Land);
    void removeLand(string);
    
    
    string getName(){return name;}
    int getNumOfLands(){return numOfLands;}
    int getManpower(){return manpower;}
    void setManpower(int manpower_x){manpower = manpower_x;}
    void setGold(int gold_x){gold = gold_x;}
    int getGold(){return gold;}
    Land* getLands(){return lands;}
  
    
    
};



class CharacterList{
    
    Character *characters;
    int size;
    
    friend void listCharacters(CharacterList&);
    friend void listLands(CharacterList&);
    
    public:
    CharacterList();
//    ~CharacterList();
    
    void addCharacter(Character);
    void delCharacter(string);
    int getSize(){return size;}
    void setCharacter(Character *newCh){characters = newCh;}
    Character getCharacter(){return *characters;}
    
    Character& getPlayer(string);
    Character& getLandOwner(string);
    
    void updatePlayer(Character &updatedChar){
        int i;
        for(i=0;i<size;i++){
            if(updatedChar.getName()== characters[i].getName())
                characters[i] = updatedChar;
        }
    }
    
    
};



