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
        std::vector<OrderBookEntry> getALLOrders();
        /** static function for getting high price */
        static double getHighPrice(const std::vector<OrderBookEntry>& orders);
        /** static function for getting low price */
        static double getLowPrice(const std::vector<OrderBookEntry>& orders);
        /** static function for getting spread */
        static double getSpread(const double max, const double min);
        /** get earliest time from order book */
        std::string getEarliestTime();
        /** returns the next time after
         * the sent time in the orderbook
         * If there is no next timestamp, wraps around to the first timestamp 
        */
        std::string getNextTime(const std::string& timestamp);
        /** check products for current time */
        bool checkProductExists(std::string timestamp, std::string product);

        /** exercise for weekly assessment */
        /** change value and % for time */
        void changingValueAndPercentageForAsks(std::string timestamp);

        /** get all timestamps in order book */
        std::vector<std::string> getAllTimestamps();
        /** find min value of pair for time */
        double findMinValueOfPairForTime(std::vector<OrderBookEntry> books, std::string timestamp, std::string pair);
        /** find max value of pair for time */
        double findMaxValueOfPairForTime(std::vector<OrderBookEntry> books, std::string timestamp, std::string pair);
        /** find actual value of pair for current time */
        double findActualValueOfPairForTime(std::vector<OrderBookEntry> books, std::string timestamp, std::string pair);
        /** find first medium value of pair for first time */
        double findFirstMediumValueOfPairForTime(std::vector<OrderBookEntry> books, std::string currentTimestamp, std::string pair);
        /** insert new order into orders */
        void insertOrder(OrderBookEntry& order);

        /** implement matching algorithm of bids and asks */
        std::vector<OrderBookEntry> matchAsksToBids(std::string timestamp, std::string product);
        /** just for practice */
        std::vector<OrderBookEntry> matchBidsToAsks(std::string timestamp, std::string product);
};