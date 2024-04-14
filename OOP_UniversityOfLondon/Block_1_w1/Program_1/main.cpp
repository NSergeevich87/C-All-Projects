#include <iostream>

using namespace std;
// Function to caluculate first 10 natural numbers and return numper and print the sum
int calculateFirst10NaturalNumbers() {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
        cout << sum << " ";
    } 
    return sum;
} 

// Main function
int main() {
    int result = calculateFirst10NaturalNumbers();
    cout << "\nSum of first 10 natural numbers is: " << result << endl;
    return 0;
}