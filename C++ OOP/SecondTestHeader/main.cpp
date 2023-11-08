#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    {
        Account base;
    }
    
    {
        Account Nick("Nikita");
        Nick.deposit(1000);
        Nick.withdraw(100);
    }
    
    {
        Account Ksy("Kseniia", 5000);
        Ksy.deposit(10'000);
        Ksy.withdraw(1250);
    }
    
        Account *Padre = new Account("Sergey", 100'344);
        (*Padre).deposit(1'234'567);
        Padre->withdraw(345);
        delete Padre;
    
    cout << endl;
    return 0;
}