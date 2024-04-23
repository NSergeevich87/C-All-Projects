#include "headers/CSVReader.h"

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile)
{
    std::vector<OrderBookEntry> entries;
    std::ifstream file_csv(csvFile);
    std::string line;

    if (!file_csv.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
    }
    else
    {
        std::cout << "File opened successfully" << std::endl;
        while(std::getline(file_csv, line))
        {
            std::vector<std::string> tokens = tokeniser(line, ',');
            OrderBookEntry obe = stringsToOBE(tokens);
            entries.push_back(obe);
        }
    }

    file_csv.close();

    return entries;
}

std::vector<std::string> CSVReader::tokeniser(std::string line, char separator)
{
    std::string temp_line = line;

    std::vector<std::string> tokens;
    std::string token;
    signed start, end {0};
    
    do
    {
        start = temp_line.find_first_not_of(separator);
        if (start != std::string::npos)
        {
            end = temp_line.find_first_of(separator, start);
            if (end == std::string::npos)
            {
                end = temp_line.length();
            }
            token = temp_line.substr(start, end - start);
            tokens.push_back(token);
            temp_line = temp_line.substr(end);
        }
    } while (start != std::string::npos);

    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    if (tokens.size() != 5)
    {
        return OrderBookEntry{"","",OrderBookType::UNKNOWN,0,0};
    }

    std::string timestamp = tokens[0];
    std::string pair = tokens[1];
    OrderBookType type = tokens[2] == "BID" ? OrderBookType::BID : OrderBookType::ASK;
    double price;
    double amount;
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error with double conversion!" << '\n';
    }

    return OrderBookEntry{timestamp, pair, type, price, amount};
}