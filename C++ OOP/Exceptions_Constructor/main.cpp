#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"

using namespace std;

int main()
{
    try
    {
        std::unique_ptr<Account> Nick {new Checking_Account{"Nick", -10}};
        cout << *Nick << endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        cerr << "Couldn't create account - negative balance" << endl;
    }
	
	cout << "Program completed successfully" << endl;
	return 0;
}		