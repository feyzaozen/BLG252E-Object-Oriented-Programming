// Feyza Özen
// 150190014
#pragma once

#include <iostream>
#include "Faction.h"

using namespace std;

class Merchant
{
    Faction *firstFaction;
    Faction *secondFaction;
    Faction *thirdFaction;
    int startingWeaponPoint;
    int startingArmorPoint;
    int revenue;
    int weaponPoint;
    int armorPoint;

public:
    Merchant();
    Merchant(int, int);
    void AssignFactions(Faction *, Faction *, Faction *);
    bool SellWeapons(string, int);
    bool SellArmors(string, int);
    void EndTurn();
    int getRevenue() { return revenue; }
    int getWeaponPoints() { return weaponPoint; }
    int getArmorPoints() { return armorPoint; }
};
