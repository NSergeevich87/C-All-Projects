//#include <climits>
//#include <cfloat>
#include <iostream>
#include <vector> // vector <char> chars{}; or vector <char<int>> chars2d;
#include <iomanip> // cout << fixed << setprecision (2);
#include <cmath>

using namespace std;

int main()
{
    char selection {};
    double num {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        cout << "Enter a double number: ";
        cin >> num;
        
        cout << "sqrt: " << sqrt(num) << endl;  //Корень
        cout << "cbrt: " << cbrt(num) << endl;  //Корень 3й степени
        cout << "sin: " << sin(num) << endl;   
        cout << "cos: " << cos(num) << endl;
        cout << "ceil: " << ceil(num) << endl;  //округление до верха
        cout << "floor: " << floor(num) << endl;//округление до низа
        cout << "round: " << round(num) << endl;
        
        cout << "Enter a power to raise: ";
        double power {};
        cin >> power;
        cout << "pow: " << pow(num, power) << endl;//возведение в степень
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != 'N' && selection != 'n');
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}