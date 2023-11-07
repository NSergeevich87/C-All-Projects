#include "Account.h"
#include "iostream"

using namespace std;

int main()
{
    Account Nick_Acc;
    Nick_Acc.set_balance(1000);
    double dinero = Nick_Acc.get_balance();
    
    cout << endl;
    return 0;
}