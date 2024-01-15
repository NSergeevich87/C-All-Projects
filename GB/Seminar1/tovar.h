#include <iostream>

class tovar
{
    friend std::ostream &operator<<(std::ostream &os, const tovar &t);
    private:
        std::string name{};
        int price{};
    public:
        tovar() = default;
        tovar(std::string name_val, int price_val) : name{name_val}, price{price_val} {}
        tovar(const tovar &rhs) : name{rhs.name}, price{rhs.price} {}
        ~tovar() = default;

        std::string get_name() const { return name; }
        int get_price() const { return price; }
        void set_name(std::string new_name) { name = new_name; }
        void set_price(int new_price) { price = new_price; }
};