#include <iostream>
#include <list>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <array>

int main() {
    std::cout << std::fixed;
    std::list<int> my_list = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

    // Замер времени выполнения сортировки с помощью библиотеки алгоритмов
    auto start = std::chrono::high_resolution_clock::now();
    my_list.sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Library algorithm: " << elapsed_seconds.count() << " sec" << std::endl;

    // Замер времени выполнения сортировки с помощью функции контейнера
    start = std::chrono::high_resolution_clock::now();
    sort(std::greater<int>());
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << "Container function: " << elapsed_seconds.count() << " sec" << std::endl;

    return 0;
}
