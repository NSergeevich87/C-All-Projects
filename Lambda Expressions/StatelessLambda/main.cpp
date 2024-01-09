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
    
    [](){ std::cout << "Hi!" << std::endl; }();
    [](int x){ std::cout << x << std::endl; }(100);
    [](int x, int y){ std::cout << x + y << std::endl; }(100, 200);
}

void test2()
{
    std::cout << "\nTest2======================================" << std::endl;
    
    auto l1 = [](){ std::cout << "Hi!" << std::endl; };
    l1();
    
    int num1 {100};
    int num2 {100};
    auto l2 = [](int x, int y){ std::cout << x + y << std::endl; };
    l2(10, 20);
    l2(num1, num2);
    
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl; // 100 200
    auto l3 = [](int &x, int y)
    { 
        std::cout << "x " << x << " y " << y << std::endl;           // 100 200
        x = 1000;                                                    // здесь мы по ссылке перезапишем значение в num1 
        y = 2000;                                                    // здесь мы сделаем копирование num2
        std::cout << "x " << x << " y " << y << std::endl;           // 1000 2000
    };
    l3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl; // 1000 100 (num1 перезаписали)
}

void test3()
{
    std::cout << "\nTest3======================================" << std::endl;
    
    Person stooges { "Nik", 35 };
    std::cout << stooges << std::endl;
    
    auto l4 = [](Person p){ std::cout << p << std::endl; };
    l4(stooges);
    
    auto l5 = [](const Person &p){ std::cout << p << std::endl; };
    l5(stooges);
    
    auto l6 = [](Person &p)
    {
        p.set_name("Nick");
        p.set_age(36);
        std::cout << p << std::endl;
    };
    l6(stooges);
    
    std::cout << stooges << std::endl;
}

// Сделаем Predicate Lambda function
void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func)
// void filter_vector(const std::vector<int> &vec, auto func)
{
    std::cout << "[ ";
    for(int i: vec)
    {
        if(func(i)) std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test4()
{
    std::cout << "\nTest4======================================" << std::endl;
    
    std::vector<int> vec { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    
    filter_vector(vec, [](int x){ return x; });
    filter_vector(vec, [](int x){ return x > 50; });
    filter_vector(vec, [](int x){ return x <= 30; });
    filter_vector(vec, [](int x){ return x >= 30 && x <= 60; });
}

// make lambda!
auto make_lambda()
{
    return []()
    { 
        std::cout << "This lambda was made using the make_lambda function" << std::endl;
    };
}

void test5()
{
    std::cout << "\nTest5======================================" << std::endl;
    
    auto lm = make_lambda();
    lm();
}

void test6()
{
    std::cout << "\nTest6======================================" << std::endl;
    
    auto lm = [](auto x, auto y){ std::cout << "X: " << x << " Y: " << y << std::endl; };
    lm(10, 40);
    lm(1.45, 6);
    lm(8.345, 3.2);
    
    lm(Person{"Nikita", 36}, Person{"Kseniia", 34});
}

void test7()
{
    std::cout << "\nTest7======================================" << std::endl;
    
    std::vector<Person> persons
    {
        {"Nick", 36},
        {"Ksy", 34},
        {"Daniil", 21}
    };
    
    std::sort(persons.begin(), persons.end(), [](const Person &p1, const Person &p2)
    {
        return p1.get_name() < p2.get_name();
    });
    
    std::for_each(begin(persons), end(persons), [](const Person &p) { std::cout << p << std::endl; }); 
    

    std::sort(persons.begin(), persons.end(), [](const Person &p1, const Person &p2)
    {
        return p1.get_age() < p2.get_age();
    });
    
    std::for_each(begin(persons), end(persons), [](const Person &p){ std::cout << p << std::endl; });
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
    // fin de 09.01.2024
    return 0;
}