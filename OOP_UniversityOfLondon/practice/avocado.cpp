#include "avocado.h"

avocado::avocado(int index, std::string date_of_the_observation, float average_price_of_a_single_avocado, double total_number_of_avocados_sold, float total_number_of_avocados_with_PLU_4046_sold, double total_number_of_avocados_with_PLU_4225_sold, float total_number_of_avocados_with_PLU_4770_sold, double total_bags, double small_bags, float large_bags, float XLarge_bags, std::string type, int year, std::string region)
    : index(index), date_of_the_observation(date_of_the_observation), average_price_of_a_single_avocado(average_price_of_a_single_avocado), total_number_of_avocados_sold(total_number_of_avocados_sold), total_number_of_avocados_with_PLU_4046_sold(total_number_of_avocados_with_PLU_4046_sold), total_number_of_avocados_with_PLU_4225_sold(total_number_of_avocados_with_PLU_4225_sold), total_number_of_avocados_with_PLU_4770_sold(total_number_of_avocados_with_PLU_4770_sold), total_bags(total_bags), small_bags(small_bags), large_bags(large_bags), XLarge_bags(XLarge_bags), type(type), year(year), region(region)
{
}

std::ostream &operator<<(std::ostream &os, const avocado &a)
{
    os << "Index: " << a.index << std::endl;
    os << "Date of the observation: " << a.date_of_the_observation << std::endl;
    os << "Average price of a single avocado: " << a.average_price_of_a_single_avocado << std::endl;
    os << "Total number of avocados sold: " << a.total_number_of_avocados_sold << std::endl;
    os << "Total number of avocados with PLU 4046 sold: " << a.total_number_of_avocados_with_PLU_4046_sold << std::endl;
    os << "Total number of avocados with PLU 4225 sold: " << a.total_number_of_avocados_with_PLU_4225_sold << std::endl;
    os << "Total number of avocados with PLU 4770 sold: " << a.total_number_of_avocados_with_PLU_4770_sold << std::endl;
    os << "Total bags: " << a.total_bags << std::endl;
    os << "Small bags: " << a.small_bags << std::endl;
    os << "Large bags: " << a.large_bags << std::endl;
    os << "XLarge bags: " << a.XLarge_bags << std::endl;
    os << "Type: " << a.type << std::endl;
    os << "Year: " << a.year << std::endl;
    os << "Region: " << a.region << std::endl;

    return os;
}