#include "headers/OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(std::string timestamp_val, std::string pair_val, OrderBookType type_val, double price_val, double amount_val)
    : timestamp(timestamp_val), pair(pair_val), type(type_val), price(price_val), amount(amount_val)
{
}

std::string OrderBookEntry::getTimestamp()
{
    return timestamp;
}

std::string OrderBookEntry::getPair() const
{
    return pair;
}

OrderBookType OrderBookEntry::getType() const
{
    return type;
}

double OrderBookEntry::getPrice() const
{
    return price;
}

double OrderBookEntry::getAmount() const
{
    return amount;
}

std::ostream &operator<<(std::ostream &os, const OrderBookEntry &obe)
{
    os << "Timestamp: " << obe.timestamp << " Pair: " << obe.pair << " Type: " << obe.type << " Price: " << obe.price << " Amount: " << obe.amount;
    return os;
}

std::ostream &operator<<(std::ostream &os, const OrderBookType &type)
{
    switch (type)
    {
    case OrderBookType::BID:
        os << "BID";
        break;
    case OrderBookType::ASK:
        os << "ASK";
        break;
    default:
        os << "UNKNOWN";
        break;
    }

    return os;
}