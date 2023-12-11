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

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int amount);
void display(const std::vector<std::shared_ptr<Test>> &vec);

int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    //vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    //fill(*vec_ptr, num);
    //display(*vec_ptr);
	
	cout << endl;
	return 0;
}	

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
    
}	