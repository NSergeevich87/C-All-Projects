#pragma once

#include <iostream>
#include <string>

enum class OrderBookType 
{
    bid,
    ask,
    saleASK,
    saleBID,
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
        std::string username;
    
    public:
        /** Constructor */
        OrderBookEntry(std::string timestamp_val, std::string pair_val, OrderBookType type_val, double price_val, double amount_val, std::string username_val = "default_name");
        /** Default destructor */
        ~OrderBookEntry() = default;

        /** Some basic functions */
        std::string getTimestamp() const;
        std::string getPair() const;
        OrderBookType getType();
        double getPrice() const;
        double getAmount() const;
        void setAmount(double amount_val);
        void setType(OrderBookType type_val)
        {
            type = type_val;
        }
        void setUsername(std::string username_val)
        {
            username = username_val;
        }
        std::string getUsername() const
        {
            return username;
        }
        
        static OrderBookType stringToOrderBookType(std::string s);
        /** compare two orderbookentries */
        static bool compareByTimestamp(const OrderBookEntry &a, const OrderBookEntry &b);
        /** compare two orderbookentries by price ascending */
        static bool compareByPriceAsc(const OrderBookEntry &a, const OrderBookEntry &b);
        /** compare two orderbookentries by price descending */
        static bool compareByPriceDesc(const OrderBookEntry &a, const OrderBookEntry &b);
};