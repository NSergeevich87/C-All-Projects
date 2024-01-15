#ifndef _VENDING_HOT_DRINKS_H_
#define _VENDING_HOT_DRINKS_H_

#include <vector>
#include <iostream>
#include "hot_drink.h"

class vending_hot_drinks
{
    public:
        std::vector<Hot_Drink> hot_drinks{};
        void get_product(std::string name, int price, int temp)
        {
            hot_drinks.push_back(Hot_Drink(name, price, temp));
        }
        void print_hot_drinks()
        {
            for(auto i : hot_drinks)
            {
                std::cout << i << std::endl;
            }
        }
};

#endif