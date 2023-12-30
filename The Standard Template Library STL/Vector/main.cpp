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

void test7()
{
    cout << "\nTest7=============================" << endl;
    
    std::vector<int> vec1 { 1, 2, 3, 4, 5, 6 };
    std::vector<int> vec2 { 10, 20, 30, 40 };
    
    std::cout << "Vector_1: ";
    display_1(vec1);
    std::cout << std::endl;
    std::cout << "Vector_2: ";
    display_1(vec2);
    std::cout << std::endl;
    
    vec1.swap(vec2);
    
    std::cout << "Vector_1: ";
    display_1(vec1);
    std::cout << std::endl;
    std::cout << "Vector_2: ";
    display_1(vec2);
    std::cout << std::endl;
}

void test8()
{
    cout << "\nTest8=============================" << endl;
    
    vector<int> vec { 4, 54, 6, 5, 78, 9, 87, 65 };
    display_1(vec);
    
    std::sort(begin(vec), end(vec));
    display_1(vec);
}

void test9()
{
    cout << "\nTest9=============================" << endl;
    
    std::vector<int> vec1 { 1, 2, 3, 4, 5 };
    std::vector<int> vec2 { 10, 20 };
    
    display_1(vec1);
    display_1(vec2);
    cout << endl;
    
    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display_1(vec1);
    display_1(vec2);
    cout << endl;
    sort(begin(vec2), end(vec2));
    display_1(vec2);
    
    // copy_if (the element is even)
    vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vec2 = { 10, 20 };
    
    display_1(vec1);
    display_1(vec2);
    
    std::copy_if(begin(vec1), end(vec1), std::back_inserter(vec2),
        [] (int x) { return x % 2 == 0; });
        
    display_1(vec1);
    display_1(vec2);
}

void test10()
{
    cout << "\nTest10=============================" << endl;
    // перемножим два вектора и запишем результат в новый вектор
    
    std::vector<int> vec1 { 1, 2, 3, 4, 5 };
    std::vector<int> vec2 { 10, 20, 30, 40, 50 };
    std::vector<int> vec3 {};
    
    display_1(vec1);
    display_1(vec2);
    display_1(vec3);
    
    std::transform(vec1.begin(), vec1.end(), begin(vec2), // что? берем полностью векто1 и начало вектора2
        back_inserter(vec3),                              // куда? копируем в вектор3
        [] (int x, int y) { return x * y; });             // как? используем лямбду для описания правила
        
    display_1(vec1);
    display_1(vec2);
    display_1(vec3);
}

void test11()
{
    cout << "\nTest11=============================" << endl;
    // есть 2 вектора, мы хотим второй вектор вставить в первый перед определенным элементом
    
    std::vector<int> vec1 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> vec2 { 111, 222, 333, 444, 555 };
    
    display_1(vec1);
    display_1(vec2);
    
    std::vector<int>::iterator it = std::find(begin(vec1), end(vec1), 5);
    if (it != vec1.end())
    {
        std::cout << "inserting..." << std::endl;
        vec1.insert(it, begin(vec2), end(vec2)); 
    }
    else cout << "Element not found" << endl;
    
    display_1(vec1);
}

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    //test8();
    //test9();
    //test10();
    test11();
    
    return 0;
}