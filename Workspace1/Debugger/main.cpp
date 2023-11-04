//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        int i{5};
        while (i > 0)
        {
            cout << i << endl;
            i--;
        }
        
        int x {100};
        int y {200};
        cout << x << " " << y << endl;
        swap(x, y);
        cout << x << " " << y << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}