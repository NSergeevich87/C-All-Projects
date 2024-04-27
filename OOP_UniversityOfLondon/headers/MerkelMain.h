#pragma once

#include "OrderBook.h"

class MerkelMain
{
    private:
        OrderBook orderBook{"20200317.csv"};
        std::string currentTime;

    public:
        /** Default constructor */
        MerkelMain() = default;
        /** Default destructor */
        ~MerkelMain() = default;

        /** Run this to start the program */
        void run();

    private:
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