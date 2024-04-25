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
            try
            {
                //std::vector<std::string> tokens = tokeniser(line, ',');
                OrderBookEntry obe = stringsToOBE(tokeniser(line, ','));
                entries.push_back(obe);
            }
            catch(const std::exception& e)
            {
                std::cout << "CSVReader::readCSV() - bad data" << '\n';
            }
        }
    }

    file_csv.close();

    std::cout << "CSVReader::readCSV() - " << entries.size() << " entries read from file\n";
    return entries;
}

std::vector<std::string> CSVReader::tokeniser(std::string line, char separator)
{
    std::vector<std::string> tokens;
    std::string token;
    signed int start, end {0};

    start = line.find_first_not_of(separator, 0);
    do
    {
        end = line.find_first_of(separator, start);
        if (start == line.length() || start == end) break;
        if (end >= 0) token = line.substr(start, end - start);
        else token = line.substr(start, line.length() - start);
        
        tokens.push_back(token);
        start = end + 1;
    } while (end > 0);

    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    if (tokens.size() != 5)
    {
        std::cout << "Bad line !" << std::endl;
        throw std::exception{};
    }  

    //OrderBookType type = tokens[2] == "BID" ? OrderBookType::BID : OrderBookType::ASK;
    double price, amount {0};
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error with double conversion!" << '\n';
        throw;
    }

    return OrderBookEntry{tokens[0], tokens[1], OrderBookEntry::stringToOrderBookType(tokens[2]), price, amount};
}