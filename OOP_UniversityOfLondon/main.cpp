#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "headers/MerkelMain.h"
#include "headers/Wallet.h"

using namespace std;

int main() 
{
    //MerkelMain app;
    //app.run();
    Wallet wallet1;
    Wallet wallet2;
    wallet1.insertCurrency("BTC", 10);
    wallet2.insertCurrency("ETH", 50);
    
    return 0;
}