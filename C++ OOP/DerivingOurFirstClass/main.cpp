#include <iostream>
#include "Account.h"
#include "Nickacc.h"

using namespace std;

int main()
{
	Account acc1;
	acc1.deposit(2500);
	acc1.withdraw(500);
	
	Account *acc2 {nullptr};
	acc2 = new Account;
	acc2->deposit(1500);
	acc2->withdraw(500);
	delete acc2;
	
	Nickacc nickacc1;
	nickacc1.deposit(500'000);
	nickacc1.withdraw(1500);
	
	Nickacc *nickacc2 {nullptr};
	nickacc2 = new Nickacc;
	nickacc2->deposit(1'000'001);
	nickacc2->withdraw(5400);
	nickacc2->deposit(47'003'354);
	delete nickacc2;
	
	cout << endl;
	return 0;
}