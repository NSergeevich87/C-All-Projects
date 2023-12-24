#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Item
{
    private:
        std::string name{};
        T value{};
        
    public:
        Item(std::string name_val, T value_val) : name{name_val}, value{value_val}
        {}
        std::string get_name() const { return name; }
        T get_value() const { return value; }
        void print() const { std::cout << name << " " << value << std::endl; }
        ~Item(){};
};

template <typename T1, typename T2>
struct my_pairs
{
    T1 first;
    T2 second;
};

int main()
{
    Item<int> item1 {"Nick", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;
    item1.print();
    
    Item<std::string> item2 {"Nick", "Programmer"};
    item2.print();
    
    Item<Item<std::string>> item3 {"Nick", {"C++", "Programmer"}};
    std::cout << item3.get_name() << " "
              << item3.get_value().get_name() << " "
              << item3.get_value().get_value() << std::endl;
              
    std::cout << "\n=============================================" << std::endl;
    
    std::vector<Item<std::string>> vec{};
    vec.push_back (Item<std::string>("nikita", "nikiforov"));
    vec.push_back (Item<std::string>("kseniia", "volkova"));
    vec.push_back (Item<std::string>("sergey", "leybman"));
    
    for(const auto &v : vec)
    {
        v.print();
    }
    
    std::cout << "\n=============================================" << std::endl;
    
    my_pairs<std::string, int> p1 {"Nick", 36};
    my_pairs<int, double> p2 {33, 6.645};
    
    std::cout << p1.first << " " << p1.second << std::endl;
    std::cout << p2.first << " " << p2.second << std::endl;
    
    return 0;
}