#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "headers/MerkelMain.h"
#include "headers/OrderBookEntry.h"

using namespace std;

void MerkelMain::run()
{
    loadOrderBook();

    bool quit = false;

    while (!quit)
    {
        printMenu();

        int choice = getUserChoice();

        quit = choiceProcess(choice);
    }
}

void MerkelMain::loadOrderBook()
{
    orderBook.push_back(OrderBookEntry(
        "2020/03/17 17:01:24.884492", 
        "ETH/RTM", 
        OrderBookType::BID, 
        0.02183269, 
        4.89101735
    ));

    orderBook.push_back(OrderBookEntry(
        "2020/03/17 17:01:24.884492", 
        "ETH/RTM", 
        OrderBookType::BID, 
        0.02183264, 
        3.9101735
    ));

    orderBook.push_back(OrderBookEntry(
        "2020/03/17 17:01:24.884492", 
        "ETH/RTM", 
        OrderBookType::ASK, 
        0.02196165, 
        0.00630238
    ));

    orderBook.push_back(OrderBookEntry(
        "2020/03/17 17:01:24.884492", 
        "ETH/RTM", 
        OrderBookType::ASK, 
        0.02227042, 
        37.7
    ));

    orderBook.push_back(OrderBookEntry(
        "2020/03/17 17:01:24.884492", 
        "RTM/BTC", 
        OrderBookType::BID, 
        0.03, 
        3.9101735
    ));
}

void MerkelMain::printMenu()
{
    cout << "====================================" << endl;
    cout << "1: Print help" << endl;
    cout << "2: Print exchange stats" << endl;
    cout << "3: Make an offer" << endl;
    cout << "4: Make a bid" << endl;
    cout << "5: Print wallet" << endl;
    cout << "6: Continue" << endl;
    cout << "7: Quit" << endl;
    cout << "====================================" << endl;
}

int MerkelMain::getUserChoice()
{
    int choice;
    cout << "Please enter a number: ";
    cin >> choice;
    cout << "\nYou entered: " << choice << endl;
    return choice;
}

void MerkelMain::printHelp()
{
    cout << "Help - This is a simple exchange program" << endl;
}

void MerkelMain::printExchangeStats()
{
    cout << "Exchange stats - Order Book has: " << orderBook.size() << " entries." << endl;
}

void MerkelMain::makeAnOffer()
{
    cout << "Make an offer - No offer available" << endl;
}

void MerkelMain::makeABid()
{
    cout << "Make a bid - No bid available" << endl;
}

void MerkelMain::printWallet()
{
    cout << "Print wallet - No wallet available" << endl;
}

void MerkelMain::goNextTimeFrame()
{
    cout << "Continue - Continue the program" << endl;
}

void MerkelMain::shutDown()
{
    cout << "Quit - Quit the program" << endl;
}

void MerkelMain::printInvalidChoice()
{
    cout << "Invalid choice" << endl;
}

bool MerkelMain::choiceProcess(int num)
{
    std::map<int, void (MerkelMain::*)()> choiceMap;
    
    choiceMap[1] = &MerkelMain::printHelp;
    choiceMap[2] = &MerkelMain::printExchangeStats;
    choiceMap[3] = &MerkelMain::makeAnOffer;
    choiceMap[4] = &MerkelMain::makeABid;
    choiceMap[5] = &MerkelMain::printWallet;
    choiceMap[6] = &MerkelMain::goNextTimeFrame;
    choiceMap[7] = &MerkelMain::shutDown;

    switch (num)
    {
    case 1:
        (this->*choiceMap[1])();
        break;
    case 2:
        (this->*choiceMap[2])();
        break;
    case 3:
        (this->*choiceMap[3])();
        break;
    case 4:
        (this->*choiceMap[4])();
        break;
    case 5:
        (this->*choiceMap[5])();
        break;
    case 6:
        (this->*choiceMap[6])();
        break;
    case 7:
        (this->*choiceMap[7])();
        return true;
        break;
    default:
        printInvalidChoice();
        break;
    }

    return false;
}