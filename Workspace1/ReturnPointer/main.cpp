//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);

using namespace std;

int *create_array(size_t size, int num = 0)
{
    int *new_array { nullptr };
    new_array = new int[size];
    for (size_t i{0}; i < size; ++i)
         *(new_array + i) = num; //или так: new_array[i] = num;
    return new_array;
}
void display(const int *const arr, size_t size)
{
    for (size_t i{0}; i < size; ++i)
    {
        cout << *(arr + i) << " "; //или так: cout << arr[i] << " ";
        cout << arr + i << " "; //просматриваем адрес каждого элемента
    }
    cout << endl;
}

int main()
{
    char selection {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        int *myNewArr { nullptr };
        size_t size;
        int number {};
        
        cout << "Enter size of the array: ";
        cin >> size;
        
        cout << "Enter default number of the array: ";
        cin >> number;
        
        myNewArr = create_array(size, number);
        display(myNewArr, size);
        delete [] myNewArr;
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}