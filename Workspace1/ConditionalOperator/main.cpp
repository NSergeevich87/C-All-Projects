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
        int num1{}, num2{};
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        if (num1 != num2)
        {
            cout << "Largest: " << ((num1 > num2) ? num1 : num2) << endl;
            cout << "Smallest: " << ((num1 < num2) ? num1 : num2) << endl;
        }
        else cout << "The numbers are the same" << endl;
        
        
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