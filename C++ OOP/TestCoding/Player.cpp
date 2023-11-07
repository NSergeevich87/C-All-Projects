#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

void Player::set_health(float hp)
{
    health = hp;
}

float Player::get_health()
{
    return health;
}
    
void Player::set_mana(float m)
{
    mana = m;
}
    
float Player::get_mana()
{
    return mana;
}
    
void Player::set_exp(int ex)
{
    if ((experience + ex) >= 1000)
    {
        int num = ex / 1000;
        int add_to_exp = (ex % 1000);
        experience += add_to_exp;
        while (num > 0)
        {
            lvl_up();
            --num;
        }
    }
    else
    {
        experience = ex;
    }
}
    
void Player::get_exp()
{
    cout << "Your exp is: " << experience << endl;
}

void Player::get_lvl()
{
    cout << "Your lvl is: " << level << endl;
}

void Player::lvl_up()
{
    level += 1;
}


