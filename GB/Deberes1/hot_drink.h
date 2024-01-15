#ifndef _HOT_DRINK_H_
#define _HOT_DRINK_H_

#include "drink.h"
#include <iostream>

class Hot_Drink : public Drink
{
    protected:
        std::string name{};
        int price{};
        double temperature{};

    public:
        Hot_Drink() = default;
        Hot_Drink(std::string name_val, int price_val, double temp_val) : name{name_val}, price{price_val}, temperature{temp_val} {} 
        ~Hot_Drink() = default;

        
        double get_temp() const { return temperature; }

        void set_temp(double temp) { this->temperature = temp; }

        virtual void print(std::ostream &os) const override;
};

#endif // _HOT_DRINK_H_