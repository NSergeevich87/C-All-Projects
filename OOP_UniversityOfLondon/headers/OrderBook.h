#pragma once

#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "CSVReader.h"

class OrderBook
{
    private:
        std::vector<OrderBookEntry> orders;

    public:
        /** Construct, reading a csv data file */
        OrderBook(std::string filename);
        /** return vector of all know products in the dataset */
        std::vector<std::string> getKnownProducts();
        /** return vector of orders according to the sent filters */
        std::vector<OrderBookEntry> getOrders(std::string timestamp, std::string product, OrderBookType type);
        /** static function for getting high price */
        static double getHighPrice(const std::vector<OrderBookEntry>& orders);
        /** static function for getting low price */
        static double getLowPrice(const std::vector<OrderBookEntry>& orders);
        /** static function for getting spread */
        static double getSpread(const double max, const double min);
};