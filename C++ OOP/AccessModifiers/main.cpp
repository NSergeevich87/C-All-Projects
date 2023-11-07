//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

class Player
{
private:
    string name {"Nikita"};
    float Hp {};
    float Xp {};
    
public:
    void say(string text) { cout << name << " say: " << text << endl; }
    bool isDead();
};

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        Player Nick;
        //Nick.name = "Nikita";
        //Nick.Xp = 1000;
        Nick.say("V dome stalo tepley!");
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}