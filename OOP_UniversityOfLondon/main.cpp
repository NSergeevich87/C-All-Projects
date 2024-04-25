#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "headers/OrderBookEntry.h"
#include "headers/MerkelMain.h"
#include "headers/CSVReader.h"

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
    MerkelMain app;
    app.run();

    //vector<OrderBookEntry> books = CSVReader::readCSV("20200317.csv");
    //OrderBookPrint(books);
    //cout << "Average price: " << computeAveragePrice(orderBook) << endl;
    //cout << "Low price: " << computeLowPrice(orderBook) << endl;
    //cout << "High price: " << computeHighPrice(orderBook) << endl;
    //cout << "Price spread: " << computePriceSpread(orderBook) << endl;
    
    
    return 0;
}