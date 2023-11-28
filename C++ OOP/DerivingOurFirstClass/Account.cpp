#include "Account.h"

Account::Account() : name{"An_account"}, balance{0.0}
{
}

Account::~Account()
{
}

void Account::deposit(double val)
{
	std::cout << "Account deposit : " << val << "$" << std::endl;
}

void Account::withdraw(double val)
{
	std::cout << "Account withdraw : " << val << "$" << std::endl;
}