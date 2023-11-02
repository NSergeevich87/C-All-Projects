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
        cout << "==========================================" << endl;
        
        bool done {false};
        int number {0};
        while (!done)
        {
            cout << "Enter number between 1 and 5: ";
            cin >> number;
            if (number <= 1 || number >= 5)
            {
                cout << "Out of range, try again: ";
            }
            else
            {
                cout << "Thanks!" << endl;
                done = true;
            }
        }
        
        
        
        
        
        
        
        cout << "==========================================" << endl;
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