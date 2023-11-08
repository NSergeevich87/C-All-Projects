//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

class Player
{
    private:
        string name;
        int age;
    public:
        void set_name(string n) { name = n; }
        string get_name() { return name; }
        
        /*Player()
        {
            name = "NO_name";
            age = 0;
        }*/
        
        Player(string n, int a)
        {
            name = n;
            age = a;
        }
};

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        Player Nick("Nikita", 36);
        cout << Nick.get_name() << endl;
        
        Player *Daniil = new Player("Daniil", 21);
        cout << Daniil->get_name() << endl;
        (*Daniil).set_name("Daniilkaaa!");
        cout << (*Daniil).get_name() << endl;
        delete Daniil;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}