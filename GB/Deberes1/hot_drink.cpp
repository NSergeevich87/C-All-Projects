#include "hot_drink.h"
#include <iostream>

void Hot_Drink::print(std::ostream &os) const
{
    os << "Hot_Drink: " << name << " " << price << " " << temperature;
}