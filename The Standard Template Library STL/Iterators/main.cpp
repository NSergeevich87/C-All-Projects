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

void test2()
{
    std::cout << "\n===================================" << std::endl;
    std::vector<int> nums2 {1, 2, 3, 4, 5};
    std::vector<int>::iterator it;
    
    it = nums2.begin();
    while(it != nums2.end())
    {
        std::cout << *it << " ";
        it++;
    }
    
    it = nums2.begin();
    while(it != nums2.end())
    {
        *it = 0;
        it++;
    }
    
    display(nums2);
}

void test3()
{
    std::cout << "\n========CONST_ITERATOR=========" << std::endl;
    std::vector<int> nums3 { 1, 2, 3, 4, 5 };
    
    //std::vector<int>::const_iterator it = nums3.begin();
    auto it = nums3.cbegin();
    
    while(it != nums3.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    
    it = nums3.begin();
    
    while(it != nums3.end())
    {
        //*it = 0;  // Compiler error - read only
        it++;
    }
}

void test4()
{
    std::cout << "\n=========REVERSE_ITERATOR=========" << std::endl;
    // revers iterator over a vector of integers
    std::vector<int> nums4 { 1, 2, 3, 4, 5 };
    
    auto it1 = nums4.rbegin();
    while( it1 != nums4.rend())
    {
        std::cout << *it1 << std::endl;
        it1++;
    }
    
    // const revers iterator over a LIST
    std::list<std::string> people { "Nick", "Ksy", "Daniil" };
    
    auto it2 = people.crbegin(); // const reverse iterator
    while(it2 != people.crend())
    {
        std::cout << *it2 << std::endl;
        it2++;
    }
    
    // iterator over a MAP
    std::map<std::string, std::string> hobby
    {
        { "Nick", "C++" },
        { "Ksy", "PR" },
        { "Daniil", "Coches" }
    };
    
    auto it3 = hobby.begin();
    while(it3 != hobby.end())
    {
        std::cout << it3->first << " " << it3->second << std::endl;
        it3++;
    }
}

void test5()
{
    std::cout << "\n===========SUBSET_of_a_container==========" << std::endl;
    std::vector<int> nums5 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    std::vector<int>::iterator start = nums5.begin() + 2;
    std::vector<int>::iterator finish = nums5.end() - 3;
    
    while(start != finish)
    {
        std::cout << *start << std::endl;
        start++;
    }
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