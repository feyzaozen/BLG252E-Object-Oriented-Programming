// Feyza Özen
// 150190014
#include "Merchant.h"

using namespace std;

Merchant::Merchant()
{
    startingWeaponPoint = 0;
    startingArmorPoint = 0;
    revenue = 0;
    weaponPoint = 0;
    armorPoint = 0;
    firstFaction = NULL;
    secondFaction = NULL;
    thirdFaction = NULL;
}

Merchant::Merchant(int weaponPoint, int armorPoint)
{
    startingWeaponPoint = weaponPoint;
    startingArmorPoint = armorPoint;
    revenue = 0;
    this -> weaponPoint = weaponPoint;
    this -> armorPoint = armorPoint;
    firstFaction = NULL;
    secondFaction = NULL;
    thirdFaction = NULL;
}

void Merchant::AssignFactions(Faction *firstFaction_x, Faction *secondFaction_x, Faction *thirdFaction_x)
{
    firstFaction = firstFaction_x;
    secondFaction = secondFaction_x;
    thirdFaction = thirdFaction_x;
}

bool Merchant::SellWeapons(string name, int weapon)
{
    if (firstFaction->getName() == name)
    {
        if (firstFaction->getIsAlive() == 0)
        {
            
            cout << "The faction you want to sell weapons is dead!" << endl;
            return false;
        }
        if (weaponPoint < weapon)
        {
            
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false;
        }
        
        cout << "Weapons sold!" << endl;
        
        revenue = revenue + firstFaction->PurchaseWeapons(weapon);
        weaponPoint = weaponPoint - weapon;
      
        return true;}
    if (secondFaction->getName() == name)
    {
        if (secondFaction->getIsAlive() == 0)
        {
            
            cout << "The faction you want to sell weapons is dead !" << endl;
            return false;
        }
        if (weaponPoint < weapon)
        {
           
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false;
        }
        cout << "Weapons sold!" << endl;
        
        revenue = revenue + secondFaction->PurchaseWeapons(weapon);
        weaponPoint = weaponPoint - weapon;
      
        return true;}
    if (thirdFaction->getName() == name)
    {
        if (thirdFaction->getIsAlive() == 0)
        {
            
            cout << "The faction you want to sell weapons is dead !" << endl;
            return false;
        }
        if (weaponPoint < weapon)
        {
            
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false;
        }
        cout << "Weapons sold!" << endl;
        
        revenue = revenue + thirdFaction->PurchaseWeapons(weapon);
        weaponPoint = weaponPoint - weapon;
      
        return true;}
    
    
    return false;
}

bool Merchant::SellArmors(string name, int armor)
{
    if (firstFaction->getName() == name)
    {
        if (firstFaction->getIsAlive() == 0)
        {
            
            cout << "The faction you want to sell armors is dead !" << endl;
            return false;
        }
        if (armorPoint < armor)
        {
            
            cout << "You try to sell more armors than you have in possession." << endl;
            return false;
        }
        
        cout << "Armors sold!" << endl;
        
        armorPoint = armorPoint - armor;
        revenue = revenue + firstFaction->PurchaseArmors(armor);
        
        return true;
    }
    if (secondFaction->getName() == name)
    {
        if (secondFaction->getIsAlive() == 0)
        {
           
            cout << "The faction you want to sell armors is dead !" << endl;
            return false;
        }
        if (armorPoint < armor)
        {
          
            cout << "You try to sell more armors than you have in possession." << endl;
            return false;
        }
     
        cout << "Armors sold!" << endl;
        
        armorPoint = armorPoint - armor;
        revenue = revenue + firstFaction->PurchaseArmors(armor);
        
        return true;
    }
    if (thirdFaction->getName() == name)
    {
        if (thirdFaction->getIsAlive() == 0)
        {
           
            cout << "The faction you want to sell armors is dead !" << endl;
            return false;
        }
        if (armorPoint < armor)
        {
            
            cout << "You try to sell more armors than you have in possession." << endl;
            return false;
        }
        cout << "Armors sold!" << endl;
        
        armorPoint = armorPoint - armor;
        revenue = revenue + firstFaction->PurchaseArmors(armor);
        return true;
    }
    
    
    return false;
}

void Merchant::EndTurn()
{
    weaponPoint = startingWeaponPoint;
    armorPoint = startingArmorPoint;
}
