#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//#include "vector3D.h"

std::vector<std::string> tokenise(std::string line, char separator)
{
    std::vector<std::string> tokens;
    std::string token;
    signed int start, end;
    do
    {
        start = line.find_first_not_of(separator);
        if (start != std::string::npos)
        {
            end = line.find_first_of(separator, start);
            if (end == std::string::npos)
            {
                end = line.size();
            }
            token = line.substr(start, end - start);
            tokens.push_back(token);
            line = line.substr(end);
        }
    } while (start != std::string::npos);
    
    return tokens;
}

int main()
{
    std::cout << "Hello to my tokenise program!\n";

    std::vector<std::string> vectorStrings;

    for (std::string line : vectorStrings)
    {
        std::vector<std::string> tokens = tokenise(line, ',');
        for (std::string token : tokens)
        {
            std::cout << token << std::endl;
        }
    }

    //vector3D v1(25.5, 30.5, 35.5);
    //std::cout << "The norm of the vector is: " << v1.norm() << std::endl;

    std::ifstream dataCSVfile{"test.csv"};

    if (dataCSVfile.is_open())
    {
        std::cout << "File opened successfully\n";
        std::string line;

        while (std::getline(dataCSVfile, line))
        {
            std::vector<std::string> tokens = tokenise(line, ',');
            if (tokens.size() != 5)
            {
                std::cout << "Error of line: " << line << std::endl;
                continue;
            }

            try
            {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << "Price: " << price << " Amount: " << amount << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << "Bad double number! " << tokens[3] << '\n';
                std::cerr << "Bad double number! " << tokens[4] << '\n';
            }
            
            
        }

        dataCSVfile.close();
    }
    else
    {
        std::cout << "Error opening file\n";
    }

    return 0;
}