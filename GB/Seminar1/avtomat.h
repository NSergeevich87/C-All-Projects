#include <iostream>
#include <vector>
#include "tovar.h"

class avtomat
{
    std::vector<tovar> tovars {};

    public:
        int all_price{};
        void getProduct(std::string name)
        {
            for(tovar i : tovars)
            {
                if (i.get_name() == name)
                {
                    std::cout << i << std::endl;
                    all_price += i.get_price();
                }
                else std::cout << "Net tovara!" << std::endl;
            }
        }
        void printProducts()
        {
            for(tovar i : tovars)
            {
                std::cout << i << std::endl;
            }

            std::cout << "All_price: " << all_price << std::endl;
        }
        void add_product(std::string name, int price)
        {
            tovars.push_back(tovar(name, price));
        }
};