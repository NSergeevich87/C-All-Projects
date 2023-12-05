#include <iostream>

using namespace std;

class Account
{
    public:
        virtual void withdraw(double amount)
        {
            cout << "Account withdraw: " << amount << endl;
        }
        
        virtual ~Account() {}
};

class Savings : public Account
{
    public:
        virtual void withdraw(double amount) override
        {
            cout << "Savings withdraw: " << amount << endl;
        }
        
        virtual ~Savings() {}
};

class Chacking : public Account
{
    public:
        virtual void withdraw(double amount) override final
        {
            cout << "Chacking withdraw: " << amount << endl;
        }
        
        virtual ~Chacking() {}
};

class Trust : public Savings
{
    public:
        virtual void withdraw(double amount) override final
        {
            cout << "Trust withdraw: " << amount << endl;
        }
        
        virtual ~Trust() {}
};

void do_withdraw(Account &name, double amount)
{
    name.withdraw(amount);
}

int main()
{
    Account a;
    Account &ref1 = a;
    ref1.withdraw(1000);
    
    Savings s;
    Account &ref2 = s;
    ref2.withdraw(2000);
    
    cout << endl;
    
    Account a1;
    Savings s1;
    Chacking c1;
    Trust t1;
    
    do_withdraw(a1, 3000);
    do_withdraw(s1, 4000);
    do_withdraw(c1, 5000);
    do_withdraw(t1, 6000);
    
    Account &ref3 = c1;
    do_withdraw(ref3, 7777);
    ref3.withdraw(8888);
    
    cout << endl;
    return 0;
}