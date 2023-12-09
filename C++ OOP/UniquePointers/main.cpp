#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

class Test
{
private:
    int data;

public:
    Test() : data{0} {std::cout << "Base Test constructor (" << data << ")" << std::endl;}
    Test(int data_val) : data{data_val} {std::cout << "Test constructor (" << data << ")" << std::endl;}
    int get_data() const {return data;}
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl;}
};

using namespace std;

int main()
{
    Test t1 {1000};
    Test t2;
    
	cout << endl;
	return 0;
}		