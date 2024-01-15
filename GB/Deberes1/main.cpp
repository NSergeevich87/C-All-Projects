#include <iostream>
#include "drink.h"
#include "hot_drink.h"
#include "vending_hot_drinks.h"

using namespace std;

int main()
{
    Drink d1 {"moloko", 10};
    cout << d1 << endl;

    vending_hot_drinks drinks;
    drinks.get_product("chai", 12, 80);
    drinks.get_product("cafe", 16, 70);
    drinks.get_product("cacao", 18, 60);
    
    drinks.print_hot_drinks();

    return 0;
}