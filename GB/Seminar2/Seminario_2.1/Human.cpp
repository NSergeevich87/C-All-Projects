#include "Human.h"
#include <iostream>
#include <string>

std::string Human::get_name()
{
    //std::cout << name << "\n";
    return Actor::name;
}
void Human::setMakeOrder(bool value)
{
    isMakeOrder = value;
}
void Human::setTakeOrder(bool value)
{
    isTakeOrder = value;
}
bool Human::getMakeOrder()
{
    return isMakeOrder;
}
bool Human::getTakeOrder()
{
    return isTakeOrder;
}