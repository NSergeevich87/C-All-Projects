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

    /** we need to set start and actual values of all pairs */
    std::map<std::string, double> min_value;
    std::map<std::string, double> max_value;
    std::map<std::string, double> actual_value;
    std::map<std::string, double> first_mid_value;

    for (const std::string& pair : pairs)
    {
        if (checkProductExists(timestamp, pair) == false) continue;
        
        min_value[pair] = findMinValueOfPairForTime(orders, timestamp, pair);
        max_value[pair] = findMaxValueOfPairForTime(orders, timestamp, pair);
        actual_value[pair] = findActualValueOfPairForTime(orders, timestamp, pair);
        first_mid_value[pair] = findFirstMediumValueOfPairForTime(orders, timestamp, pair);
    }

    /** print values */
    for (const std::string& pair : pairs)
    {
        if (checkProductExists(timestamp, pair) == false) continue;

        std::cout << "Pair: " << pair << " Minimal price: " << min_value[pair] << std::endl;
        std::cout << "Pair: " << pair << " Maximum price: " << max_value[pair] << std::endl;
        std::cout << "Pair: " << pair << " Actual mid price: " << actual_value[pair] << std::endl;
        std::cout << "Pair: " << pair << " First mid price: " << first_mid_value[pair] << std::endl;

        if ((first_mid_value[pair] - actual_value[pair]) <= 0)
        {
            /** print distance */
            std::cout << "Pair: " << pair << " Distance: +" << actual_value[pair] - first_mid_value[pair] << std::endl;
            /** print the difference as a percentage */
            std::cout << "Pair: " << pair << " Difference as a percentage: +" << (actual_value[pair] - first_mid_value[pair]) / first_mid_value[pair] * 100 << "%" << std::endl;
        }
        else
        {
            /** print distance */
            std::cout << "Pair: " << pair << " Distance: -" << first_mid_value[pair] - actual_value[pair] << std::endl;
            /** print the difference as a percentage */
            std::cout << "Pair: " << pair << " Difference as a percentage: -" << (first_mid_value[pair] - actual_value[pair]) / first_mid_value[pair] * 100 << "%" << std::endl;
        }
        
    }
}

/** find min value of pair for time */
double OrderBook::findMinValueOfPairForTime(std::vector<OrderBookEntry> books, std::string timestamp, std::string pair)
{
    double min = 0.0;

    for (OrderBookEntry& order : books)
    {
        if (order.getTimestamp() <= timestamp && order.getPair() == pair)
        {
            if (min == 0.0)
            {
                min = order.getPrice();
            }
            else
            {
                if (order.getPrice() < min)
                {
                    min = order.getPrice();
                }
            }
        }
    }

    return min;
}

/** find min value of pair for time */
double OrderBook::findMaxValueOfPairForTime(std::vector<OrderBookEntry> books, std::string timestamp, std::string pair)
{
    double max = 0.0;

    for (OrderBookEntry& order : books)
    {
        if (order.getTimestamp() <= timestamp && order.getPair() == pair)
        {
            if (max == 0.0)
            {
                max = order.getPrice();
            }
            else
            {
                if (order.getPrice() > max)
                {
                    max = order.getPrice();
                }
            }
        }
    }

    return max;
}

/** find actual value of pair for current time */
double OrderBook::findActualValueOfPairForTime(std::vector<OrderBookEntry> books, std::string timestamp, std::string pair)
{
    std::vector<double> values;

    for (OrderBookEntry& order : books)
    {
        if (order.getTimestamp() == timestamp && order.getPair() == pair)
        {
            values.push_back(order.getPrice());
        }
    }

    double value = 0.0;

    for (double& val : values)
    {
        value += val;
    }

    return value / values.size();
}

/** find first medium value of pair for first time */
double OrderBook::findFirstMediumValueOfPairForTime(std::vector<OrderBookEntry> books, std::string currentTimestamp, std::string pair)
{
    std::vector<std::string> timestamps = getAllTimestamps();
    std::vector<double> values;
    int timestams_index = 0;

    for (OrderBookEntry& order : books)
    {
        if (timestamps[timestams_index] > currentTimestamp)
        {
            break;
        }
        else if (!checkProductExists(timestamps[timestams_index], pair))
        {
            timestams_index++;
            continue;
        }else if (order.getTimestamp() == timestamps[timestams_index] && order.getPair() == pair)
        {
            values.push_back(order.getPrice());
        }
    }

    double value = 0.0;

    for (double& val : values)
    {
        value += val;
    }

    return value / values.size();
}

