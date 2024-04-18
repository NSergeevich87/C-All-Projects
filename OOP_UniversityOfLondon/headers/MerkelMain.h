

class MerkelMain
{
    public:
        MerkelMain();
        ~MerkelMain();

        void run();

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