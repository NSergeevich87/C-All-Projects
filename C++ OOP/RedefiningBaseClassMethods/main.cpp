#include <iostream>
#include "Savings_Account.h"

using namespace std;

int main()
{
    cout << "==========Account==========" << endl;
    
    Account a1{1000};
    cout << a1 << endl;
    
    a1.deposit(500);
    cout << a1 << endl;
    
    a1.withdraw(700);
    cout << a1 << endl;
    
    a1.withdraw(4700);
    cout << a1 << endl;
    
    cout << "==========Savings_Account==========" << endl;
    
    Savings_Account test;
    
    Savings_Account s1{1000, 5};
    cout << s1 << endl;
    
    s1.deposit(1000);
    cout << s1 << endl;
    
    s1.withdraw(2000);
    cout << s1 << endl;
    
    s1.withdraw(1000);
    cout << s1 << endl;
    
    cout << endl;
    return 0;
}