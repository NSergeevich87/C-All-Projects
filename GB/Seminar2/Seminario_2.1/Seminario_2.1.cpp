// Seminario_2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Human.h"
#include "Market.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Seminario_2\n";
    cout << boolalpha;

    Market Market_1;

    Human Human_1("Nick");

    
    Market_1.AcceptToMarket(Human_1);

    return 0;
}