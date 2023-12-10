#include <memory>
#include <iostream>
#include <vector>
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
    /*Test t1 {1000};
    Test t2;
    
    Test *t3 = new Test(1000);
    delete t3;*/  
    
    //std::unique_ptr<Test> t1 {new Test{999}};
    //std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
    //auto t3 = std::make_unique<Test>(1001);
    
    std::unique_ptr<Account> a1 {new Checking_Account{"Nick", 4000}};
    std::unique_ptr<Account> a2;
    
    a2 = std::move(a1);
    if(!a1) std::cout << "a1 nullptr" << std::endl;
    
    std::unique_ptr<Account> a3 = std::make_unique<Trust_Account>("Ksy", 5000, 10);
    a3->deposit(5000);
    std::cout << *a3 << std::endl;
    
    std::vector<std::unique_ptr<Account>> accounts;
    
    accounts.push_back(std::make_unique<Checking_Account>("James", 1000));
    accounts.push_back(std::make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back(std::make_unique<Trust_Account>("Bobby", 5000, 4.5));
    
    for(const auto &acc: accounts) std::cout << *acc << std::endl;
        
    
	return 0;
}		