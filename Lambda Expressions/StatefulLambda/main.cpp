#include <iostream>
#include <vector>
#include <algorithm>

int global_x{1000};

void test1()
{
    std::cout << "\nTest1=========================================" << std::endl;
    
    int local_x{100};
    
    auto l = [local_x]()
    { 
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    l();
}

void test2()
{
    std::cout << "\nTest2=========================================" << std::endl;
    
    int x{3};
    
    auto l = [x]()mutable
    {
        x += 100;
        std::cout << x << std::endl;
    };
    
    l();
    std::cout << x << std::endl;
    
    l();
    std::cout << x << std::endl;
}

void test3()
{
    std::cout << "\nTest3=========================================" << std::endl;
    
    int x{100};
    
    auto lm = [&x]()mutable
    {
        x += 100;
        std::cout << "lm: " << x << std::endl;
    };
    
    lm();
    std::cout << x << std::endl;
    
    lm();
    std::cout << x << std::endl;
}

void test4()
{
    std::cout << "\nTest4=========================================" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};
    
    auto lm = [=]()mutable
    {
        x *= 2;
        y *= 2;
        z *= 2;
        std::cout << "lm: " << x << std::endl;
        std::cout << "lm: " << y << std::endl;
        std::cout << "lm: " << z << std::endl;
    };
    
    lm();
    std::cout << x << " " << y << " " << z << std::endl;
    
    lm();
    std::cout << x << " " << y << " " << z << std::endl;
}

void test5()
{
    std::cout << "\nTest5=========================================" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};
    
    auto lm = [&]()mutable
    {
        x += 100;
        y += 100;
        z += 100;
        std::cout << "lm: " << x << " " << y << " " << z << std::endl;
    };
    
    lm();
    std::cout << x << " " << y << " " << z << std::endl;
}

void test6()
{
    std::cout << "\nTest6=========================================" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};
    
    auto lm = [=, &y]()mutable
    {
        x += 100;
        y += 100;
        z += 100;
        std::cout << "lm: " << x << " " << y << " " << z << std::endl;
    };
    
    lm();
    std::cout << x << " " << y << " " << z << std::endl;
}

void test7()
{
    std::cout << "\nTest7=========================================" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};
    
    auto lm = [&, x, z]()mutable
    {
        x += 100;
        y += 100;
        z += 100;
        std::cout << "lm: " << x << " " << y << " " << z << std::endl;
    };
    
    lm();
    std::cout << x << " " << y << " " << z << std::endl;
}

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    private:
        std::string name{};
        int age{};
    public:
        // constructors and destructors
        Person() = default;
        Person(std::string name_val, int age_val) : name{name_val}, age{age_val} {}
        Person(const Person &p) : name{p.name}, age{p.age} {}
        ~Person() = default;
        // getters and setters
        std::string get_name() const { return name; }
        void set_name(std::string name) { this->name = name; }
        int get_age() const { return age; }
        void set_age(int age) { this->age = age; }
        
        auto change_person1() { return [this](std::string new_name, int new_age){ name = new_name; age = new_age;};}
        auto change_person2() { return [=](std::string new_name, int new_age){ name = new_name; age = new_age;};}
        auto change_person3() { return [&](std::string new_name, int new_age){ name = new_name; age = new_age;};}
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "[Person: " << p.name << " : " << p.age << "]";
    return os;
}

void test8()
{
    std::cout << "\nTest8=========================================" << std::endl;
    
}

void test9()
{
    std::cout << "\nTest9=========================================" << std::endl;
    
}

void test10()
{
    std::cout << "\nTest10=========================================" << std::endl;
    
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
    test8();
    test9();
    test10();
    
    return 0;
}