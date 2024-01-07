#include <iostream>
#include <queue>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name{};
    int age{};
    
    public:
        Person() : name{"Default"}, age{0} {}
        Person(std::string name_val, int age_val) : name{name_val}, age{age_val} {}
        
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
void display(std::priority_queue<T> p)
{
    std::cout << "[ ";
    while(!p.empty())
    {
        T temp = p.top();
        p.pop();
        std::cout << temp << " ";
    }
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\nTest1==========================================" << std::endl;
    
    std::priority_queue<int> pq{};
    
    for(int i: { 30, 8, 64, 5, 1, 26, 7, 80, 86 })
    {
        pq.push(i);
    }
    
    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl;
    display(pq);
    
    pq.pop();
    display(pq);
}

void test2()
{
    std::cout << "\nTest2==========================================" << std::endl;
    
    std::priority_queue<Person> pq{};
    
    pq.push(Person{ "A", 0 });
    pq.push(Person{ "B", 5 });
    pq.push(Person{ "C", 66 });
    pq.push(Person{ "D", 45 });
    pq.push(Person{ "E", 13 });
    pq.push(Person{ "F", 22 });
    
    display(pq);
}

int main()
{
    test1();    
    test2();    
    
    return 0;
}