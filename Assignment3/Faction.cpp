// Feyza Özen
// 150190014
#include "Faction.h"

using namespace std;




Faction::Faction()
{
     name = "x";
     numberOfUnits = -1;
     attackPoint = -1;
     healthPoint = -1;
     unitRegNumber = -1;
     totalHealth = -1;
     firstEnemy = NULL;
     secondEnemy = NULL;
     isAlive = true;
    
}

Faction::Faction(string name, int  numberOfUnits, int attackPoint, int healthPoint, int unitRegenerationNumber)
{
     this-> name = name;
     this-> numberOfUnits =  numberOfUnits;
     this-> attackPoint = attackPoint;
     this-> healthPoint = healthPoint;
     this-> unitRegNumber = unitRegenerationNumber;
     totalHealth = numberOfUnits * healthPoint;
     firstEnemy = NULL;
     secondEnemy = NULL;
     isAlive = true;
     
}

void Faction::AssignEnemies(Faction *first, Faction *second)
{
     firstEnemy = first;
     secondEnemy = second;
}

void Faction::Print()
{
     cout << "Faction name:         " << name << endl;
    
     if (isAlive == 1){cout << "Status:               Alive" << endl;}
     else{cout << "Status:               Defeated" << endl;}
    
     cout << "Number of Units:      " << numberOfUnits << endl;
     cout << "Attack Point:         " << attackPoint << endl;
     cout << "Health Point:         " << healthPoint << endl;
     cout << "Unit Regen Number:    " << unitRegNumber << endl;
     cout << "Total Faction Health: "<< numberOfUnits * healthPoint << endl;
}

void Faction::EndTurn()
{
     if (numberOfUnits <= 0){
          numberOfUnits = 0;
          isAlive = false;
          return;
     }
     
    
    
    numberOfUnits = numberOfUnits + unitRegNumber;
}
