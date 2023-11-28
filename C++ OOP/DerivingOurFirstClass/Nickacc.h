#ifndef _NICKACC_H_
#define _NICKACC_H_

#include "Account.h"

class Nickacc : public Account
{
public:
	double int_rate;
	
	void deposit(double val);
	void withdraw(double val);
	
	Nickacc();
	~Nickacc();

};

#endif // _NICKACC_H_
