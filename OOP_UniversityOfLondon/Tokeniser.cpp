#include "headers/Tokeniser.h"

std::vector<std::string> Tokeniser::tokenise(
    const std::string& input, 
    const char separator
    )
{
    std::string input_temp = input;
    std::vector<std::string> tokens;
    std::string token;
    signed int start, end{0};
    do
    {
        start = input_temp.find_first_not_of(separator);
        if (start != std::string::npos)
        {
            end = input_temp.find_first_of(separator, start);
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