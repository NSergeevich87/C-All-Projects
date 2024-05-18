/** Пользователь вводит с клавиатуры число n, а затем -- n целых чисел.
Необходимо вычислить их среднее арифметическое и вывести на экран.*/

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter the number: " << i + 1 << " ";
        std::cin >> numbers[i];
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }
    std::cout << "AVG: " << static_cast<double>(sum) / n << std::endl;
    return 0;
}