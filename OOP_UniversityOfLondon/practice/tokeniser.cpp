#include "tokeniser.h"
#include <string>

std::vector<std::string> tokeniser::tokenise(const std::string line, const char delimiter)
{
    std::string input_temp = line;
    std::vector<std::string> tokens;
    std::string token;
    signed int start, end{0};
    do
    {
        start = input_temp.find_first_not_of(delimiter);
        if (start != std::string::npos)
        {
            end = input_temp.find_first_of(delimiter, start);
            if (end == std::string::npos)
            {
                end = input_temp.length();
            }
            token = input_temp.substr(start, end - start);
            tokens.push_back(token);
            input_temp = input_temp.substr(end);
        }
    } while (start != std::string::npos);
    
    return tokens;
}