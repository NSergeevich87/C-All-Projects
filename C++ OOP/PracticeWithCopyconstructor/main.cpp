#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    std::string name;
    float balance;

public:
    std::string get_name() { return name; }
    float get_balance() { return balance; }
    //Base constructor
    Account(std::string name_val = "NO_name", float balance_val = 0);
    //Copy constructor
    Account(const Account &source);
    //Destructor
    ~Account() { cout << "Distructor was called for: " << name << endl; }
};

Account::Account(std::string name_val, float balance_val)
    : name{name_val}, balance{balance_val} {
        cout << "Constructor was called for: " << name << endl;
    }
    
Account::Account(const Account &source)
    //: Account{source.name, source.balance} {
    : name{source.name}, balance{source.balance} {
        cout << "Copy constructor was called for: " << name << endl;
    }

void display_account(Account acc)
{
    cout << "Name of account: " << acc.get_name() << endl;
    cout << "Balance of account: " << acc.get_balance() << endl;
}

int main()
{
    Account empty {"Empty", 0};
    
    Account new_empty {empty};
    
    Account nick {"Nikita", 5000};
    display_account(nick);
    
    cout << endl;
    return 0;
}