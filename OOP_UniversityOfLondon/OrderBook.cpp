#include "headers/OrderBook.h"

#include <map>
#include <algorithm>

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

/** get earliest time from order book */
std::string OrderBook::getEarliestTime()
{
    /** before we need sort orders */
    std::sort(orders.begin(), orders.end(), [](OrderBookEntry a, OrderBookEntry b) { 
        return a.getTimestamp() < b.getTimestamp(); 
        });

    return orders[0].getTimestamp();
}
/** get next timestamp */
std::string OrderBook::getNextTime(const std::string& timestamp)
{
    std::string next_timestamp = "";

    for (OrderBookEntry& order : orders)
    {
        if (order.getTimestamp() > timestamp)
        {
            next_timestamp = order.getTimestamp();
            break;
        }
    }

    if (next_timestamp == "")
    {
        next_timestamp = getEarliestTime();
    }

    return next_timestamp;
}
/** check products for current time */
bool OrderBook::checkProductExists(std::string timestamp, std::string product)
{
    for (OrderBookEntry& order : orders)
    {
        if (order.getTimestamp() == timestamp && order.getPair() == product)
            return true;
    }

    return false;
}

/** change value and % for time */
void OrderBook::changingValueAndPercentageForAsks(std::string timestamp)
{
    /** get all pairs */
    std::vector<std::string> pairs = getKnownProducts();
    /** we need to set start value of all pairs */
    std::map<std::string, double> start_value;
    for (const std::string& pair : pairs)
    {
        /** we should to find value for earliest time */
        start_value[pair] = getOrders(getEarliestTime(), pair, OrderBookType::ask)[0].getPrice();
    }
    /** then get actual value for current time */
    std::map<std::string, double> actual_value;
}
