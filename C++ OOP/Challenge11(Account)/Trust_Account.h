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
    double bonus_deposit;
    double bonus;
    double withdraw_limite;
    int withdraw_counter;
    
public:
    Trust_Account(std::string name_val = def_name, double bal_val = def_balance, double rate_val = def_int_rate, 
        double val_bonus_deposit = def_bonus_deposit, 
        double val_bonus = def_bonus, 
        double val_withdraw_limite = def_withdraw_limite,
        int val_withdraw_counter = def_withdraw_counter);
        
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_
