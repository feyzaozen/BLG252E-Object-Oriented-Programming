// Feyza Özen
// 150190014
#pragma once

#include <iostream>
#include "Faction.h"

using namespace std;


class Orcs : public Faction
{
public:
    Orcs(string name, int  numberOfUnits, int attackPoint, int healthPoint, int unitRegenerationNumber) : Faction(name, numberOfUnits, attackPoint, healthPoint, unitRegenerationNumber){}
    void PerformAttack();
    void ReceiveAttack(string, int);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};
