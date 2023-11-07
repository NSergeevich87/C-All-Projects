#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Player Nick;
    Nick.set_name("Nikita");
    string name = Nick.get_name();
    cout << "Your name is: " << name << endl;
    
    Nick.set_health(100);
    float hp = Nick.get_health();
    cout << "Your hp is: " << hp << endl;
    
    Nick.set_mana(300);
    float mana = Nick.get_mana();
    cout << "Your mana is: " << mana << endl;
    
    Nick.set_exp(500);
    Nick.get_exp();
    Nick.get_lvl();
    
    Nick.set_exp(4200);
    Nick.get_exp();
    Nick.get_lvl();
    
    cout << endl;
    return 0;
}