/** Задание 4. Среднее арифметическое число в массиве
Что нужно сделать
Реализуйте шаблонную функцию подсчёта среднего арифметического числа 
в массиве скалярных чисел произвольного типа. Это может быть int, double, float и так далее.
Ввод данных массива и вывод результата производится через стандартную консоль.

Рекомендации
Для простоты можете реализовать подсчёт в массиве фиксированной длины.
Функцию ввода данных массива тоже рекомендуется реализовать как шаблонную.
Обе функции имеют похожую сигнатуру вида:

template < typename T >
void input(T array[8])
{
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
} */

#include <iostream>

template <typename T>
T average(T array[8])
{
    T sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        sum += array[i];
    }
    return sum / 8;
}

template <typename T>
void input(T array[8])
{
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
    }
}

int main()
{
    int array[8];
    input(array);
    std::cout << "Average: " << average(array) << std::endl;
    return 0;
}