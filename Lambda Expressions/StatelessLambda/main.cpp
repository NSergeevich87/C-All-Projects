// Stateless lambda expressions
// [] - empty capture list

#include <iostream>
#include <string>
#include <vector>
#include <functional> // for std::function
#include <algorithm>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    
    private:
        std::string name{};
        int age{};
    
    public:
        Person(std::string name_val, int age_val) : name{name_val}, age{age_val} {}
        Person(const Person &p) : name{p.name}, age{p.age} {}
        ~Person() = default;
        
        std::string get_name() const { return name; }
        void set_name(std::string name) { this->name = name; }
        int get_age() const { return age; }
        void set_age(int age) { this->age = age; }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "[Person: " << p.name << " : " << p.age << "]";
    return os;
}

void test1()
{
    std::cout << "\nTest1======================================" << std::endl;
}

void test2()
{
    std::cout << "\nTest2======================================" << std::endl;
}

void test3()
{
    std::cout << "\nTest3======================================" << std::endl;
}

void test4()
{
    std::cout << "\nTest4======================================" << std::endl;
}

void test5()
{
    std::cout << "\nTest5======================================" << std::endl;
}

void test6()
{
    std::cout << "\nTest6======================================" << std::endl;
}

void test7()
{
    std::cout << "\nTest7======================================" << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    
    return 0;
}