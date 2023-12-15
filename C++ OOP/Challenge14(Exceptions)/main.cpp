#include <iostream>
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"
#include "Account.h"
#include "Main_Account.h"
#include <memory>

using namespace std;

int main()
{
    try
    {
        std::unique_ptr<Account> name = std::make_unique<Main_Account>("Nick", 1000);
        name->withdraw(900);
        name->get_bal();
        name->withdraw(101);
        name->get_bal();
    }
    catch (const IllegalBalanceException &ex)
    {
        cerr << ex.what() << endl;
    }
    catch (const InsufficentFundsException &ex)
    {
        cerr << ex.what() << endl;
    }
	
	cout << "Program terminate successfully" << endl;
	return 0;
}		