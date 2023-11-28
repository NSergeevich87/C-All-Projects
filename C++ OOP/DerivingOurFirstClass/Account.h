#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
#include <iostream>

class Account
{
public:
	std::string name;
	double balance;
	
	void deposit(double val);
	void withdraw(double val);
	
	Account();
	~Account();

};

#endif // _ACCOUNT_H_
