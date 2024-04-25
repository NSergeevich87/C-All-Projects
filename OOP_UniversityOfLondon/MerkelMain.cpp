#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "headers/MerkelMain.h"
#include "headers/OrderBookEntry.h"
#include "headers/CSVReader.h"

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
    orderBook = CSVReader::readCSV("20200317.csv");
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
    int bid = 0;
    int ask = 0;

    for (OrderBookEntry &entry : orderBook)
    {
        if (entry.getType() == OrderBookType::bid)
        {
            bid++;
        }
        
        if (entry.getType() == OrderBookType::ask)
        {
            ask++;
        }
    }

    cout << "Order book entries: " << orderBook.size() << " Bids: " << bid << " Asks: " << ask << endl;
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