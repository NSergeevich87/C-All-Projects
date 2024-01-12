#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::iota

void test1()
{
    std::cout << "\nTest1==================================" << std::endl;
    
    std::vector<int> nums { 10, 20, 30, 40, 50 };
    
    std::for_each(nums.begin(), end(nums), [](int n){ std::cout << n << " "; });
}

void test2()
{
    std::cout << "\nTest2==================================" << std::endl;
    
    struct Point
    {
        int x{};
        int y{};
    };
    
    Point p1{4,5};
    Point p2{3,1};
    Point p3{6,2};
    Point p4{2,7};
    
    std::vector<Point> triangle1 {p1,p2,p3};
    std::vector<Point> triangle2 {p3,p1,p2};
    std::vector<Point> triangle3 {p2,p3,p4};
    
    if(std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), [](Point lhs, Point rhs){ return lhs.x == rhs.x && lhs.y == rhs.y; }))
        std::cout << "Triangle1 and Triangle2 are equivalent!" << std::endl;
    else std::cout << "Triangle1 and Triangle2 are NOT equivalent!" << std::endl;
    
    if(std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), [](Point lhs, Point rhs){ return lhs.x == rhs.x && lhs.y == rhs.y; }))
        std::cout << "Triangle1 and Triangle2 are equivalent!" << std::endl;
    else std::cout << "Triangle1 and Triangle2 are NOT equivalent!" << std::endl;
}

void test3()
{
    std::cout << "\nTest3==================================" << std::endl;
    
    std::vector<int> vec { 34, 56, 7, 89, 87, 6 };
    int bonus {5};
    
    std::transform(vec.begin(), vec.end(), vec.begin(), [bonus](int num){ return num += bonus; });
    
    for(int &i : vec) std::cout << i << " ";
}

void test4()
{
    std::cout << "\nTest4==================================" << std::endl;
    
    std::vector<int> nums { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    nums.erase(std::remove_if(nums.begin(), nums.end(), [](int n){ return n % 2 == 0; }), nums.end());
    
    for(int &i : nums) std::cout << i << " ";
}

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    private:
        std::string name {};
        int age {};
    public:
        Person(std::string name_val, int age_val) : name{name_val}, age{age_val} {}
        Person(const Person &p) : name{p.name}, age{p.age} {}
        ~Person() = default;
        
        std::string get_name() const { return name; }
        int get_age() const { return age; }
        void set_name(std::string name) { this->name = name; }
        void set_age(int age) { this->age = age; }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "[Person: " << p.name << " : " << p.age << "]";
    return os;
}

void test5()
{
    std::cout << "\nTest5==================================" << std::endl;
    
    Person p1 {"person1", 45};
    Person p2 {"erson2", 15};
    Person p3 {"rson3", 25};
    Person p4 {"son4", 5};
    Person p5 {"on5", 35};
    
    std::vector<Person> persons = { p1, p2, p3, p4, p5 };
    for(auto &i : persons) std::cout << i << std::endl;
    std::cout << std::endl;
    std::sort(persons.begin(), persons.end(), [](Person p1, Person p2){ return p1.get_name() < p2.get_name(); });
    for(auto &i : persons) std::cout << i << std::endl;
    std::cout << std::endl;
    std::sort(persons.begin(), persons.end(), [](Person p1, Person p2) { return p1.get_age() < p2.get_age(); });
    for(auto &i : persons) std::cout << i << std::endl;
}

bool in_range(const std::vector<int> &vec, int start, int end)
{
    bool result {false};
    
    result = std::all_of(vec.begin(), vec.end(), [start, end](int n) { return n >= start && n <= end; });
    
    return result;
}

void test6()
{
    std::cout << "\nTest6==================================" << std::endl;
    
    std::cout << std::boolalpha;
    
    std::vector<int> vec(10);
    std::iota(vec.begin(), vec.end(), 1);
    
    for(int &i: vec) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Nums between 50 and 60: " << in_range(vec, 50, 60) << std::endl;
    std::cout << "Nums between 1 and 10: " << in_range(vec, 0, 20) << std::endl;
    std::cout << "Nums between 5 and 7: " << in_range(vec, 5, 7) << std::endl;
}

class Password_Validator
{
    private:
        char c {'$'};
    public:
        bool is_valid(std::string pass)
        {
            return std::all_of(pass.begin(), pass.end(), [this](char ch) { return c != ch; });
        }
};

class Password_Validator2
{
    private:
        const std::vector<char> check {'!','@','#','$','%','&','*','?','+','-','/'};
    public:
        bool is_valid(std::string pass)
        {
            return std::all_of(pass.begin(), pass.end(), [this](char ch){ 
                return std::none_of(check.begin(), check.end(), [ch](char c){ 
                    return c == ch; });});
        }
};

void test7()
{
    std::cout << "\nTest7==================================" << std::endl;
    
    std::cout << std::boolalpha;
    std::string pass1 {"sasdfgh$"};
    Password_Validator validator;
    std::cout << "Password is valid: " << validator.is_valid(pass1) << std::endl;
    
    Password_Validator2 validator2;
    std::string pass2 {"^sfdgfhdh"};
    std::cout << "Password is valid: " << validator2.is_valid(pass2) << std::endl;
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