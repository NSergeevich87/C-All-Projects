#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Base
{
	private:
        int num;
    
    public:
        Base() : num{0} { std::cout << "Base constructor" << std::endl; }
        Base(int num_val) : num{num_val} { std::cout << "Overload constructor" << std::endl; }
        int get_num() const { return num; }
        ~Base() { std::cout << "Base destructor" << std::endl; }
};

void func(std::shared_ptr<Base> ptr)
{
    std::cout << "use_count: " << ptr.use_count() << std::endl;
}

int main()
{
    /*std::shared_ptr<int> ptr1 {new int {200}};
    cout << "use_count ptr1: " << ptr1.use_count() << endl;
    
    std::shared_ptr<int> ptr2 = std::make_shared<int>(100);
    cout << "use_count ptr2: " << ptr2.use_count() << endl;
    
    std::shared_ptr<int> ptr3 {ptr1};
    cout << "use_count ptr1: " << ptr1.use_count() << endl;
    cout << "use_count ptr3: " << ptr3.use_count() << endl;
    
    std::shared_ptr<int> ptr4;
    ptr4 = ptr2;
    cout << "use_count ptr2: " << ptr2.use_count() << endl;
    cout << "use_count ptr4: " << ptr4.use_count() << endl;
    
    ptr1.reset();
    ptr2.reset();
    
    cout << "use_count ptr1: " << ptr1.use_count() << endl;
    cout << "use_count ptr2: " << ptr2.use_count() << endl;
    cout << "use_count ptr3: " << ptr3.use_count() << endl;
    cout << "use_count ptr4: " << ptr4.use_count() << endl;*/
    
    std::shared_ptr<Base> ptr1 {new Base {500}};
    func(ptr1);
    std::shared_ptr<Base> ptr2 = std::make_shared<Base>(200);
    cout << ptr2.use_count() << endl;
    
    std::vector<std::shared_ptr<Base>> ptrs;
    ptrs.push_back(std::make_shared<Base>(100));
    ptrs.push_back(std::make_shared<Base>(200));
    ptrs.push_back(std::make_shared<Base>(300));
    
    for(auto &p: ptrs)
    {
        std::cout << p.use_count() << std::endl;
        std::cout << p->get_num() << std::endl;
        p.reset();
    }
    
    for(auto &p: ptrs)
    {
        std::cout << p.use_count() << std::endl;
    }
	
	cout << endl;
	return 0;
}		