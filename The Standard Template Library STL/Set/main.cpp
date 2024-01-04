#include <iostream>
#include <string>
#include <set>
#include <list>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name{};
    int age{};
    
    public:
        Person() : name{"No_name"}, age{0} {}
        Person(std::string name_val, int age_val) : name{name_val}, age{age_val} {}
        
        bool operator<(const Person &rhs) const { return this->age < rhs.age; }
        bool operator==(const Person &rhs) const { return (this->name == rhs.name && this->age == rhs.age); }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << " " << p.age;
    return os;
}

template<typename T>
void display(const std::set<T> &p)
{
    std::cout << "[ ";
    for(const auto &elem: p)
    {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\nTest1===================================" << std::endl;
    
    std::set<int> nums { 1, 5, 4, 2, 6, 8 };
    display(nums);
    
    nums = { 1, 1, 5, 5, 4, 4,  2, 2, 6, 6, 8, 8 };
    display(nums);
    
    nums.insert(0);
    nums.insert(10);
    display(nums);
    
    if (nums.count(10)) std::cout << "We found 10" << std::endl;
    else std::cout << "We NOT found 10" << std::endl;
    
    std::set<int>::iterator it = nums.find(5);
    if(it != nums.end()) { std::cout << *it << std::endl; }
    
    nums.clear();
    display(nums);
    
    if(nums.empty()) std::cout << "Nums is Empty" << std::endl;
    else std::cout << "Nums is NOT Empty" << std::endl; 
}

void test2()
{
    std::cout << "\nTest2===================================" << std::endl;
    
    std::set<Person> persons
    {
        {"Nick", 36},
        {"Daniil", 21},
        {"Ksy", 34 }
    };
    
    display(persons);
    
    persons.emplace("Dirk", 32);
    display(persons);
    
    persons.emplace("Krid", 32); // NO -- 32 already exists
    display(persons);
    
   // std::set<Person>::iterator it = persons.find(Person{"Dirk", 32});
   // if (it != persons.end()) persons.erase(it);
   // display(persons);
    
    auto it = persons.find(Person{"XXXX", 32}); // will remove Dirk tambien, because uses operator<
    if (it != persons.end()) persons.erase(it);
    display(persons);
}

void test3()
{
    std::cout << "\nTest3===================================" << std::endl;
    
    std::set<std::string> s { "q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m" }; // ordered
    display(s);
    
    std::cout << std::boolalpha;
    auto result = s.emplace("A");
    display(s);
    std::cout << *(result.first) << std::endl;
    std::cout << result.second << std::endl; // true - до этого А не было
    
    result = s.emplace("A");
    display(s);
    std::cout << *(result.first) << std::endl;
    std::cout << result.second << std::endl; // false - тк А уже есть
    
    std::cout << s.size() << std::endl;
    std::cout << s.max_size() << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    
    return 0;
}