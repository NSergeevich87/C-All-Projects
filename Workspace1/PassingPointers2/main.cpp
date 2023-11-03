//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

void swap(int *a, int *b);
void swap(int *a, int *b)
{
    int temp { *a };
    *a = *b;
    *b = temp;
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        int x { 1 }, y { 100 };
        cout << "X: " << x << " Y: " << y << endl;
        
        swap( &x, &y );
        cout << "X: " << x << " Y: " << y << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}