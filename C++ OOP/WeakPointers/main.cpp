#include <iostream>
#include <memory>

using namespace std;

class B;

class A
{
    private:
        std::shared_ptr<B> ptr_b;
    public:
        void set_B(std::shared_ptr<B> b)
        {
            ptr_b = b;
        }
        A() { std::cout << "A constructor" << std::endl; }
        ~A() { std::cout << "A destructor" << std::endl; }
};

class B
{
    private:
        std::weak_ptr<A> ptr_a; //В этой ситуации один из поинтеров должен быть weak чтобы избежать утечьки памяти
    public:
        void set_A(std::shared_ptr<A> a)
        {
            ptr_a = a;
        }
        B() { std::cout << "B constructor" << std::endl; }
        ~B() { std::cout << "B destructor" << std::endl; }
};

int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->set_B(b);
    b->set_A(a);
	
	cout << endl;
	return 0;
}		