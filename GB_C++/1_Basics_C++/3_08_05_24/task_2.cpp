#include <iostream>
#include <string>
#include <limits>

using namespace std;

class task_2
{
    public:
        void run()
        {
            int productCost {};
            int deliveryCost {};
            int discount {};

            std::cout << "Enter product cost: ";
            std::cin >> productCost;
            std::cout << "Enter delivery cost: ";
            std::cin >> deliveryCost;
            std::cout << "Enter discount: ";
            std::cin >> discount;
            std::cout << "---------\n";
            int price = productCost + deliveryCost - discount;
            std::cout << "Price: " << price << "\n";

            /** clean the input buffer from the previous input */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
};