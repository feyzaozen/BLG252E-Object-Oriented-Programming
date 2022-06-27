
//Feyza Özen 150190014  23 June 2021


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Warlord {
private:
    int power;
    int magic;
public:
    
    int getPower(){ return power; }
    int getMagic(){ return magic; }
    
    /* Write a constructor */
    
    
    Warlord(int power_x = 0,int magic_x = 0){
        
        
        if(power_x < 0) throw "A warlord cannot have negative power!";
        if(magic_x <= 0) throw "A warlord cannot be a non-magic wielder!";
        
        else{
        power = power_x;
        magic = magic_x;
        }
    }

    /* Write Print function */
    
    void Print(){
    cout << "Power: " << power<< " Magic: "<<magic << endl;
    }
    
};

/* Write a comparison function which will return true if first parameter is bigger than the second */

bool Comp(Warlord w1, Warlord w2){
    bool value = w1.getPower() + w1.getMagic() > w2.getPower() + w2.getMagic();
    
    
    return value;}


/* Define an STL container (vector, list, etc.) here. Use typedef to name it as "Container" */


typedef vector<Warlord> Container;

typedef Container::iterator Iterator;


/* You should not change or remove the given code parts. Add necessary codes to get the same result with sample output */
int main() {

    Warlord w1(1, 1);
    Warlord w2(2, 2);
    Warlord w3(2, 1);

    /* Initialize the "Container" and put the w1,w2, and w3 into container */
    
    Container lords;
    lords={w1,w2,w3};
    
    cout << "Unsorted Warlords" << endl;
    
    for (Iterator i = lords.begin(); i != lords.end(); i++) {
        (*i).Print();
    }

    /* Sort Warlords in the container */
    sort(lords.begin(), lords.end(), Comp);

    cout << endl << "Sorted Warlords" << endl;
    
    for (Iterator i = lords.begin(); i != lords.end(); i++) {
        (*i).Print();
        
    }
    

    try{
        Warlord w4; /* by default warlords have zero power and zero magic*/
        w4.Print();
    }catch (const char *message){
        cout << endl << message << endl;}


    return 0;
}


