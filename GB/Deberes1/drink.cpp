#include "drink.h"

void Drink::print(std::ostream &os) const
{
    os << "Drink: " << name << " " << price;
}