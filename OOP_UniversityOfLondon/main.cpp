#include <iostream>
#include <string>
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

int main() 
{
    // 2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02183269,4.89101735
    // Let's parse the string above and store the data to the variables
    string datastamp = "2020/03/17 17:01:24.884492";
    string pair = "ETH/BTC";
    string type = "bid";
    double price = 0.02183269;
    double amount = 4.89101735;

    bool quit = false;

    while (!quit)
    {
        printMenu();

        int choice = getUserChoice();

        quit = choiceProcess(choice);
    }

    return 0;
}