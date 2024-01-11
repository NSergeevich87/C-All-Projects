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
    
    Person per {"Nick", 28};
    std::cout << per << std::endl;
    
    // using state [this]
    auto change_per1 = per.change_person1();
    change_per1("Nikita", 36);
    std::cout << per << std::endl;
    
    // using state [=]
    auto change_per2 = per.change_person2();
    change_per2("Ksy", 34);
    std::cout << per << std::endl;
    
    auto change_per3 = per.change_person3();
    change_per3("Daniil", 21);
    std::cout << per << std::endl;
}

class Lambda
{
    private:
        int y {};
    public:
        Lambda(int y) : y{y} {}
        
        void operator() (int x) const
        {
            std::cout << x * y << std::endl;
        };
};

void test9()
{
    std::cout << "\nTest9=========================================" << std::endl;
    
    int y {100};
    
    Lambda l1(y);
    auto l2 = [y](int x){std::cout << x * y << std::endl;};
    
    l1(200);
    l2(200);
}

class People
{
        std::vector<Person> p{};
        int max_people{};
        
    public:
        People(int max = 10) : max_people{max} {}
        People(const People &p) = default;
        
        void add(std::string name, int age)
        {
            p.emplace_back(name, age);
        }
        
        void set_max(int max) { max_people = max; }
        int get_max() const { return max_people; }
        
    // здесь опишем метод возвращающий вектор с отфильтрованными элементами по определенному правилу используя лямбда выражение
        std::vector<Person> get_persons(int max_age)
        {
            std::vector<Person> temp{};
            int counter{0};
            
            std::copy_if(p.begin(), p.end(),
                std::back_inserter(temp),
                [this, &counter, max_age](const Person &p){ return p.get_age() > max_age && ++counter <= max_people; }); 
                
            return temp;
        }
};

void test10()
{
    std::cout << "\nTest10=========================================" << std::endl;
    
    People friends;
    friends.add("Nick", 16);
    friends.add("Nick2", 26);
    friends.add("Nick3", 36);
    friends.add("Nick4", 46);
    friends.add("Nick5", 56);
    friends.add("Nick6", 66);
    
    std::cout << std::endl;
    
    auto filter = friends.get_persons(10);
    for(const auto &p : filter)
        std::cout << p << std::endl;
    
    std::cout << std::endl;
    
    filter = friends.get_persons(40);
    for(const auto &p : filter)
        std::cout << p << std::endl;
    
    friends.set_max(3);
    filter = friends.get_persons(10);
    
    std::cout << std::endl;
    
    for(const auto &p : filter)
        std::cout << p << std::endl;
        
    filter = friends.get_persons(60);
    
    std::cout << std::endl;
    
    for(const auto &p : filter)
        std::cout << p << std::endl;
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