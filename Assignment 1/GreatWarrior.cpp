#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "GreatWarrior.h"

using namespace std;



Land::Land(){
    name = "F";
    holding = "village";
} //default constructor


Land::Land(string name_x,string holding_x){
    name = name_x;
    holding = holding_x;
} //

Land::Land(Land &land){
    name = land.name;
    holding = land.holding;
}//constructor with argument


Character::Character(){
    this->name = ' ';
    this->manpower = 3;
    this->gold = 20;
    this->numOfLands = 1;
    this->lands = nullptr;
} //default constructor


Character::Character(string name_x, int manpower_x = 3, int gold_x = 20, int numOfLands_x= 1){
    
    
    this->name = name_x;
    this->manpower = manpower_x;
    this->gold = gold_x;
    this->numOfLands = numOfLands_x;
    this->lands = NULL;
    
}//constructor with argument
    


Character::Character(Character &Ch){
    this->name = Ch.name;
    this->manpower = Ch.manpower;
    this->gold = Ch.gold;
    this->numOfLands = Ch.numOfLands;
    this->lands = Ch.lands;

}//copy constructor


void Character::addLand(Land newLand) {
    
    
    Land *pLand = new Land;
    
    pLand->setName(newLand.getName());
    pLand->setHolding(newLand.getHolding());
    pLand->next=nullptr;

    if(lands==nullptr){
        lands=pLand;
        return;
    }
    Land *ptrLand=lands;
    while(ptrLand->next != nullptr){
        ptrLand=ptrLand->next;
    }

    ptrLand->next=pLand;
};


void Character::removeLand(string name_x){
    Land* pLand = lands;
    

    while(pLand->next->getName() != name_x){
        pLand = pLand->next;
    }

    Land* del = pLand->next;
    pLand->next = pLand->next->next;
    delete del;
    numOfLands -= 1;
}

void Character::getTaxes(){
    
    Land* p = lands;
    while(p != NULL)
    {
        if(p->getHolding() == "village")
            gold = gold + 5;
        else if(p->getHolding() == "castle")
            gold = gold + 7;

        else if(p->getHolding() == "city")
            gold = gold + 10;
    
        p = p->next;
    }
    
    gold = gold - manpower;
}

CharacterList::CharacterList(){
    this->size = 0;
    this->characters = new Character[1];
}


void CharacterList::addCharacter(Character Ch){
    if (size == 0){
        size = 1;
        characters[0] = Ch;
        return;
    }

    CharacterList *newChList = new CharacterList;
    size++;
    newChList->size = size;
    newChList->characters = new Character[size];
    for(int i = 0; i < size-1 ;i++){
        newChList->characters[i] = characters[i];
    }
    newChList->characters[size-1] = Ch;

    delete[] characters;

    characters = new Character[size];
    for(int i = 0; i < size ;i++){
        this->characters[i] =  newChList->characters[i];
    }

    delete[] newChList->characters;
    delete newChList;


}

Character& CharacterList::getPlayer(string name){
    
    int i;
    for(i = 0; i<size+1; i++){
        if(this->characters[i].getName()== name){
            return this->characters[i];
        }
    }
    return this->characters[0];}


void CharacterList::delCharacter(string name){
    if(size == 1){
        delete[] characters;
        size = 0;
        return;
    }
    CharacterList *newList = new CharacterList;
    
    for(int i = 0; i < size-2; i++){
        if(name == this->characters[i].getName()){ continue;}
        newList->addCharacter(this->characters[i]);
    }for(int i = 0; i < size-1; i++){
        this->characters[i] = newList->characters[i]; }
    size--;
}



Character& CharacterList::getLandOwner(string chName){
    int i;
    for(i=0; i<size+1; i++){
        Land *land = characters[i].getLands();
        if(land->getName()!=chName){
            land->next=land->next->next;
            
        }else{return getPlayer(characters[i].getName());}}
    
    return characters[0];
    
}

/*jCharacter::~Character() {
    
    delete[] lands;

    
    
};

CharacterList::~CharacterList(){
    Character* ptr1 = characters;
    delete ptr1;
}; */

