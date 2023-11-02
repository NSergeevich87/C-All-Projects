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
        
        int array[] { 100, 95, 77, 96 };
        int *ptr_array { array };
        
        cout << "Address0: " << array << endl;
        cout << "Address1: " << array + 1 << endl;
        cout << "Address2: " << array + 2 << endl;
        cout << "Address0: " << ptr_array << endl;
        cout << "Address1: " << ptr_array + 1 << endl;
        cout << "Address2: " << ptr_array + 2 << endl;
        
        cout << array[0] << endl;
        cout << array[1] << endl;
        cout << array[2] << endl;
        
        cout << ptr_array[0] << endl;
        cout << ptr_array[1] << endl;
        cout << ptr_array[2] << endl;
        
        cout << *array << endl;
        cout << *(array + 1) << endl;
        cout << *(array + 2) << endl;
        
        cout << *(ptr_array) << endl;
        cout << *(ptr_array + 1) << endl;
        cout << *(ptr_array + 2) << endl;
        
        cout << sizeof(array) << endl;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}