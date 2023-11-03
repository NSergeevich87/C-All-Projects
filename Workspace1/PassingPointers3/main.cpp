//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

void display(const vector<string> *const s);
void display(const vector<string> *const s)
{
    //(*s).at(0) = "Sergey";
    
    for (auto name : *s)
        cout << name << " ";
    cout << endl;
    
    //s = nullptr;
}
void display(int *array, int stop)
{
    while ( *array != stop )
    {
        cout << *array++ << " ";
        cout << array << " ";
    }
    cout << endl;
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        vector<string> names { "Nikita", "Kseniia", "Daniil" };
        display(&names);
        
        int arr[] { 2, 34, 56, 7, 89, 87, 6, 54, -1 };
        display( arr, -1 );
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}