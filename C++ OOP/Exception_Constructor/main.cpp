#include <iostream>

using namespace std;

class Base
{
	public:
		int a{};
		void display() { cout << "a : " << a << " b : " << b << " c : " << endl; }
	
	protected:
		int b{};
		
	private:
		int c{};
};

int main()
{
	Base base1;
	base1.a = 100;
	base1.display();
	
	cout << endl;
	return 0;
}		