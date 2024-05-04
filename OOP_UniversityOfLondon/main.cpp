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
    // MerkelMain app;
    // app.run();

    Wallet wallet{};
    std::cout << "Wallet has: " << wallet.containsCurrency("BTC", 1) << std::endl;
    std::cout << "Inserting 100 BTC" << std::endl;
    wallet.insertCurrency("BTC", 100); 
    std::cout << "Wallet has: " << wallet;

    std::cout << "Removing 50 BTC" << std::endl;
    wallet.removeCurrency("BTC", 50);
    std::cout << "Wallet has: " << wallet;

    std::cout << "Inserting 100 ETH" << std::endl;
    wallet.insertCurrency("ETH", 100);
    std::cout << "Wallet has: \n" << wallet << std::endl;
    
    return 0;
}