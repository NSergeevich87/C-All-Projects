#include <iostream>

using namespace std;

int main()
{
    int counter {10};
    int result {0};
    
    result = ++counter;
    cout << "counter: " << counter << endl;
    cout << "result: " << result << endl;
    
    //example_2
    
    int counter2 {10};
    int result2 {0};
    
    result2 = counter2++;
    cout << "counter2: " << counter2 << endl;
    cout << "result2: " << result2 << endl;
    
    //example_3
    
    int counter3 {10};
    int result3 {0};
    
    result3 = ++counter3 + 10;
    cout << "counter3: " << counter3 << endl;
    cout << "result3: " << result3 << endl;
    
    return 0;
}