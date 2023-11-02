//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

void local_example()
{
    int num {5000};
    cout << "NO static Num = " << num << endl;
    num += 1000;
    cout << "NO static Num + 1000 = " << num << endl;
}

void static_local_example() 
{
    static int num {5000};
    cout << "Static Num = " << num << endl;
    num += 1000;
    cout << "Static Num + 1000 = " << num << endl;
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        local_example(); 
        local_example();
        static_local_example();  
        static_local_example();  
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}