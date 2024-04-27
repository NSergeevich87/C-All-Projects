#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

#include "headers/MerkelMain.h"
#include "headers/CSVReader.h"

using namespace std;

void MerkelMain::run()
{
    bool quit = false;

    currentTime = orderBook.getEarliestTime();

    while (!quit)
    {
        printMenu();

        int choice = getUserChoice();

        quit = choiceProcess(choice);
    }
}

void MerkelMain::printMenu()
{
    cout << setw(40) << setfill('=') << "" << endl;
    cout << "1: Print help" << endl;
    cout << "2: Print exchange stats" << endl;
    cout << "3: Make an offer" << endl;
    cout << "4: Make a bid" << endl;
    cout << "5: Print wallet" << endl;
    cout << "6: Continue" << endl;
    cout << "7: Quit" << endl;
    cout << setw(40) << setfill('=') << "" << endl;
    cout << setw(10) << right << "Current Time: " << currentTime << "\n";
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
    cout << "Exchange stats: " << "\n";
    for (const string& product : orderBook.getKnownProducts())
    {
        cout << "\n" << setfill(' ') << "Product: " << setw(31) << product << "\n" << endl;
        
        /** first we need to check existing of products with current time */
        if (!orderBook.checkProductExists(currentTime, product))
        {
            cout << "No data available for this product at this time" << endl;
            continue;
        }

        std::vector<OrderBookEntry> orders = orderBook.getOrders(
            currentTime,
            product,
            OrderBookType::ask);
        cout << "Asks Orders: " << setw(27) << right << setfill('_') << orders.size() << "\n";
        cout << "Asks High price: " << setw(23) << right << setfill('_') << OrderBook::getHighPrice(orders) << "\n";
        cout << "Asks Low price: " << setw(24) << right << setfill('_') << OrderBook::getLowPrice(orders) << "\n";
        cout << "Asks Spread: " << setw(27) << right << setfill('_') << OrderBook::getSpread(OrderBook::getHighPrice(orders), OrderBook::getLowPrice(orders)) << "\n";  
    }
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
    cout << "Going to next time frame\n";
    currentTime = orderBook.getNextTime(currentTime);
    cout << "Current Time: " << currentTime << endl;
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