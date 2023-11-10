#include <iostream>
#include <string>

using namespace std;

class Player

{
private:
    std::string name;
    int health;
    int exp;
public:
    //Methods
    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_exp() { return exp; }
    //Base constructor
    Player(std::string name_val = "NO_name", int health_val = 0, int exp_val = 0);
    //Copy constructor
    Player(const Player &sourse);
    //Destructor
    ~Player() { cout << "Called destructor of: " << name << endl; }
};

Player::Player(std::string name_val, int health_val, int exp_val)
    : name{name_val}, health{health_val}, exp{exp_val} {
        cout << "Three-args constructor for " + name << endl;
    }
    
Player::Player(const Player &sourse)
    : Player{sourse.name, sourse.health, sourse.exp} {  //deligating
    //: name{sourse.name}, health{sourse.health}, exp{sourse.exp} {
        cout << "Copy constructor - made copy of: " << sourse.name << endl;
    }
    
void display_player(Player p)
{
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "Exp: " << p.get_exp() << endl;
}

int main()
{
    Player empty {"XXX", 45, 54};
    Player my_new_player {empty};
    display_player(empty);
    
    Player nick {"Nick"};
    Player hero {"Hero", 100};
    Player ksy {"Kseniia", 100, 500};
    
    cout << endl;
    return 0;
}