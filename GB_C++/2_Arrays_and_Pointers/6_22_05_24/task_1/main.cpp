/** Задача 1
Что нужно сделать:
Напишите функцию swapvec, принимающую std::vector<int> и указатель на массив переменных типа int 
(одного размера) и обменивающую значения этих массивов.

Пример:

std::vector<int> a = {1,2,3,4};
int b[] = {2,4,6,8};
swapvec(a,b);
for(int i = 0; i < 4; ++i)
std::cout << a[i];
std::cout << std::endl;
for(int i = 0; i < 4; ++i)
std::cout << b[i];

Вывод:
2468
1234*/

#include <iostream>
#include <vector>

using namespace std;

void swapvec(std::vector<int>& vec, int* arr)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        int temp = vec[i];
        vec[i] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    std::vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};
    swapvec(a,b);
    
    for(int i = 0; i < 4; ++i)
        std::cout << a[i];

    std::cout << std::endl;
    
    for(int i = 0; i < 4; ++i)
        std::cout << b[i];

    return 0;
}