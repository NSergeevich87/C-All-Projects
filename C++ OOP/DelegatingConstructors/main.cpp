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
    Player();
    Player(std::string n);
    Player(std::string n, int health, int exp);
};

Player::Player()
    : Player{ "No_name", 0, 0 } {
        cout << "No args constructor was called!" << endl;
    }
    
Player::Player(std::string n)
    : Player{ n, 0, 0 } {
        cout << "One args constructor was called!" << endl;
    }
    
Player::Player(std::string n, int hp, int ex)
    : name{n}, health{hp}, exp{ex} {
        cout << "All args constructor was called!" << endl;
    }

int main()
{
    Player empty;
    Player nick {"Nikita"};
    Player ksy {"Kseniia", 405, 3456};
    
    cout << endl;
    return 0;
}