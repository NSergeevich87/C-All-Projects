//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

class Player
{
public:
    string name {"Player"};
    float HP {100};
    float XP {3};
    
    void talk(string text) { cout << name << " say: " << text << endl; }
    bool isDead();
};

class Account
{
public:
    string name {"Account"};
    float balance {0.f};
    
    void deposit (float amount) { balance += amount; cout << name << " deposited!" << endl; }
    void withdraw (float amount) { balance -= amount; cout << name << " withdrawded!" << endl; }
};

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        Player Nick;
        Nick.name = "Nikitosik";
        Nick.HP = 1000;
        Nick.XP = 999;
        Nick.talk("me fastidia mycho lo de vatniky");
        
        Player *Enemy = new Player;
        (*Enemy).name = "Enemy";
        Enemy->HP = 200;
        (*Enemy).XP = 500;
        Enemy->talk("I'll destroy you!");
        delete Enemy;
        
        Account Nick_Acc;
        Nick_Acc.name = "Nick's account";
        Nick_Acc.balance = 5000.f;
        Nick_Acc.deposit(1'000'000.f);
        Nick_Acc.withdraw(500.f);
        
        Account *Ksy_Acc = new Account;
        (*Ksy_Acc).name = "Ksy's account";
        Ksy_Acc->balance = 7000;
        Ksy_Acc->deposit(1'250'000);
        (*Ksy_Acc).withdraw(7000);
        delete Ksy_Acc;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}