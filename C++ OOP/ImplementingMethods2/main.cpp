#include "Account.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    Account Nick_Acc;
    Nick_Acc.set_name("Nikita");
    Nick_Acc.set_balance(1000);
    
    if (Nick_Acc.deposit(200))
        cout << "Deposit OK" << endl;
    else
        cout << "Deposit NOT Allowed" << endl;
        
    if (Nick_Acc.withdraw(500))
        cout << "Withdrawal OK" << endl;
    else
        cout << "Not sufficient funds" << endl;
        
    if (Nick_Acc.withdraw(1500))
        cout << "Withdrawal OK" << endl;
    else
        cout << "Not sufficient funds" << endl;
    
    cout << endl;
    return 0;
}