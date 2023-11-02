#include <iostream>

using namespace std;

int main()
{
    int num1 = 200;
    int num2 = 100;
    
    int result {0};
    
    result = num1 % num2;
    cout << "num1 % num2 = " << result << endl;
    
    num1 = 10;
    num2 = 3;
    cout << "num1 % num2 = " << num1 % num2 << endl;
    
    const float usd_per_eur {1.19};
    
    cout << "Welcome to eht EUR to USD converter" << endl;
    cout << "Enter the value in EUR: ";
    
    float euros {0.0};
    double dollars {0.0};
 
    cin >> euros;
    dollars = euros * usd_per_eur;

    cout << dollars << " $ = E " << euros << endl;
        
    cout << endl;
    return 0;
}