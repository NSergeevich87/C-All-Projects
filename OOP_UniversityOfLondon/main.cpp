#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void printMenu();

int getUserChoice();

void printHelp();

void printExchangeStats();

void makeAnOffer();

void makeABid();

void printWallet();

void goNextTimeFrame();

void shutDown();

void printInvalidChoice();

bool choiceProcess(int num);

enum class OrderBookType
{
    BID,
    ASK
};

ostream &operator<<(ostream &os, const OrderBookType &type)
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

class OrderBookEntry
{
    private:
        string timestamp;
        string pair;
        OrderBookType type;
        double price;
        double amount;
    
    public:
        OrderBookEntry(string timestamp_val, string pair_val, OrderBookType type_val, double price_val, double amount_val)
            : timestamp(timestamp_val), pair(pair_val), type(type_val), price(price_val), amount(amount_val) {}

        ~OrderBookEntry() {}

        string getTimestamp() const
        {
            return timestamp;
        }

        string getPair() const
        {
            return pair;
        }

        OrderBookType getType() const
        {
            return type;
        }

        double getPrice() const
        {
            return price;
        }

        double getAmount() const
        {
            return amount;
        }

        friend ostream &operator<<(ostream &os, const OrderBookEntry &entry)
        {
            os << entry.timestamp << "," << entry.pair << "," << entry.type << "," << entry.price << "," << entry.amount;
            return os;
        }
};

void OrderBookPrint(const vector<OrderBookEntry> &orderBook)
{
    for (const OrderBookEntry &entry : orderBook)
    {
        cout << entry << endl;
    }
}

int main() 
{
    // 2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02183269,4.89101735
    // Let's parse the string above and store the data to the variables
    // string datastamp = "2020/03/17 17:01:24.884492";
    // string pair = "ETH/BTC";
    // string type = "bid";
    // double price = 0.02183269;
    // double amount = 4.89101735;

    // bool quit = false;

    // while (!quit)
    // {
    //     printMenu();

    //     int choice = getUserChoice();

    //     quit = choiceProcess(choice);
    // }

    std::vector<OrderBookEntry> orderBook;

    orderBook.push_back(OrderBookEntry(
        "2020/03/17 17:01:24.884492", 
        "ETH/RTM", 
        OrderBookType::BID, 
        0.02183269, 
        4.89101735
    ));

    orderBook.push_back(OrderBookEntry(
        "2020/03/17 18:31:44.884492", 
        "RTM/BTC", 
        OrderBookType::ASK, 
        2183269, 
        3.9101735
    ));

    OrderBookPrint(orderBook);

    return 0;
}