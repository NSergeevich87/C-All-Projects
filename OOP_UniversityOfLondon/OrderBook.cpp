#include "headers/OrderBook.h"

#include <map>

/** Construct, reading a csv data file */
OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}
/** return vector of all know products in the dataset */
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> types_of_products;

    std::map<std::string, bool> product_map;

    for (const OrderBookEntry& order : orders)
    {
        product_map[order.getPair()] = true;
    }

    for (const auto& p : product_map)
    {
        types_of_products.push_back(p.first);
    }
 
    return types_of_products;
}
/** return vector of orders according to the sent filters */
std::vector<OrderBookEntry> OrderBook::getOrders(
    std::string timestamp, 
    std::string product, 
    OrderBookType type)
{
    std::vector<OrderBookEntry> result;

    for (OrderBookEntry& order : orders)
    {
        if (order.getTimestamp() == timestamp && order.getPair() == product && order.getType() == type)
            result.push_back(order);
    }

    return result;
}

/** static function for getting high price */
double OrderBook::getHighPrice(const std::vector<OrderBookEntry>& orders)
{
    double max = orders[0].getPrice();

    for (const OrderBookEntry& order : orders)
    {
        if (order.getPrice() > max) max = order.getPrice();
    }

    return max;
}

/** static function for getting low price */
double OrderBook::getLowPrice(const std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].getPrice();

    for (const OrderBookEntry& order : orders)
    {
        if (order.getPrice() < min) min = order.getPrice();
    }

    return min;
}

/** static function for getting spread */
double OrderBook::getSpread(const double max, const double min)
{
    return max - min;
}