#include <iostream>

using namespace std;

int main()
{
    cout << boolalpha;
    /*int num1 {}, num2 {};
    cout << "Enter 2 numbers: ";
    cin >> num1 >> num2;
    
    cout << num1 << " < " << num2 << " : " << (num1 < num2) << endl;
    cout << num1 << " <= " << num2 << " : " << (num1 <= num2) << endl;
    cout << num1 << " > " << num2 << " : " << (num1 > num2) << endl;
    cout << num1 << " >= " << num2 << " : " << (num1 >= num2) << endl;*/
    
    const int little_num {10};
    const int large_num {20};
    
    cout << "Enter number less than " << little_num << " : ";
    int new_num {};
    cin >> new_num;
    cout << new_num << " < " << little_num << " is " << (new_num < little_num) << endl;
    
    cout << "Enter number more than " << large_num << " : ";
    cin >> new_num;
    cout << new_num << " > " << large_num << " is " << (new_num > large_num) << endl;
    
    cout << endl;
    return 0;
}