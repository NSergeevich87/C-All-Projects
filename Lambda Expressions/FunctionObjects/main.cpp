#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

struct Square_Functor
{
    void operator() (int x)
    {
        std::cout << x * x << " ";
    }
};

template<typename T>
struct Displayer
{
    void operator() (const T &data)
    {
        std::cout << data << " ";
    }
};

class Multiplier
{
    private:
        int num{};
        
    public:
        Multiplier(int num_val) : num{num_val} {}
        int operator() (int n) const
        {
            return n * num;
        }
};

int main()
{
    std::cout << "\nTest1=============================================" << std::endl;
    
    Square_Functor square;
    square(4);
    
    Displayer<int> p1;
    Displayer<std::string> p2;
    p1(100);
    p2("Nick");
    
    std::cout << "\nTest2=============================================" << std::endl;
    
    std::vector<int> nums { 3, 45, 6, 76, 5, 43 };
    std::vector<std::string> names { "Nick", "Ksy", "Daniil" };
    
    std::for_each(nums.begin(), nums.end(), Square_Functor());
    std::for_each(begin(nums), end(nums), square);
    std::for_each(nums.begin(), nums.end(), Displayer<int>());
    std::for_each(nums.begin(), nums.end(), p1);
    
    std::cout << std::endl;
    std::for_each(begin(names), end(names), Displayer<std::string>());
    std::for_each(begin(names), end(names), p2);
    
    std::cout << "\nTest3=============================================" << std::endl;
    
    std::for_each(nums.begin(), nums.end(), [] (int x) { std::cout << x * x << " "; });
    std::cout << std::endl;
    
    std::for_each(begin(nums), end(nums), [] (int x) { std::cout << x << " "; });
    std::cout << std::endl;
    
    std::for_each(begin(nums), end(nums), [] (int x) { std::cout << x * 10 << " "; });
    std::cout << std::endl;
    
    std::for_each(names.begin(), names.end(), [] (std::string x) { std::cout << x << " "; });
    std::cout << std::endl;
    
    std::cout << "\nTest4=============================================" << std::endl;
    
    Multiplier mult(100);
    std::vector<int> num { 1, 2, 3, 4, 5 };
    
    std::transform(num.begin(), num.end(), num.begin(), mult);
    std::for_each(num.begin(), num.end(), p1);
    
    num = { 1, 2, 3, 4, 5 };
    std::transform(num.begin(), num.end(), num.begin(), [] (int x) { return x * 100; });
    std::cout << std::endl;
    std::for_each(num.begin(), num.end(), [] (int x) { std::cout << x << " "; });
    
    return 0;
}