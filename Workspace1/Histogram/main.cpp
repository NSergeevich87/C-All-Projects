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
        
        vector<int> data {};
        int numbers_of_items {};
        cout << "How many items do you have? : ";
        cin >> numbers_of_items;
        for (int i {1}; i <= numbers_of_items; ++i)
        {
            int data_item{};
            cout << "Enter data item " << i << ": ";
            cin >> data_item;
            data.push_back(data_item);
        }
        cout << "Displaying histogram: " << endl;
        for (auto val : data)
        {
            for (int i {1}; i <= val; ++i)
            {
                cout << "-";
            }
            cout << endl;
        }
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}