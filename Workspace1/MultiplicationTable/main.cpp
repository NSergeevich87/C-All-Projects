//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

int main()
{
    bool Stop {false};
    while (!Stop)
    {
        cout << "Your message heare..." << endl;
        
        for (int num1 {1}; num1 <= 10; ++num1)
        {
            for (int num2 {1}; num2 <= 10; ++num2)
            {
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            }
            cout << "=================================" << endl; 
        }
        
        cout << "For exit press 'Y': ";
        char answer {};
        cin >> answer;
        switch (answer)
        {
            case 'y':
            case 'Y':
                Stop = true;
                break;
        }
    }
    
    cout << endl;
    return 0;
}