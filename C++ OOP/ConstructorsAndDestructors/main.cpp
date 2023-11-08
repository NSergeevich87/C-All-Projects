//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

class Player
{
    private:
        string name {};
        int health {};
        int xp {};
    
    public:
        void set_name(string n) { name = n; }
        void set_health(int hp) { health = hp; }
        // Overload constructors:
        Player() { cout << "No args constructor called" << endl; }
        Player( string name ) { cout << "Just name constructor called" << endl; }
        Player( string name, int health, int xp ) { cout << "All args constructor called" << endl; }
        // Destructor call:
        ~Player() { cout << "Destructor called for " << name << endl; }
};

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        
        Player Nick;
        Nick.set_name("Nikita");
        
        
        Player player1("Nikita");
        player1.set_name("Nikita");
           
        Player player2("Daniil", 100, 10);
        player2.set_name("Daniil");
        
        
        
        Player *enemy = new Player;
        enemy->set_name("Destroyer"); //(*enemy).set_name
        
        Player *enemy_boss = new Player("Boss", 1000, 0);
        enemy_boss->set_name("Boss");
        
        delete enemy;
        delete enemy_boss;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}