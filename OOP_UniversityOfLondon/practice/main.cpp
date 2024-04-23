#include <iostream>
#include <fstream>
#include <vector>

#include "tokeniser.h"
#include "avocado.h"

using namespace std;

void printAvocado(const vector<avocado> &avocados)
{
    for (const avocado &entry : avocados)
    {
        cout << entry << endl;
    }
}

int main()
{
    tokeniser tokenisator;
    vector<string> tokens;

    vector<avocado> avocados;

    ifstream avocadoFile("avocado.csv");
    string line;

    if (!avocadoFile.is_open())
    {
        cerr << "Error: File not found." << endl;
    }
    else
    {
        while (getline(avocadoFile, line))
        {
            tokens = tokenisator.tokenise(line, ',');

            //cout << "Number of tokens: " << tokens.size() << endl;

            if (tokens.size() != 14)
            {
                cerr << "Error: Invalid number of tokens." << endl;
                continue;
            }

            int index;
            int year;
            float average_price_of_a_single_avocado;
            float total_number_of_avocados_with_PLU_4046_sold;
            float total_number_of_avocados_with_PLU_4770_sold;
            float large_bags;
            float XLarge_bags;
            double total_number_of_avocados_sold;
            double total_number_of_avocados_with_PLU_4225_sold;
            double total_bags;
            double small_bags;
            std::string date_of_the_observation = tokens[1];
            std::string type = tokens[11];
            std::string region = tokens[13];
            try
            {
                index = stoi(tokens[0]);
                year = stoi(tokens[12]);
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error with integer conversion!" << '\n';
            }
            try
            {
                average_price_of_a_single_avocado = stof(tokens[2]);
                total_number_of_avocados_with_PLU_4046_sold = stof(tokens[4]);
                total_number_of_avocados_with_PLU_4770_sold = stof(tokens[6]);
                large_bags = stof(tokens[9]);
                XLarge_bags = stof(tokens[10]);
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error with float conversion!" << '\n';
            }
            try
            {
                total_number_of_avocados_sold = stod(tokens[3]);
                total_number_of_avocados_with_PLU_4225_sold = stod(tokens[5]);
                total_bags = stod(tokens[7]);
                small_bags = stod(tokens[8]);
            }
            catch(const std::exception& e)
            {
                std::cerr << "Error with double conversion!" << '\n';
            }

            avocados.push_back(avocado(index, date_of_the_observation, average_price_of_a_single_avocado, total_number_of_avocados_sold, total_number_of_avocados_with_PLU_4046_sold, total_number_of_avocados_with_PLU_4225_sold, total_number_of_avocados_with_PLU_4770_sold, total_bags, small_bags, large_bags, XLarge_bags, type, year, region));
        }
    }

    printAvocado(avocados);

    return 0;
}