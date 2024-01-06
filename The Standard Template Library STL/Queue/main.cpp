#include <iostream>
#include <queue>
#include <list>

template<typename T>
void display(std::queue<T> q)
{
    std::cout << "[ ";
    while(!q.empty())
    {
        T temp = q.front();
        q.pop();
        std::cout << temp << " ";
    }
    std::cout << "]" << std::endl;
}

template<typename T>
void display(std::queue<T, std::list<T>> q)
{
    std::cout << "[ ";
    while(!q.empty())
    {
        T temp = q.front();
        q.pop();
        std::cout << temp << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::queue<int, std::list<int>> q{};
    
    for(int i: { 1, 2, 3, 4, 5 }) q.push(i);
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    
    q.push(100);
    display(q);
    
    q.pop();
    q.pop();
    display(q);
    
    while(!q.empty()) q.pop();
    display(q);
    
    std::cout << "Size: " << q.size() << std::endl;
    for(int i: { 10, 100, 1000 }) q.push(i);
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    
    q.front() = 5;
    q.back() = 5000;
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;
    
    return 0;
}