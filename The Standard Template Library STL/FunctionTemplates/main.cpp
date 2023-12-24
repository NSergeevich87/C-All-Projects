#include <iostream>
#include <string>

template <typename T> T min(T a, T b)
{
   return (a < b) ? a : b;
}

template <typename T1, typename T2> void func(T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

struct Person
{
    std::string name{};
    int age{};
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name;
    return os;
}

template <typename t1, typename t2>
t1 divider(t1 a, t2 b)
{
    return a / b;
}

int main()
{
    double a{20};
    int b{15};
    double c{};
    c = divider(a, b);
    std::cout << c << std::endl;
    
    int x{100};
    int y{200};
    std::cout << x << ", " << y << std::endl;
    swap(x, y);
    std::cout << x << ", " << y << std::endl;
    
    std::cout << std::endl;
    
    Person p1 {"Nick", 26};
    Person p2 {"Ksy", 34};
    Person p3 = min(p1, p2);
    std::cout << p3.name << " is younger" << std::endl;
    
    func(p1, p2);
    
    std::cout << min<int>(2, 3) << std::endl;
    std::cout << min(2,3) << std::endl;
    std::cout << min('A', 'B') << std::endl;
    std::cout << min(12.45, 9.432) << std::endl;
    std::cout << min(4 + 2*2, 5*2 - 4) << std::endl;
    
    func<int, int>(10, 20);
    func(10.4, 'A');
    func("Ksy", 34.1);
    func(36, std::string{"Nikita"});
    
    return 0;
}