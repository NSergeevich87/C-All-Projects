//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);
#include <vector>

using namespace std;

void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);

void print(int num)
{
    cout << num << endl;
}

void print(double num)
{
    cout << num << endl;
}

void print(string text)
{
    cout << text << endl;
}

void print(string text1, string text2)
{
    cout << "text1: " << text1 << " and text2: " << text2 << endl;
}

void print(vector<string> text)
{
    for(string t : text)
        cout << t << endl;
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        print(50);
        print('B');
        print(150.5);
        print(89.45f);
        print("C style string");
        string s {"C++ style"};
        print(s);
        print("C style string", s);
        vector<string> vec {"Nikita", "Kseniia", "Daniil"};
        print(vec);
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}