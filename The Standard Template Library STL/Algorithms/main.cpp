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
        
        string get_name() const { return name; }
        int get_age() const { return age; }
};

void find_test()
{
    cout << "\n===============FIND_test=================" << endl;
    vector<int> nums { 2, 2, 3, 4, 5 };
    
    auto finder = find(begin(nums), end(nums), 1);
    
    if (finder != end(nums))
    {
        cout << "Number is finded: " << *finder << endl;
    }
    else
    {
        cout << "Number is not finded" << endl;
    }
    
    list<Person> new_list
    {
        {"Nick", 36},
        {"Kseniia", 34},
        {"Daniil", 21}
    };
    
    auto fp = find(new_list.begin(), new_list.end(), Person {"Daniil", 22});
    if (fp != new_list.end())
    {
        cout << "Found Daniil" << endl;
    }
    else
    {
        cout << "Person not found" << endl;
    }
}

void count_test()
{
    cout << "\n===============COUNT_test=================" << endl;
    std::vector<int> vec { 1, 3, 5, 4, 8, 9, 4, 1, 6, 8, 8, 9, 1, 8 };
    
    auto counter = std::count(begin(vec), end(vec), 2);
    cout << "2 : " << counter << " times" << endl;
    
}

void count_if_test()
{
    cout << "\n===============COUNT_IF_test=================" << endl;
    
    std::vector<int> numbers { 1, 2, 44, 9, 8, 86, 2, 5, 69, 87, 86, 3, 25, 98 };
    
    
    int even_c = std::count_if(numbers.begin(), numbers.end(), [] (int x) { return x % 2 == 0; });
    cout << "Even numbers: " << even_c << endl;
    
    int odd_c = count_if(begin(numbers), end(numbers), [] (int x) { return x % 2 != 0; });
    cout << "Odd numbers: " << odd_c << endl;
    
    
    int nums_grater_than = count_if(numbers.begin(), numbers.end(), [] (int x) { return x > 44; });
    cout << "Nums > 44: " << nums_grater_than << endl;
}

void replace_test()
{
    cout << "\n===============REPLACE_test=================" << endl;
    
    std::vector<int> nums { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    for(auto n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
    
    std::replace(nums.begin(), nums.end(), 3, 300);
    
    for(auto n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
}

void all_of_test()
{
    cout << "\n===============ALL_OF_test=================" << endl;
    
    std::vector<int> nums { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    
    bool more_than_all = std::all_of(nums.begin(), nums.end(), [] (int x) { return x > 5; });   // false
    if (more_than_all) cout << "All elements more than 5: " << more_than_all << endl;
    else cout << "All elements more than 5: " << more_than_all << endl;
    
    
    if(std::all_of(nums.begin(), nums.end(), [] (int x) { return x < 10; }))
    {
        cout << "All elements less than 10" << endl;
    }
    else
    {
        cout << "Not all alements are < 10" << endl;
    }
}

void string_transform_test()
{
    cout << "\n===============STRING_TRANSFORM_test=================" << endl;
    
    string some_text {"Ya ochen lublu svoyou shenu!"};
    cout << some_text << endl;
    
    transform(some_text.begin(), some_text.end(), begin(some_text), ::toupper);
    cout << "After transform: " << some_text << endl;
}

int main()
{
    cout << boolalpha;
    
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();
    
    return 0;
}