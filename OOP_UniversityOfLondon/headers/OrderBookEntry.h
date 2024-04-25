#pragma once

#include <iostream>
#include <string>

enum class OrderBookType 
{
    bid,
    ask,
    unknown
};

std::ostream &operator<<(std::ostream &os, const OrderBookType &type);

class OrderBookEntry
{
    /** Overload ostream operator << for print in console */
    friend std::ostream &operator<<(std::ostream &os, const OrderBookEntry &obe);

    private:
        std::string timestamp;
        std::string pair;
        OrderBookType type;
        double price;
        double amount;
    
    public:
        /** Constructor */
        OrderBookEntry(std::string timestamp_val, std::string pair_val, OrderBookType type_val, double price_val, double amount_val);
        /** Default destructor */
        ~OrderBookEntry() = default;

        /** Some basic functions */
        std::string getTimestamp();
        std::string getPair() const;
        OrderBookType getType();
        double getPrice() const;
        double getAmount() const;
        
        static OrderBookType stringToOrderBookType(std::string s);
};