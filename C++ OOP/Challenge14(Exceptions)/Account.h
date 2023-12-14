#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account
{
private:
    static constexpr const char *def_name = "No_name";
    static constexpr double def_balance = 0.0;
    
protected:
    std::string name;
    double balance;
    
public:
    Account(std::string name_val = def_name, double bal_val = def_balance);
    virtual bool withdraw(double amount) = 0;
    virtual ~Account() = default;
};

#endif // _ACCOUNT_H_
