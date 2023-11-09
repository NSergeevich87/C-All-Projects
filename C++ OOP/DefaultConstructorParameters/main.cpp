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
    Player(std::string n = "NO_name", int hp = 0, int ex = 0);
};

Player::Player(std::string n, int hp, int ex)
    : name{n}, health{hp}, exp{ex} {
        
    }

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        Player empty;
        Player one("one");
        Player two("two", 2);
        Player three("three", 3, 3);
        
        Player *heap = new Player("Heap!", 100, 3500);
        delete heap;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}