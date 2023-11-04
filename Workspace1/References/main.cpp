//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        int num {100};
        int &ref {num};
        cout << num << endl;
        cout << ref << endl;
        
        num = 200;
        cout << num << endl;
        cout << ref << endl;
        
        ref = 300;
        cout << num << endl;
        cout << ref << endl;
        
        /*size_t size {};
        int *arr { nullptr };
        cout << "Enter array size: ";
        cin >> size;
        arr = new int[size];
        for(size_t i{0}; i < size; ++i)
        {
            int num {};
            cout << "Enter element for array: ";
            cin >> num;
            *(arr + i) = num;
        }
        for(size_t i{0}; i < size; ++i)
        {
            cout << *(arr + i) << " ";
        }
        delete [] arr;*/
        
        vector<string> names { "Tatyana", "Kseniia", "Nikita", "Victoriya" };
        for(auto str : names)
            cout << str << " ";
        cout << endl;
            
        for(auto const &str : names)
            cout << str << " ";
        cout << endl;
            //str = "NoName";
            
        for(auto str : names)
            cout << str << " ";
        cout << endl;
        
        cout << "\n==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}