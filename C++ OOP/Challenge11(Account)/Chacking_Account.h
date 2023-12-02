#ifndef _CHACKING_ACCOUNT_H_
#define _CHACKING_ACCOUNT_H_

#include "Account.h"

class Chacking_Account : public Account
{
friend std::ostream &operator<<(std::ostream &os, const Chacking_Account &account);

private:
    static constexpr const char *def_name = "No_name";
    static constexpr double def_balance = 0.0;
    static constexpr double def_fee = 1.5;
    
protected:
    double fee;
    
public:
    Chacking_Account(std::string name_val = def_name, double bal_val = def_balance, double fee_val = def_fee);
    bool withdraw(double amount);
    double get_fee() const;

};

#endif // _CHACKING_ACCOUNT_H_
