#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "headers/OrderBookEntry.h"
#include "headers/MerkelMain.h"
#include "headers/Tokeniser.h"

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

    Tokeniser tokeniser;
    vector<string> orderBook;
    orderBook.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02186299,0.1");
    orderBook.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02185561,9.14455526");
    orderBook.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.0218247,0.01248192");
    orderBook.push_back("2020/03/17 17:01:40.107326,BTC/USDT,bid,5327.46290721,0.00024266");
    orderBook.push_back("2020/03/17 17:01:45.111661,DOGE/BTC,ask,0.00000076,3010444.3290228");
    orderBook.push_back("");
    orderBook.push_back(",,,");
    orderBook.push_back("test");
    orderBook.push_back(",test");
    orderBook.push_back("test,");
    orderBook.push_back("test,test");
    orderBook.push_back(",,test,,");

    for(const string& entry: orderBook)
    {
        vector<string> tokens = tokeniser.tokenise(entry, ',');
        for(const string& token: tokens)
        {
            cout << token << " ";
        }
        cout << endl;
    }

    {
        // OrderBookPrint(orderBook);
        // cout << "Average price: " << computeAveragePrice(orderBook) << endl;
        // cout << "Low price: " << computeLowPrice(orderBook) << endl;
        // cout << "High price: " << computeHighPrice(orderBook) << endl;
        // cout << "Price spread: " << computePriceSpread(orderBook) << endl;
    }
    
    return 0;
}