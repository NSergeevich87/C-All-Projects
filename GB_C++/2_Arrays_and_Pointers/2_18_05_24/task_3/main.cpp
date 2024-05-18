/** Пользователь вводит с клавиатуры число n, а затем -- n целых чисел. 
 * Необходимо отыскать второе по величине из этих чисел и вывести на экран.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter the number: " << i + 1 << " ";
        cin >> numbers[i];
    }
    int max = numbers[0];
    int secondMax = numbers[0];
    for (int i = 0; i < n; ++i) {
        if (numbers[i] > max) {
            secondMax = max;
            max = numbers[i];
        } else if (numbers[i] > secondMax && numbers[i] != max) {
            secondMax = numbers[i];
        }
    }
    cout << "Second max: " << secondMax << endl;
    return 0;
}