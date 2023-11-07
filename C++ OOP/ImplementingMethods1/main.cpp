#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    string name {};
    float balance {};

public:
    void set_balance(float bal) { balance = bal; }
    float get_balance() { return balance; }
    
    void set_name(string n);
    string get_name();
    
    bool deposit(float val);
    bool withdraw(float val);
};

void Account::set_name(string n)
{
    name = n;
}

string Account::get_name()
{
    return name;
}

bool Account::deposit(float val)
{
    balance += val;
    return true;
}

bool Account::withdraw(float val)
{
    if ((balance - val) >= 0)
    {
        balance -= val;
        cout << "Withdrawing succes" << endl;
        return true;
    }
    else
    {
        cout << "No sufficient balance!" << endl;
        return false;
    }
}

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