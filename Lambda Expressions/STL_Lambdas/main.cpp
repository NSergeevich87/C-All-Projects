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
}

void test4()
{
    std::cout << "\nTest4==================================" << std::endl;
}

void test5()
{
    std::cout << "\nTest5==================================" << std::endl;
}

void test6()
{
    std::cout << "\nTest6==================================" << std::endl;
}

void test7()
{
    std::cout << "\nTest7==================================" << std::endl;
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