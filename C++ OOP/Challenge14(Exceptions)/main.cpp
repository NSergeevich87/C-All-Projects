#include <iostream>
#include "Account.h"
#include "Main_Account.h"
#include <memory>

using namespace std;

int main()
{
    std::unique_ptr<Account> name = std::make_unique<Main_Account>("Nick", 1000);
	
	cout << endl;
	return 0;
}		