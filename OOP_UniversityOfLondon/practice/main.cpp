#include <iostream>
#include <string>
#include <vector>

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
    vectorStrings.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187307,3.467434");
    vectorStrings.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187305,6.85567013");
    vectorStrings.push_back("2020/03/17 17:01:24.884492,ETH/BTC,bid,0.021873,1.");

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

    return 0;
}