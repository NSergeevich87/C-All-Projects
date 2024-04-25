#pragma once

#include <string>
#include <vector>

#include "headers/OrderBookEntry.h"
#include "headers/CSVReader.h"

class OrderBook
{
    public:
        /** Construct, reading a csv data file */
        OrderBook(std::string filename);
        /** return vector of all know products in the dataset */
        std::vector<std::string> getKnownProducts();
        /** return vector of orders according to the sent filters */
        std::vector<OrderBookEntry> getOrders(std::string timestamp, std::string product, OrderBookType type);
};