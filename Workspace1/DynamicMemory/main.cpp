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
        
        /*int *int_ptr { nullptr };
        int_ptr = new int;
        cout << int_ptr << endl;
        delete int_ptr;*/
        
        size_t size { 0 };
        double *ptr_array { nullptr };
        cout << "Enter size of the array: ";
        cin >> size;
        cout << ptr_array << endl;
        ptr_array = new double[size];
        cout << "Address of the array is: " << ptr_array << endl;
        delete [] ptr_array;
        
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}