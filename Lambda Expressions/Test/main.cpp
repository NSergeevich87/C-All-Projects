#include <iostream>

using namespace std;


int main()
{
    int y {3};
    
    auto lm2 = [y](int x){ cout << x * y << endl; };
    lm2(10);
    
    int x {100};
    
    [&x] () mutable {
        x += 100;
        cout << x;
    }();
    
    cout << x << endl;
	
	cout << endl;
	return 0;
}		