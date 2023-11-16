#include "Player.h"

int Player::players_num {0};

Player::Player(std::string name_val, int hp_val, int ex_val)
    : name{name_val}, health{hp_val}, exp{ex_val} {
        ++players_num;
    }
    
Player::Player(const Player &source)
    : Player{ source.name, source.health, source.exp } {
        
    }
    
    
Player::~Player()
{
    --players_num;
}

int Player::get_players_num()
{
    return players_num;
}
