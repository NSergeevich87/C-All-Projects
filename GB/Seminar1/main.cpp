#include <iostream>
#include "avtomat.h"

using namespace std;

int main()
{
    avtomat products{};
    products.add_product("moloko", 10);
    products.add_product("kefir", 11);
    products.add_product("smetana", 14);
    products.add_product("sir", 21);

    products.getProduct("moloko");
    products.getProduct("kefir");
    products.getProduct("kefir");
    products.getProduct("kefir");
    products.getProduct("kefir");
    products.getProduct("sir");

    products.printProducts();

    return 0;
}