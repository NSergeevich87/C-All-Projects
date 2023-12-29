#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name {};
    int age {};
    
    public:
        Person() = default;
        Person(std::string name_v, int age_v) : name{name_v}, age{age_v} {}
        
        bool operator<(const Person &rhs) const
        {
            return this->age < rhs.age;
        }
        
        bool operator==(const Person &rhs) const
        {
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << " " << p.age;
    return os;
}

template<typename T>
void display_1 (const std::vector<T> &vec)
{
    std::cout << "[ ";
    for(const auto &i : vec) std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void display_2 (const std::vector<int> &vec)
{
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(), [] (int x) { std::cout << x << " "; });
    std::cout << "]" << std::endl;
}

void test1()
{
    cout << "\nTest1=============================" << endl;
    
    vector<int> vec1 { 1, 2, 3, 4, 5 };
    display_1(vec1);
    
    vec1 = { 2, 4, 6, 8 };
    display_2(vec1);
    
    vector<int> vec2 (10, 100);
    display_1(vec2);
    //display_2(vec2);
}

void test2()
{
    cout << "\nTest2=============================" << endl;
    
    vector<int> vec { 1, 2, 3, 4, 5 };
    display_1(vec);
    cout << "Vector size: " << vec.size() << endl;
    cout << "Vector capacity: " << vec.capacity() << endl;
    cout << "Vector max_size: " << vec.max_size() << endl;
    cout << endl;
    
    vec.push_back(6);
    display_1(vec);
    cout << "Vector size: " << vec.size() << endl;
    cout << "Vector capacity: " << vec.capacity() << endl;
    cout << "Vector max_size: " << vec.max_size() << endl;
    cout << endl;
    
    vec.shrink_to_fit();
    display_1(vec);
    cout << "Vector size: " << vec.size() << endl;
    cout << "Vector capacity: " << vec.capacity() << endl;
    cout << "Vector max_size: " << vec.max_size() << endl;
    cout << endl;
    
    vec.reserve(100);
    display_1(vec);
    cout << "Vector size: " << vec.size() << endl;
    cout << "Vector capacity: " << vec.capacity() << endl;
    cout << "Vector max_size: " << vec.max_size() << endl;
    cout << endl;
}

void test3()
{
    cout << "\nTest3=============================" << endl;
    
    vector<int> vec { 1, 2, 3, 4, 5 };
    display_1(vec);
    
    vec[0] = 100;
    vec.at(1) = 200;
    display_1(vec);
}

void test4()
{
    cout << "\nTest4=============================" << endl;
    
    std::vector<Person> stooges{};
    
    Person p1 {"Nick", 36};
    display_1(stooges);
    
    stooges.push_back(p1);
    display_1(stooges);
    
    stooges.push_back(Person{"Ksy", 34});
    display_1(stooges);
    
    stooges.emplace_back("Daniil", 21);
    display_1(stooges);
}

void test5()
{
    cout << "\nTest5=============================" << endl;
    
    vector<Person> stooges
    {
        {"Nick", 36},
        {"Ksy", 34},
        {"Daniil", 21}
    };
    display_1(stooges);
    
    cout << stooges.front() << endl;
    cout << stooges.back() << endl;
    
    stooges.pop_back();
    display_1(stooges);
}

void test6()
{
    cout << "\nTest6=============================" << endl;
    
    vector<int> nums { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display_2(nums);
    
    nums.clear();
    display_2(nums);
    
    nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display_2(nums);
    
    nums.erase(nums.begin(), nums.begin() + 2);
    display_2(nums);
    
    nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    display_2(nums);
    
    std::vector<int>::iterator it = nums.begin();
    while(it != nums.end())
    {
        if (*it % 2 == 0) nums.erase(it);
        else it++;
    }
    display_2(nums);
}

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test6();
    //test7();
    //test8();
    //test9();
    //test10();
    //test11();
    
    return 0;
}