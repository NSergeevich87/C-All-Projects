// Seminario_2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Human.h"
#include "Market.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Seminario_2\n" << endl;
    cout << boolalpha;

    Market Market_1;

    Human Human_1("Petya");
    Human Human_2("Vasya");
    Human Human_3("Kolya");
    Human Human_4("Denis");
    Human Human_5("Gena");

    Market_1.PrintQueue();

    Market_1.AcceptToMarket(Human_1);
    Market_1.AcceptToMarket(Human_2);
    Market_1.AcceptToMarket(Human_3);
    Market_1.AcceptToMarket(Human_4);
    Market_1.AcceptToMarket(Human_5);

    Market_1.PrintQueue();

    Market_1.Update();

    Market_1.PrintQueue();

    return 0;
}