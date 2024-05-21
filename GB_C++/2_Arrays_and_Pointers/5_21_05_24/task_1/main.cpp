/** Задача 1
Что нужно сделать:
Написать функцию, принимающую два указателя на int и меняет местами содержимое данных указателей.
Пример:
```
int a = 10;

int b = 20;

swap(&a, &b);

std::cout << a << “ “ << b;

// 20 10
``
[]()*/

#include <iostream>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;
    int b = 20;
    int *ptr_a = &a;
    int *ptr_b = &b;

    std::cout << "a = " << a << " b = " << b << std::endl;

    swap(ptr_a, ptr_b);

    std::cout << "a = " << a << " b = " << b << std::endl;

    return 0;
}