/** get all timestamps in order book */
std::vector<std::string> OrderBook::getAllTimestamps()
{
    std::vector<std::string> timestamps;

    for (OrderBookEntry& order : orders)
    {
        timestamps.push_back(order.getTimestamp());
    }

    return timestamps;
}
/** insert new order into orders */
void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

/** implement matching algorithm of bids and asks */
std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string timestamp, std::string product)
{

    /**
     * PSEUDOCODE
     * 
     * 1. Get all asks and bids for the product at the timestamp
     *    asks = getOrders()
     *    bids = getOrders()
     * 2. Create a vector of OrderBookEntry to store the matched orders
     *    vector sales = []
     * 3. Sort the asks by ascending price
     *    sort(asks)
     * 4. Sort the bids by descending price
     *    sort(bids)
     * 5. Loop through the asks and bids
     *   for ask in asks
     *          for bid in bids
     *             if ask.price <= bid.price
     *                sale = new order()
     *                sale.price = ask.price
     *                ...
     *                bid.amount == ask.amount
     *                bid.amount >= ask.amount
     *                bid.amount < ask.amount
    */

    std::vector<OrderBookEntry> asks = getOrders(timestamp, product, OrderBookType::ask);
    std::vector<OrderBookEntry> bids = getOrders(timestamp, product, OrderBookType::bid);
    std::vector<OrderBookEntry> sales;

    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

    for (OrderBookEntry& ask : asks)
    {
        for (OrderBookEntry& bid : bids)
        {
            if (ask.getPrice() <= bid.getPrice())
            {
                OrderBookEntry sale{timestamp, product, OrderBookType::sale, ask.getPrice(), 0};

                if (bid.getAmount() == ask.getAmount())
                {
                    sale.setAmount(ask.getAmount());
                    sales.push_back(sale);
                    bid.setAmount(0);
                    break;
                }
                else if (bid.getAmount() > ask.getAmount())
                {
                    sale.setAmount(ask.getAmount());
                    sales.push_back(sale);
                    bid.setAmount(bid.getAmount() - ask.getAmount());
                    break;
                }
                else
                {
                    sale.setAmount(bid.getAmount());
                    sales.push_back(sale);
                    ask.setAmount(ask.getAmount() - bid.getAmount());
                    bid.setAmount(0);
                    continue;
                }
            }
        }
    }

    return sales;
}
/** matching bids to asks for practice */
std::vector<OrderBookEntry> OrderBook::matchBidsToAsks(std::string timestamp, std::string product)
{
    std::vector<OrderBookEntry> asks = getOrders(timestamp, product, OrderBookType::ask);
    std::vector<OrderBookEntry> bids = getOrders(timestamp, product, OrderBookType::bid);

    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

    std::vector<OrderBookEntry> sales;

    for (OrderBookEntry& bid : bids)
    {
        for (OrderBookEntry& ask :asks)
        {
            if (bid.getPrice() <= ask.getPrice())
            {
                OrderBookEntry sale{timestamp, product, OrderBookType::sale, bid.getPrice(), 0};

                if (bid.getAmount() == ask.getAmount())
                {
                    sale.setAmount(ask.getAmount());
                    sales.push_back(sale);
                    bid.setAmount(0);
                    ask.setAmount(0);
                    break;
                }

                if (bid.getAmount() > ask.getAmount())
                {
                    sale.setAmount(ask.getAmount());
                    sales.push_back(sale);
                    bid.setAmount(bid.getAmount() - ask.getAmount());
                    ask.setAmount(0);
                    continue;
                }

                if (bid.getAmount() < ask.getAmount())
                {
                    sale.setAmount(bid.getAmount());
                    sales.push_back(sale);
                    ask.setAmount(ask.getAmount() - bid.getAmount());
                    bid.setAmount(0);
                    break;
                }
            }
        }
    }

    return sales;
}