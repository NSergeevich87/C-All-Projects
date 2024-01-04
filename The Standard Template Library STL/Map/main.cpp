#include <iostream>
#include <set>
#include <map>

void display(const std::map<std::string, std::set<int>> &m)
{
    std::cout << "[ ";
    for(const auto &elem : m)
    {
        std::cout << elem.first << ": [ ";
        for(const auto &set_elem : elem.second)
        {
            std::cout << set_elem << " ";
        }
        std::cout << "] ";
    }
    std::cout << "] " << std::endl;
}

template<typename T1, typename T2>
void display(const std::map<T1, T2> &m)
{
    std::cout << "[ ";
    for(const auto &elem: m)
    {
        std::cout << elem.first << ":" << elem.second << " ";
    }
    std::cout << "] " << std::endl;
}

void test1()
{
    std::cout << "\nTest1============================" << std::endl;
    
    std::map<std::string, int> persons
    {
        {"Larry", 3},
        {"Curly", 2},
        {"Moe", 1}
    };
    display(persons);
    
    persons.insert(std::pair<std::string, int>("Anna", 10));
    display(persons);
    
    persons.insert(std::make_pair("Joe", 5));
    display(persons);
    
    persons["Frank"] = 18;
    display(persons);
    
    persons["Frank"] += 10;
    display(persons);

    persons.erase("Frank");
    display(persons);

    std::cout << "Count for Joe: " << persons.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << persons.count("Frank") << std::endl;
    
    std::map<std::string, int>::iterator it = persons.find("Larry");
    if(it != persons.end()) std::cout << "Found: " << it->first << " " << it->second << std::endl;
    
    persons.clear();
    display(persons);
    
    std::cout << persons.empty() << std::endl;
}

void test2()
{
    std::cout << "\nTest2============================" << std::endl;
    
    std::map<std::string, std::set<int>> grades
    {
        {"Nick", { 43, 5, 46, 99, 8 }},
        {"Ksy", { 98, 7, 65, 4, 56 }},
        {"Daniil", { 4, 567, 876 }}
    };
    display(grades);
    
    grades["Dirk"] = { 7, 564, 65, 76 };
    display(grades);
    
    grades["Daniil"].insert(999);
    display(grades);
    
    std::map<std::string, std::set<int>>::iterator it = grades.find("Nick");
    if(it != end(grades)) it->second.insert(777);
    display(grades);
    
    grades.insert(std::pair<std::string, std::set<int>>("Miguel", { 90, 8, 7 }));
    display(grades);
}

int main()
{
    test1();
    test2();
    
    return 0;
}