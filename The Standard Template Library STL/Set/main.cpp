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
        
        bool operator<(const Person &rhs) { return this->age < rhs.age; }
        bool operator==(const Person &rhs) { return (this->name == rhs.name && this->age == rhs.age); }
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
}

void test2()
{
    std::cout << "\nTest2===================================" << std::endl;
}

void test3()
{
    std::cout << "\nTest3===================================" << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    
    return 0;
}