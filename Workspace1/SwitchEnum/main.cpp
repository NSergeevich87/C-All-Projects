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
        enum Direction
        {
            left, right, up, down
        };
        
        Direction moving {};
        
        cout << "Enter W, A, S or D: ";
        char ans {};
        cin >> ans;
        switch (ans)
        {
            case 'w':
            case 'W':
                moving = up;
                break;
            case 'a':
            case 'A':
                moving = left;
                break;
            case 's':
            case 'S':
                moving = down;
                break;
            case 'd':
            case 'D':
                moving = right;
                break;
            default:
                cout << "System error!" << endl;
        }
        switch (moving)
        {
            case up:
                cout << "Going forward!" << endl;
                break;
            case left:
                cout << "Going to left!" << endl;
                break;
            case right:
                cout << "Going to right!" << endl;
                break;
            case down:
            {
                cout << "You really want to go dawn? y/n: ";
                char confirm {};
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y')
                {
                    cout << "=(" << endl;
                    cout << "Going down!" << endl;
                }
                else cout << "Super! Let's try more!" << endl;
                break;
            }
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