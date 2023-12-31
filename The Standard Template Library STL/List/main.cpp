#include <iostream>
#include <list>
#include <iterator>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name{};
    int age{};
    
    public:
        Person() : name{"Default"}, age{0} {}
        Person(std::string name_v, int age_v) : name{name_v}, age{age_v} {}
        
        bool operator<(const Person &rhs)
        {
            return this->age < rhs.age;
        }
        
        bool operator==(const Person &rhs)
        {
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "Name: " << p.name << " age: " << p.age;
    return os;
}

template<typename T>
void display(const std::list<T> &l)
{
    std::cout << "[ ";
    for(const auto &i : l)
    {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    
    return 0;
}