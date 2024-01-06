#include <iostream>
#include <list>
#include <vector>
#include <stack>

template<typename T>
void display(std::stack <T> s)
{
    std::cout << "[ ";
    while(!s.empty())
    {
        T temp = s.top();
        s.pop();
        std::cout << temp << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::stack<int> s1;
    std::stack<int, std::vector<int>> s2;
    std::stack<int, std::list<int>> s3;
    std::stack<int, std::deque<int>> s4;
    
    for(int i: { 1, 2, 3, 4, 5 }) s1.push(i);
    display(s1);
    //std::cout << s1.top() << std::endl;
    
    s1.push(100);
    display(s1);
    
    s1.pop();
    s1.pop();
    display(s1);
    
    while(!s1.empty()) s1.pop();
    display(s1);
    
    std::cout << "Size: " << s1.size() << std::endl;
    
    s1.push(10);
    display(s1);
    
    s1.top() = 100;
    display(s1);
    
    return 0;
}