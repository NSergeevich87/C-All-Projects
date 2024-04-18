#include <iostream>
#include <string>

enum class OrderBookType 
{
    BID,
    ASK
};

std::ostream &operator<<(std::ostream &os, const OrderBookType &type);

class OrderBookEntry
{
    friend std::ostream &operator<<(std::ostream &os, const OrderBookEntry &obe);

    private:
        std::string timestamp;
        std::string pair;
        OrderBookType type;
        double price;
        double amount;
    
    public:
        OrderBookEntry(std::string timestamp_val, std::string pair_val, OrderBookType type_val, double price_val, double amount_val);

        ~OrderBookEntry() {}

        std::string getTimestamp();

        std::string getPair() const;

        OrderBookType getType() const;

        double getPrice() const;

        double getAmount() const;
};