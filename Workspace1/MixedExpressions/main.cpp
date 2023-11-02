#include <iostream>

using namespace std;

int main()
{
    int total {};
    int num1 {}, num2 {}, num3 {};
    const int count {3};
    
    cout << "Enter 3 numbers: ";
    cin >> num1 >> num2 >> num3;
    
    total = num1 + num2 + num3;
    
    double ave {0.0};
    
    ave = static_cast<double>(total) / count;
    //Или так: ave = total / static_cast<double>(count);
    
    cout << "The 3 numbers where: " << num1 << " , " << num2 << " , " << num3 << endl;
    cout << "The sum of the numbers is: " << total << endl;
    cout << "The average of the numbers is: " << ave << endl;
    
    cout << endl;
    return 0;
}