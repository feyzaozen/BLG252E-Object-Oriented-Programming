// Feyza Özen
// 150190014


#pragma once

#include <iostream>

using namespace std;

class Faction
{
protected:
    string name;
    Faction *firstEnemy;
    Faction *secondEnemy;
    int numberOfUnits;
    int attackPoint;
    int healthPoint;
    int unitRegNumber;
    int totalHealth;
    bool isAlive;
    
public:
    Faction();
    Faction(string, int, int, int, int);
    void AssignEnemies(Faction *first, Faction *second);
    virtual void PerformAttack() = 0;
    virtual void ReceiveAttack(string name, int damage) = 0;
    virtual int PurchaseWeapons(int number) = 0;
    virtual int PurchaseArmors(int number) = 0;
    virtual void Print();
    string getName() { return name; }
    void EndTurn();
    bool getIsAlive() { return isAlive; }
    
};
