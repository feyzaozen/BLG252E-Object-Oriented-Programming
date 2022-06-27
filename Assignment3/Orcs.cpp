// Feyza Özen
// 150190014
#include "Orcs.h"

using namespace std;

void Orcs::PerformAttack()
{

    if (firstEnemy->getIsAlive() == 1 && secondEnemy->getIsAlive() == 0)
    {
       
        firstEnemy->ReceiveAttack(name,numberOfUnits*attackPoint);
        
    }
    else if(firstEnemy->getIsAlive() == 0 && secondEnemy->getIsAlive() == 1)
    {
        
        secondEnemy->ReceiveAttack(name,numberOfUnits*attackPoint);
        
    }
    else if (firstEnemy->getIsAlive() == 1 && secondEnemy->getIsAlive() == 1)
    {
        if (firstEnemy->getName() == "Elves")
        {
            firstEnemy->ReceiveAttack(name,  0.70 * numberOfUnits * attackPoint);
            secondEnemy->ReceiveAttack(name, 0.30 * numberOfUnits * attackPoint);
            
            return;
            
        }else if(firstEnemy->getName() == "Dwarves"){
            
        firstEnemy->ReceiveAttack(name, numberOfUnits * 0.30 * attackPoint);
        secondEnemy->ReceiveAttack(name, numberOfUnits * 0.70 * attackPoint);
            
        return;
        }
    }
}

void Orcs::ReceiveAttack(string name, int attack)
{
    if (name == "Elves")
    {
        numberOfUnits = numberOfUnits - ((attack * 0.75) / healthPoint);
        return;
    }
    
    numberOfUnits = numberOfUnits - ((attack * 0.80) / healthPoint);
}

int Orcs::PurchaseWeapons(int weaponPoint)
{
    attackPoint = attackPoint + 2 * weaponPoint;
    
return 20 * weaponPoint;}

int Orcs::PurchaseArmors(int armorPoint)
{
    healthPoint = healthPoint + (3 * armorPoint) ;
    
    return armorPoint;}

void Orcs::Print()
{
    cout << "Stop running, you'll only die tired!" << endl;
    
    Faction::Print();
}

