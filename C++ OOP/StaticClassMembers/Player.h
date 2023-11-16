#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player
{
private:
    static int players_num;
    
    std::string name{};
    int health{};
    int exp{};

public:
    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_exp() { return exp; }
    //Full constructor
    Player(std::string name_val = "No_Name", int hp_val = 0, int ex_val = 0);
    //Copy constructor
    Player(const Player &source);
    //Destructor
    ~Player();
    
    static int get_players_num();
};

#endif // _PLAYER_H_
