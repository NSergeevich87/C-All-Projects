#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

class Person
{
    friend ostream &operator<<(ostream &os, const Person &p);
    std::string name{};
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
            return (this-> name == rhs.name && this->age == rhs.age);
        }
        
        void operator=(Person &rhs)
        {
            this->name = rhs.name;
            this->age = rhs.age;
        }
};

ostream &operator<<(ostream &os, const Person &p)
{
    os << "Name: " << p.name << " Age: " << p.age;
    return os;
}

template<typename T>
void display(const deque<T> &value)
{
    cout << "[ ";
    for(const auto &item : value)
    {
        cout << item << " ";
    }
    cout << "]" << endl;
}

void test1()
{
    cout << "\nTest1==============================" << endl;
    
    std::deque<int> d1 { 1, 2, 3, 4, 5 };
    display(d1);
    
    std::deque<int> d2 (10, 100);
    display(d2);
    
    d1[0] = 100;
    d1.at(1) = 200;
    display(d1);
}

void test2()
{
    cout << "\nTest2==============================" << endl;
    
    std::deque<int> d1 { 0, 0, 0 };
    display(d1);
    
    d1.push_back(10);
    d1.push_back(20);
    display(d1);
    
    d1.push_front(100);
    d1.push_front(200);
    display(d1);
    
    cout << d1.front() << endl;
    cout << d1.back() << endl;
    cout << d1.size() << endl;
    cout << d1.max_size() << endl;
    
    d1.pop_front();
    display(d1);
    
    d1.pop_back();
    display(d1);
}

void test3()
{
    cout << "\nTest3==============================" << endl;
    // в пустой вектор добавить назад все четные значения из вектора 1, а вперед добавить все нечетные
    
    std::deque<int> d1 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::deque<int> d2 {};
    
    display(d1);
    display(d2);
    
    // Через iterator
    /*std::deque<int>::iterator it = begin(d1);
    while(it != end(d1))
    {
        if(*it % 2 == 0) d2.push_back(*it);
        else d2.push_front(*it);
        it++;
    }*/
    
    // Через цикл for
    for(const auto &item : d1)
    {
        if (item % 2 == 0) d2.push_back(item);
        else d2.push_front(item);
    }
    
    display(d2);
}

void test4()
{
    cout << "\nTest4==============================" << endl;
    
    std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::deque<int> d {};
    display(d);
    
    for(const auto &i : vec) d.push_front(i);
    display(d);
    
    d.clear();
    display(d);
    
    for(const auto &i : vec) d.push_back(i);
    display(d);
}

void test5()
{
    cout << "\nTest5==============================" << endl;
    
    std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::deque<int> d {};
    
    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    display(d);
    
    d.clear();
    
    std::copy(vec.begin(), end(vec), std::back_inserter(d));
    display(d);
}

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    
    return 0;
}