//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

void double_data(int *ptr_number);
void double_data(int *ptr_number)
{
    *ptr_number *= 2;
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        int data { 10 };
        int *p { nullptr };
        cout << data << endl;
        
        double_data(&data);
        cout << data << endl;
        
        p = &data;
        double_data(p);
        cout << data << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}