/** Задача 2
Что нужно сделать:
Написать функцию, которая принимает указатель на тип int, по которому размещены 10 переменных типа int. 
Функция ничего не возвращает, но по тому же указателю элементы должны лежать в обратном порядке.*/

#include <iostream>

void reverse(int *ptr, int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = ptr[i];
        ptr[i] = ptr[size - i - 1];
        ptr[size - i - 1] = temp;
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ptr = arr;

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    reverse(ptr, size);
    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}