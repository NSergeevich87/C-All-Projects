#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <limits>

#include "headers/MerkelMain.h"
#include "headers/CSVReader.h"

using namespace std;

void MerkelMain::run()
{
    bool quit = false;
    /** for test */
    wallet.insertCurrency("BTC", 10);
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
    cout << "3: Make ASK" << endl;
    cout << "4: Make BID" << endl;
    cout << "5: Print wallet" << endl;
    cout << "6: Continue" << endl;
    cout << "7: Print changing stats" << endl;
    cout << "8: Quit" << endl;
    cout << setw(40) << setfill('=') << "" << endl;
    cout << setw(10) << right << "Current Time: " << currentTime << "\n";
}

int MerkelMain::getUserChoice()
{
    int choice = 0;
    string input;

    cout << "Please enter a number: ";
    getline(cin, input);

    try
    {
        choice = stoi(input);
    }
    catch(const std::exception& e)
    {
        //
    }

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

void MerkelMain::makeAsk()
{
    string input;

    cout << "Make ASK - enter like this: BTC/USDT,5406,0.0136" << endl;
    
    /** clean the input buffer from the previous input */
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, input);

    std::vector<std::string> parts = CSVReader::tokeniser(input, ',');
    if (parts.size() != 3)
    {
        cout << "MerkelMain::makeAsk() -> Bad input" << endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                currentTime, parts[0], OrderBookType::ask, parts[1], parts[2]);
            obe.setUsername("simuser");

            if (wallet.canFullfillOrder(obe))
            {
                cout << "You have enough money to make this order" << endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                cout << "You don't have enough money to make this order" << endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "MerkelMain::makeAsk() -> Bad input!" << '\n';
        }
    }

    cout << "You entered: " << input << endl;
}

void MerkelMain::makeBid()
{
    cout << "Make BID - enter like this: BTC/USDT,5406,0.0136" << endl;
    string input;
    getline(cin, input);

    std::vector<std::string> parts = CSVReader::tokeniser(input, ',');
    if (parts.size() != 3)
    {
        cout << "MerkelMain::makeBid() -> Bad input!" << endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                currentTime, parts[0], OrderBookType::bid, parts[1], parts[2]);
            obe.setUsername("simuser");

            if (wallet.canFullfillOrder(obe))
            {
                cout << "You have enough money to make this order" << endl;
                orderBook.insertOrder(obe);
            }
            else
            {
                cout << "You don't have enough money to make this order" << endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "MerkelMain::makeBid() -> Bad input!" << '\n';
        }
    }

    cout << "You entered: " << input << endl;
}

void MerkelMain::printWallet()
{
    cout << wallet << endl;
}

void MerkelMain::goNextTimeFrame()
{
    cout << "Going to next time frame\n";

    /** test matching algorithm */
    for (const string& product : orderBook.getKnownProducts())
    {
        vector<OrderBookEntry> transactions = orderBook.matchAsksToBids(currentTime, product);
        cout << "Product: " << product << " All sails: " << transactions.size() << endl;
        for (const OrderBookEntry& obe : transactions)
        {
            cout << "Sale pair: " << obe.getPair() << " Sale amoount: " << obe.getAmount() << " Price: " << obe.getPrice() << endl;
        }
    }

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
    choiceMap[3] = &MerkelMain::makeAsk;
    choiceMap[4] = &MerkelMain::makeBid;
    choiceMap[5] = &MerkelMain::printWallet;
    choiceMap[6] = &MerkelMain::goNextTimeFrame;
    choiceMap[7] = &MerkelMain::changingValueAndPercentageForAsks;
    choiceMap[8] = &MerkelMain::shutDown;

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
        break;
    case 8:
        (this->*choiceMap[8])();
        return true;
        break;
    default:
        printInvalidChoice();
        break;
    }

    return false;
}

/** exercise for weekly assessment */
void MerkelMain::changingValueAndPercentageForAsks()
{
    cout << "Minimal and Maximum values until current time: \n";

    orderBook.changingValueAndPercentageForAsks(currentTime); 
}
