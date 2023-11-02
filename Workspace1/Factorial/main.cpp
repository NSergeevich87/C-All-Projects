//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

unsigned long long factorial(unsigned long long);
unsigned long long factorial(unsigned long long n)
{
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        cout << factorial(20) << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}