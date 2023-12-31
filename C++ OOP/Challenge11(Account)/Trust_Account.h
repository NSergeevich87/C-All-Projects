#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"
#include "Account.h"

class Trust_Account : public Savings_Account
{
friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
    
private:
    static constexpr const char *def_name = "No_name";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    
    static constexpr double def_bonus_deposit = 5000.0;
    static constexpr double def_bonus = 50.0;
    static constexpr double def_withdraw_limite = 20;
    static constexpr int def_withdraw_counter = 3;
    
protected:
    int withdraw_counter;
    /*double bonus_deposit;
    double bonus;
    double withdraw_limite;*/
    
public:
    Trust_Account(std::string name_val = def_name, double bal_val = def_balance, double rate_val = def_int_rate);
        
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_
