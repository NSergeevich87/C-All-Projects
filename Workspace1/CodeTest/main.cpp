#include <iostream>
#include <string>

using namespace std;

unsigned long long sum_digit(unsigned long long);
unsigned long long sum_digit(unsigned long long n)
{
    if (n < 10) return n % 10;
    return (n % 10) + sum_digit(n / 10);
}

int main()
{   
    int num {5678};
    cout << num % 10 << endl;
    cout << sum_digit(num) << endl;
    
    cout << endl;
    return 0;
}

string try_to_change(string name)
{
    
    //cout << "Into method try_to_change name is: " << name << endl;
    return name = "Kseniia";;
}