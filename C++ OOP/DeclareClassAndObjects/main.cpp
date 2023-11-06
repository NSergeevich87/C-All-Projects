//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

class Player
{
    //Параметры
    string Name{"Player"};
    float Hp{100};
    float Xp{3};
    
    //Методы
    void Speak(string);
    bool isDead();
};

class Account
{
    string name {"Account"};
    float balance {0.f};
    
    bool deposit(float);
    bool withdraw(float);
};

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        Account NickAcc;
        Account KsyAcc;
        
        Player Nikita;
        Player Kseniia;
        
        Player players[] {Nikita, Kseniia}; 
        
        vector<Player> players_vector {Nikita};
        players_vector.push_back(Kseniia);
        
        Player *Enemy { nullptr };
        Enemy = new Player;
        
        delete Enemy;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}