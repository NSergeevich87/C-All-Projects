#include <iostream>

using namespace std;

int main()
{
    const int dollars {100};
    const int quarters {25};
    const int dimes {10};
    const int nickels {5};
    const int pennies {1};
    
    int Num_Cent {0};
    
    cout << "Welcome to my change station: " << endl;
    
    cout << "Enter cuontity of cents: ";
    cin >> Num_Cent;
    
    cout << "Your " << Num_Cent << " cents are: ";
    
    cout << "\nDollars: " << Num_Cent / dollars << endl;
    Num_Cent %= dollars;
    
    cout << "Quarters: " << Num_Cent / quarters << endl;
    Num_Cent %= quarters;
    
    cout << "Dimes: " << Num_Cent / dimes << endl;
    Num_Cent %= dimes;
    
    cout << "Nickels: " << Num_Cent / nickels << endl;
    Num_Cent %= nickels;
    
    cout << "Pennies: " << Num_Cent / pennies << endl;
    
    cout << endl;
    return 0;
}