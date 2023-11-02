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
        int *p {&num};
        
        cout << num << endl;
        cout << *p << endl;
        
        *p = 200;
        cout << num << endl;
        cout << *p << endl;
        
        cout << "\n-------------------------------------------------" << endl;
        
        double high_temp { 78.4 };
        double low_temp { 55.13 };
        double *ptr_temp { &high_temp };
        
        cout << *ptr_temp << endl;
        
        ptr_temp = &low_temp;
        
        cout << *ptr_temp << endl;
        
        cout << "\n-------------------------------------------------" << endl;
        
        string name { "Nikita" };
        string *ptr_name { &name };
        
        cout << *ptr_name << endl;
        
        *ptr_name = "Kseniia";
        
        cout << *ptr_name << endl;
        
        name = "Uyobok Pere";
        
        cout << *ptr_name << endl;
        
        cout << "\n-------------------------------------------------" << endl;
        
        vector<string> names { "Nikita", "Kseniia", "Daniil" };
        vector<string> *ptr_names { &names };
        //ptr_names = &names;
        
        cout << (*ptr_names).at(0) << endl;
        
        for (auto n : *ptr_names)
            cout << n << " ";
        cout << endl;
        
        for (size_t i{0}; i < ptr_names->size(); ++i)
        {
            cout << "Enter new name: ";
            cin >> (*ptr_names).at(i);
        }
        
        for (auto n : *ptr_names)
            cout << n << " ";
        cout << endl;
        
        (*ptr_names).at(0) = "Pere idet na huy";
        cout << (*ptr_names).at(0) << endl;
        cout << names[0] << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}