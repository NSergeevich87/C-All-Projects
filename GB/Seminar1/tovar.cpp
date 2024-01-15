#include "tovar.h"

std::ostream &operator<<(std::ostream &os, const tovar &t)
{
    os << "Name: " << t.name << " Type: " << t.price;
    return os;
}