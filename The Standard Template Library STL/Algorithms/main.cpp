#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

class Person
{
    private:
        std::string name{};
        int age{};
        
    public:
        Person() = default;
        Person(std::string name, int age) : name{name}, age{age} {}
        
        bool operator<(const Person &rhs) const
        {
            return this->age < rhs.age;
        }
        
        bool operator==(const Person &rhs) const
        {
            return (this->name == rhs.name && this->age == rhs.age);
        }
};

int main()
{
    cout << "\n============================================" << endl;
    std::vector<int> nums { 1, 2, 3, 4, 5 };
    
    //auto loc = std::find(nums.begin(), nums.end(), 1);
    auto loc = std::find(std::begin(nums), std::end(nums), 1);
    
    if(loc != nums.end())
    {
       cout << "Number was finded: " << *loc << endl; 
    }
    else cout << "Couldn't find the number" << endl;
    
    return 0;
}