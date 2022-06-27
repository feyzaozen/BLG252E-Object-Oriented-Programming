// Feyza Özen
// 150190014


#include "Elves.h"

using namespace std;


void Elves::PerformAttack()
{
    if (firstEnemy->getIsAlive() == 1 && secondEnemy->getIsAlive() == 1)
    {
       
        if (firstEnemy->getName() == "Orcs")
        {
            firstEnemy->ReceiveAttack(name, 0.6 * numberOfUnits * 1.5 * attackPoint );
            secondEnemy->ReceiveAttack(name, 0.4 * numberOfUnits * attackPoint);
            return;
        }
        
        
        secondEnemy->ReceiveAttack(name, 0.6 * numberOfUnits * 1.5 * attackPoint);
        firstEnemy->ReceiveAttack(name, 0.4 * numberOfUnits * attackPoint);
        return;
    }
    else if (firstEnemy->getIsAlive())
    {
        if (firstEnemy->getName() == "Orcs")
        {
           
            firstEnemy->ReceiveAttack(name, 1.5 * numberOfUnits * attackPoint);
        }
        else
        {
            
            firstEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
        }
    }
    else
    {
        if (secondEnemy->getName() == "Orcs")
        {
           
            secondEnemy->ReceiveAttack(name, 1.5 * numberOfUnits * attackPoint);
        }
        else
        {
           
            secondEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
        }
    }
}

void Elves::ReceiveAttack(string name, int attack)
{
    
    if (name == "Orcs")
    {
        numberOfUnits = numberOfUnits - ((1.25 * attack) / healthPoint);
        return;
    }numberOfUnits = numberOfUnits - ((0.75 * attack) / healthPoint);
}


int Elves::PurchaseWeapons(int weaponPoint)
{
    attackPoint = attackPoint + 2 * weaponPoint;
    
return 15 * weaponPoint;}

int Elves::PurchaseArmors(int armorPoint)
{
    healthPoint = healthPoint + (4 * armorPoint) ;
    
    return 5 * armorPoint;}

void Elves::Print()
{
    cout << "You cannot reach our elegance." << endl;
    
    Faction::Print();
}
