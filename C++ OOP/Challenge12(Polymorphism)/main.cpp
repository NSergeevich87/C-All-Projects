#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main()
{
    cout << "==================================================" << endl;
    
    Account *a = new Savings_Account("Nick");
    Account *b = new Savings_Account("Nick", 3000);
    Account *c = new Savings_Account("Nick", 5000, 5);
    cout << *a << endl;
    cout << *b << endl;
    cout << *c << endl;
    
    cout << "==================================================" << endl;
    
    a->deposit(1000);
    b->deposit(1000);
    c->deposit(1000);
    
    cout << *a << endl;
    cout << *b << endl;
    cout << *c << endl;
    
    cout << "==================================================" << endl;
    
    a->withdraw(2000);
    b->withdraw(2000);
    c->withdraw(2000);
    
    cout << *a << endl;
    cout << *b << endl;
    cout << *c << endl;
    
    cout << endl;
    return 0;
}