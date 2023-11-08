//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

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
        Player(std::string n, int hp, int ex);
        //Destructor
        ~Player() { cout << "Called destructor of: " << name << endl; }
};

Player::Player()
    : name{"No name"}, health{0}, exp{0} {
        
    }
    
Player::Player(std::string n)
    : name{n}, health{0}, exp{0} {
        
    }
    
Player::Player(std::string n, int hp, int ex)
    : name{n}, health{hp}, exp{ex} {
        
    }

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        {
            Player base;
        }
        {
            Player nick("Nikita");
        }
        {
            Player ksy("Kseniia", 100, 500);
        }
        
        Player *big_boss = new Player("BOSS", 1000, 666);
        delete big_boss;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}