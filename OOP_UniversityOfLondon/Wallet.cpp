#include "headers/Wallet.h"
#include "headers/CSVReader.h"

void Wallet::insertCurrency(std::string type, double amount) 
{
    double balance = 0;
    /** check amount non negative */
    if (amount < 0) throw std::exception{};
    if (currencies.count(type) == 0)
    {
        balance = 0;
    }
    else
    {
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;
}

bool Wallet::containsCurrency(std::string type, double amount) 
{
    if (currencies.count(type) == 0) return false;
    else return currencies[type] >= amount;
}

std::string Wallet::toString() {
    std::string result = "";
    for (const std::pair<std::string, double>& type : currencies) {
        result += type.first + ": " + std::to_string(type.second) + "\n";
    }
    return result;
}

bool Wallet::removeCurrency(std::string type, double amount) 
{
    if (amount < 0) return false;
    if (currencies.count(type) == 0) return false;
    if (containsCurrency(type, amount))
    {
        currencies[type] -= amount;
        return true;
    }
    else // there are currency but not enough
        return false;
}

bool Wallet::canFullfillOrder(OrderBookEntry order) 
{
    std::vector<std::string> currencies = CSVReader::tokeniser(order.getPair(), '/');

    if (order.getType() == OrderBookType::ask)
    {
        double amount = order.getAmount();
        std::string currency = currencies[0];
        std::cout << "Currency: " << currencies[0] << " Amount: " << amount << "\n";
        return containsCurrency(currency, amount);    
    }

    if (order.getType() == OrderBookType::bid)
    {
        double amount = order.getAmount() * order.getPrice();
        std::string currency = currencies[1];
        std::cout << "Currency: " << currencies[1] << " Amount: " << amount << "\n";
        return containsCurrency(currency, amount);
    }

    return false;
}