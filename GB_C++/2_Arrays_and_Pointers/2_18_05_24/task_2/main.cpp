/** Пользователь вводит с клавиатуры число n, а затем -- n действительных (дробных) чисел. 
 * Необходимо вывести их все в обратном порядке 
 * (то есть сначала то число, которые пользователь ввел последним и так далее).*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<double> numbers(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter the number: " << i + 1 << " ";
        cin >> numbers[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}