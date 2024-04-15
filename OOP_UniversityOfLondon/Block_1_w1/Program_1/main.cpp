#include <iostream>
#include <map>

using namespace std;

void printMenu()
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

int getUserChoice()
{
    int choice;
    cout << "Please enter a number: ";
    cin >> choice;
    cout << "\nYou entered: " << choice << endl;
    return choice;
}

void printHelp()
{
    cout << "Help - This is a simple exchange program" << endl;
}

void printExchangeStats()
{
    cout << "Exchange stats - No stats available" << endl;
}

void makeAnOffer()
{
    cout << "Make an offer - No offer available" << endl;
}

void makeABid()
{
    cout << "Make a bid - No bid available" << endl;
}

void printWallet()
{
    cout << "Print wallet - No wallet available" << endl;
}

void goNextTimeFrame()
{
    cout << "Continue - Continue the program" << endl;
}

void shutDown()
{
    cout << "Quit - Quit the program" << endl;
}

void printInvalidChoice()
{
    cout << "Invalid choice" << endl;
}

bool choiceProcess(int num)
{
    map<int, void (*)()> choiceMap;
    choiceMap[1] = printHelp;
    choiceMap[2] = printExchangeStats;
    choiceMap[3] = makeAnOffer;
    choiceMap[4] = makeABid;
    choiceMap[5] = printWallet;
    choiceMap[6] = goNextTimeFrame;
    choiceMap[7] = shutDown;

    switch (num)
    {
    case 1:
        choiceMap[1]();
        break;
    case 2:
        choiceMap[2]();
        break;
    case 3:
        choiceMap[3]();
        break;
    case 4:
        choiceMap[4]();
        break;
    case 5:
        choiceMap[5]();
        break;
    case 6:
        choiceMap[6]();
        break;
    case 7:
        choiceMap[7]();
        return true;
        break;
    default:
        printInvalidChoice();
        break;
    }

    return false;
}

int main() 
{
    bool quit = false;

    while (!quit)
    {
        printMenu();

        int choice = getUserChoice();

        quit = choiceProcess(choice);
    }

    return 0;
}