#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

int main()
{
    std::string name{};
    int number{};
    double total{};
    
    std::string info {"Nick 100 123.321"};
    std::istringstream iss{info};
    
    iss >> name >> number >> total;
    std::cout << std::setw(15) << std::left << name
              << std::setw(5) << number
              << std::setw(10) << total << std::endl;
              
    std::cout << "\n--------------------------------------------" << std::endl;
    
    std::ostringstream oss{};
    oss << std::setw(15) << std::left << name
        << std::setw(5) << number
        << std::setw(10) << total << std::endl;
    
    std::cout << oss.str() << std::endl;
    
    std::cout << "\n---Data Validation--------------------------" << std::endl;
    
    int value{};
    std::string data_entered{};
    bool done = false;
    
    do
    {
        std::cout << "Enter a number: ";
        std::cin >> data_entered;
        
        std::istringstream iss{data_entered};
        if(iss >> value)
        {
            done = true;
        }
        else
        {
            std::cout << "Sorry that's not an integer" << std::endl;
        }
        
        // Discards the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (!done);
    
    std::cout << "You entered number: " << value << std::endl;
    
    return 0;
}