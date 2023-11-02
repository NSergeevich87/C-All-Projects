//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

void function0 (int num);
void function1 (int &num);
void function2 (string &s);
void function3 (vector<string> &v);
void function_print_vector (const vector<string> &v);

void function0 (int num)
{
    num = 1000;
}

void function1 (int &num)
{
    num = 1000;
}

void function2 (string &s)
{
    s = "New message";
}

void function3 (vector<string> &v)
{
    v.clear();
}

void function_print_vector (const vector<string> &v)
{
    for(auto s : v)
        cout << s << " ";
    cout << endl;
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        int number {9};
        string name {"Nikita"};
        vector<string> data {"Hitallo", "Vadim", "Nikolay"};
        cout << "Number before functions: " << number << endl;
        function0(number);
        cout << "Number after function0: " << number << endl;
        function1(number);
        cout << "Number after function1: " << number << endl;
        cout << "Name is: " << name << endl;
        function2(name);
        cout << "Name is: " << name << endl;
        function_print_vector(data);
        function3(data);
        function_print_vector(data);
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}