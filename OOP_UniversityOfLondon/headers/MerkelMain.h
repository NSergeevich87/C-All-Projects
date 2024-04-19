#pragma once

#include "OrderBookEntry.h"

class MerkelMain
{
    private:
        /** Vector of OrderBookEntry to save all orders*/
        std::vector<OrderBookEntry> orderBook;

    public:
        /** Default constructor */
        MerkelMain() = default;
        /** Default destructor */
        ~MerkelMain() = default;

        /** Run this to start the program */
        void run();

    private:
        /** This function load orders from csv file */
        void loadOrderBook();

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
};