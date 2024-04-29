#pragma once

#include "OrderBookEntry.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class CSVReader
{
    private:
        static OrderBookEntry stringsToOBE(std::vector<std::string> tokens);

    public:
        CSVReader() = default;

        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
        static std::vector<std::string> tokeniser(std::string line, char separator);
        static OrderBookEntry stringsToOBE(
            std::string timestamp, 
            std::string pair, 
            OrderBookType type, 
            std::string price, 
            std::string amount
        );
};