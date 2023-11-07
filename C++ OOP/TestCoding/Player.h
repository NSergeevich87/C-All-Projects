#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player
{
private:
    std::string name {};
    float health {};
    float mana {};
    int experience {};
    int level {};
    
public:
    void set_name(std::string n) { name = n; }
    std::string get_name() { return name; }
    
    void set_health(float hp);
    float get_health();
    
    void set_mana(float m);
    float get_mana();
    
    void set_exp(int ex);
    void get_exp();
    
    void get_lvl();
    void lvl_up();

};

#endif // _PLAYER_H_
