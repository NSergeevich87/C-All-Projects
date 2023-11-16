#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    std::string name{};
    int health{};
    int xp{};

public:
    std::string get_name() const { return name; }
    void set_name(std::string n) { name = n; }
    // overload constructions
    Player();
    Player(std::string n);
    Player(std::string n, int h, int x);
};

Player::Player()
    : Player{"No_name", 0, 0} {
        
    }
    
Player::Player(std::string n)
    : Player{n, 0, 0} {
        
    }
    
Player::Player(std::string n, int h, int x)
    : name{n}, health{h}, xp{x} {
         
    }

void display_player_name(const Player &p)
{
    cout << p.get_name() << endl;
}    

int main()
{
    const Player villian {"Villian", 100, 55};
    Player hero {"Hero", 100, 15};
    
    //villian.set_name("Super");
    //hero.set_name("Super");
    
    //cout << villian.get_name() << endl;
    cout << hero.get_name() << endl;
    
    //display_player_name(villian);
    display_player_name(hero);
    
    cout << endl;
    return 0;
}