#ifndef _DRINK_H_
#define _DRINK_H_

#include <iostream>
#include "I_Print.h"

class Drink : public I_Print
{
    private:
        std::string name{};
        int price{};

    public:
        Drink() = default;
        Drink(std::string name_val, int price_val) : name{name_val}, price{price_val} {}
        Drink(const Drink &rhs) : name{rhs.name}, price{rhs.price} {}
        ~Drink() = default;

        std::string get_name() const { return name; }
        int get_price() const { return price; }
        void set_name(std::string name) { this->name = name; }
        void set_price(int price) { this->price = price; }

        virtual void print(std::ostream &os) const override;
};

#endif // _DRINK_H_