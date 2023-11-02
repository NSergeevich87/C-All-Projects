//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

unsigned long long fibonacci(unsigned long long n);
unsigned long long fibonacci(unsigned long long n)
{
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        cout << fibonacci(5) << endl;
        cout << fibonacci(30) << endl;
        cout << fibonacci(40) << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}