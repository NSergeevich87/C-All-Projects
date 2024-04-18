#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "headers/OrderBookEntry.h"
#include "headers/MerkelMain.h"

using namespace std;

void OrderBookPrint(const vector<OrderBookEntry> &orderBook)
{
    for (const OrderBookEntry &entry : orderBook)
    {
        cout << entry << endl;
    }
}

double computeAveragePrice(const vector<OrderBookEntry> &entries)
{
    double sum = 0;
    for (const OrderBookEntry &entry : entries)
    {
        sum += entry.getPrice();
    }

    return sum / entries.size();
}

double computeLowPrice(const vector<OrderBookEntry>& entries)
{
    double low = entries[0].getPrice();
    for (const OrderBookEntry &entry : entries)
    {
        if (entry.getPrice() < low)
        {
            low = entry.getPrice();
        }
    }

    return low;
}

double computeHighPrice(const vector<OrderBookEntry>& entries)
{
    double high = entries[0].getPrice();
    for (const OrderBookEntry &entry : entries)
    {
        if (entry.getPrice() > high)
        {
            high = entry.getPrice();
        }
    }

    return high;
}

double computePriceSpread(const std::vector<OrderBookEntry>& entries)
{
    return computeHighPrice(entries) - computeLowPrice(entries);
}

int main() 
{
    MerkelMain main;
    main.run();

    // std::vector<OrderBookEntry> orderBook;

    // orderBook.push_back(OrderBookEntry(
    //     "2020/03/17 17:01:24.884492", 
    //     "ETH/RTM", 
    //     OrderBookType::BID, 
    //     0.02183269, 
    //     4.89101735
    // ));

    // orderBook.push_back(OrderBookEntry(
    //     "2020/03/17 17:01:24.884492", 
    //     "ETH/RTM", 
    //     OrderBookType::BID, 
    //     0.02183264, 
    //     3.9101735
    // ));

    // orderBook.push_back(OrderBookEntry(
    //     "2020/03/17 17:01:24.884492", 
    //     "ETH/RTM", 
    //     OrderBookType::ASK, 
    //     0.02196165, 
    //     0.00630238
    // ));

    // orderBook.push_back(OrderBookEntry(
    //     "2020/03/17 17:01:24.884492", 
    //     "ETH/RTM", 
    //     OrderBookType::ASK, 
    //     0.02227042, 
    //     37.7
    // ));

    // orderBook.push_back(OrderBookEntry(
    //     "2020/03/17 17:01:24.884492", 
    //     "RTM/BTC", 
    //     OrderBookType::BID, 
    //     0.03, 
    //     3.9101735
    // ));

    // OrderBookPrint(orderBook);

    // cout << "Average price: " << computeAveragePrice(orderBook) << endl;
    // cout << "Low price: " << computeLowPrice(orderBook) << endl;
    // cout << "High price: " << computeHighPrice(orderBook) << endl;
    // cout << "Price spread: " << computePriceSpread(orderBook) << endl;

    return 0;
}