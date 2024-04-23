#include <iostream>
#include <string>

class avocado
{
    friend std::ostream& operator<<(std::ostream& os, const avocado& a);

    private:
        int index;
        std::string date_of_the_observation;
        float average_price_of_a_single_avocado;
        double total_number_of_avocados_sold;
        float total_number_of_avocados_with_PLU_4046_sold;
        double total_number_of_avocados_with_PLU_4225_sold;
        float total_number_of_avocados_with_PLU_4770_sold;
        double total_bags;
        double small_bags;
        float large_bags;
        float XLarge_bags;
        std::string type;
        int year;
        std::string region;

    public:
        avocado() = default;
        avocado(int index, std::string date_of_the_observation, float average_price_of_a_single_avocado, double total_number_of_avocados_sold, float total_number_of_avocados_with_PLU_4046_sold, double total_number_of_avocados_with_PLU_4225_sold, float total_number_of_avocados_with_PLU_4770_sold, double total_bags, double small_bags, float large_bags, float XLarge_bags, std::string type, int year, std::string region);
        ~avocado() = default;
};