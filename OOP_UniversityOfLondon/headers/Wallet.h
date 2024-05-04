#pragma once

#include <map>
#include <string>
#include "OrderBookEntry.h"

class Wallet
{
    friend std::ostream& operator<<(std::ostream& os, Wallet& wallet)
    {
        os << wallet.toString();
        return os;
    }

    public:
        Wallet() = default;
        /** insert currency to the wallet */
        void insertCurrency(std::string type, double amount);
        /** remove currency from the wallet */
        bool removeCurrency(std::string type, double amount);

        /** check if the wallet contains this much currency or more */
        bool containsCurrency(std::string type, double amount);
        /** check if can fullfill order */
        bool canFullfillOrder(OrderBookEntry order);

        /** generate a string representation of the wallet */
        std::string toString();

    private:
        std::map<std::string, double> currencies;
};