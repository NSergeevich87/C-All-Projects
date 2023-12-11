#include <iostream>
#include <memory>

using namespace std;

class Base
{
	private:
		int data;
        
    public:
        Base() : data{0} { std::cout << "Base constructor" << std::endl; }
        Base(int data_val) : data{data_val} { std::cout << "Overload Base constructor " << data << std::endl; }
        int get_data() const { return data; }
        ~Base() { std::cout << "Destructor Base" << std::endl; }
};

void my_deleter(Base *ptr)
{
    std::cout << "My_deleter" << std::endl; 
    delete ptr;
}

int main()
{
    // Using a FUNCTION
    {
        //std::shared_ptr<Base> base1 = std::make_shared<Base>(100);
        std::shared_ptr<Base> base2 { new Base{100}, my_deleter };
    }
	
    std::cout << "======================================================" << std::endl;
    
    // Using a LAMBDA expression
    {
        std::shared_ptr<Base> base3 ( new Base{666},
        [] (Base *b)
        {
           std::cout << "Using Lambda expression deleter" << std::endl;
            delete b;
        });
    }
    
	cout << endl;
	return 0;
}		