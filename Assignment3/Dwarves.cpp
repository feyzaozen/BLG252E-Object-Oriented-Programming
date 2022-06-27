// Feyza Özen
// 150190014


#include "Dwarves.h"

using namespace std;


void Dwarves::PerformAttack()
{
    if (firstEnemy->getIsAlive() == 1 && secondEnemy->getIsAlive() == 1)
    {
        firstEnemy->ReceiveAttack(name,0.5 * numberOfUnits * attackPoint);
        secondEnemy->ReceiveAttack(name, 0.5 * numberOfUnits * attackPoint);
        
        
        return;
    }
    else if (firstEnemy->getIsAlive() == 1)
    {
        
        firstEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
        
        
        return;
    }else if (secondEnemy->getIsAlive() == 1){
        
        secondEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
        
        return;
    }
    
 
}
    
    
void Dwarves::ReceiveAttack(string name, int attack)
{
    numberOfUnits = numberOfUnits - (attack / healthPoint);
}
 

int Dwarves::PurchaseWeapons(int weaponPoint)
{
    attackPoint = attackPoint + weaponPoint;
    
return 10 * weaponPoint;}


int Dwarves::PurchaseArmors(int armorPoint)
{
    healthPoint = healthPoint + (2 * armorPoint) ;
    
    return 3 * armorPoint;}


void Dwarves::Print()
{
    cout << "Taste the power of our axes!" << endl;
    
    Faction::Print();
}
