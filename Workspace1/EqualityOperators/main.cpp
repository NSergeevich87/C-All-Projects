#include <iostream>

using namespace std;

int main()
{
    bool equals {false};
    bool not_equals {false};
    int num1 {}, num2 {};
    
    cout << boolalpha;
    
    cout << "Enter 2 numbers: ";
    cin >> num1 >> num2;
    
    equals = (num1 == num2);
    not_equals = (num1 != num2);
    
    cout << "Numbers - equals: " << equals << endl;
    cout << "Numbers - not_equals: " << not_equals << endl;
    
    cout << endl;
    return 0;
}