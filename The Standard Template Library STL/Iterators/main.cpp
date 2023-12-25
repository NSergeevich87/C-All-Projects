#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void display(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for(auto const &v : vec)
        std::cout << v << " ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\n=========================================" << std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};
    std::vector<int>::iterator it = nums1.begin();
    //auto it = nums1.begin();
    std::cout << *it << std::endl;
    
    ++it;
    std::cout << *it << std::endl;
    
    it += 2;
    std::cout << *it << std::endl;
    
    it -= 2;    
    std::cout << *it << std::endl;

    it = nums1.end() - 1;
    std::cout << *it << std::endl;
}

int main()
{
    test1();
    
    return 0;
}