/** Задача 3
Что нужно сделать:
Написать функцию, которая принимает указатель на char, по которому лежит строка.
Функция должна возвращать true, если вторая строка является подстрокой первой.

Пример:
const char* a = "Hello world";
const char* b = "wor";
const char* c = "banana";
std::cout << substr(a,b) << " " << substr(a,c);
// true false*/

#include <iostream>

bool substr(const char* a, const char* b)
{
    int i = 0;
    int j = 0;
    while (a[i] != '\0')
    {
        if (a[i] == b[j])
        {
            j++;
            if (b[j] == '\0')
            {
                return true;
            }
        }
        else
        {
            j = 0;
        }
        i++;
    }

    return false;
}

int main()
{
    std::boolalpha(std::cout);

    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";
    std::cout << substr(a,b) << " " << substr(a,c);

    return 0;
}