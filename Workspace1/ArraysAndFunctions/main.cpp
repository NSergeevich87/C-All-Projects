//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int num);

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        int array[] { 84, 57, 27, 40, 97 };
        int num = sizeof(array) / sizeof(int);
        cout << "size in main arr: " << num << endl;
        print_array(array, num);
        set_array(array, num, 9);
        print_array(array, num);
        print_array(array, num);
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}

void print_array(const int arr[], size_t size)
{
    for(size_t i{0}; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
    //arr[0] = -9;
}

void set_array(int arr[], size_t size, int num)
{
    for(size_t i{0}; i < size; ++i)
        arr[i] = num;
}