#pragma once

#include "OrderBookEntry.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class CSVReader
{
    private:
        static std::vector<std::string> tokeniser(std::string line, char separator);
        static OrderBookEntry stringsToOBE(std::vector<std::string> tokens);

    public:
        CSVReader() = default;

        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
};