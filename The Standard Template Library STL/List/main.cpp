#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

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
    os << "Name: " << p.name << " age: " << p.age << ";";
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

void test1()
{
    std::cout << "\nTest1====================================" << std::endl;
    
    std::list<int> l1 { 1, 2, 3, 4, 5 };
    display(l1);
    
    std::list<std::string> l2 {};
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);
    
    std::list<int> l3 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display(l3);
    
    std::list<int> l4 (10, 100);
    display(l4);
}

void test2()
{
    std::cout << "\nTest2====================================" << std::endl;
    
    std::list<int> l { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display(l);
    
    std::cout << l.size() << std::endl;
    std::cout << l.front() << std::endl;
    std::cout << l.back() << std::endl;
    
    l.clear();
    display(l);
    std::cout << l.size() << std::endl;
}

void test3()
{
    std::cout << "\nTest3====================================" << std::endl;
    
    std::list<int> l { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display(l);
    
    l.resize(5);
    display(l);
    
    l.resize(10);
    display(l);
    
    std::list<Person> p;
    display(p);
    
    p.resize(5);
    display(p);
}

void test4()
{
    std::cout << "\nTest4====================================" << std::endl;
    
    std::list<int> l { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display(l);
    
    std::list<int>::iterator it = std::find(l.begin(), l.end(), 5);
    if(it != l.end())
    {
        l.insert(it, 100);
    }
    display(l);
    
    std::list<int> l2 { 2000, 3000, 4000 };
    l.insert(it, l2.begin(), l2.end());
    display(l);
    
    std::advance(it, -4);
    std::cout << *it << std::endl; 
    l.erase(it);
    display(l);
}

void test5()
{
    std::cout << "\nTest5====================================" << std::endl;
    
    std::list<Person> stooges
    {
        {"Nick", 36},
        {"Ksy", 34},
        {"Daniil", 21}
    };
    display(stooges);
    
    std::string name{};
    int age{};
    std::cout << "\nEnter a new person: ";
    std::getline(std::cin, name);
    std::cout << "\nEnter age: ";
    std::cin >> age;
    
    stooges.emplace_back(name, age);
    display(stooges);
    
    std::list<Person>::iterator it = std::find(stooges.begin(), stooges.end(), Person{"Daniil", 21});
    if(it != stooges.end())
    {
        stooges.emplace(it, "Padre", 62);
    }
    display(stooges);
}

void test6()
{
    std::cout << "\nTest6====================================" << std::endl;
    
    std::list<Person> stooges
    {
        {"Nick", 36},
        {"Ksy", 34},
        {"Daniil", 21}        
    };
    display(stooges);
    
    stooges.sort();
    display(stooges);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    
    return 0;
}