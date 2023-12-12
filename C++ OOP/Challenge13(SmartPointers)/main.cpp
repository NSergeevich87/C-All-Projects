#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test
{
  private:
    int d;
    
  public:
    Test() : d{0} { std::cout << "Test Base constructor (" << d << ")" << std::endl; }
    Test(int Test_val) : d{Test_val} { std::cout << "Test Overload constructor (" << d << ")" << std::endl; }
    int get_Test() const { return d; }
    ~Test() { std::cout << "Test Destructor (" << d << ")" << std::endl; }
};

//std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int amount);
void display(const std::vector<std::shared_ptr<Test>> &vec);

//std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
auto make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
	
	cout << endl;
	return 0;
}	

//std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
/*auto make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}*/

void fill(std::vector<std::shared_ptr<Test>> &vec, int amount)
{
    int temp;
    for(auto i = 0; i < amount; ++i)
    {
        std::cout << "Enter data point [" << i + 1 << "] : ";
        std::cin >> temp;
        
        vec.push_back(std::make_shared<Test>(temp));
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec)
{
    std::cout << "===========================" << std::endl;
    for(const auto &v : vec)
    {
        std::cout << v->get_Test() << std::endl;
    }
    std::cout << "===========================" << std::endl;
}