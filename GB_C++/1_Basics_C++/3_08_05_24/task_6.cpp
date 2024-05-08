/**
 * Задача 2. Обмен местами Что нужно сделать: 
 * Есть код программы с двумя переменными типа int и выводом этих переменных на экран. 
 * Напишите программу, которая меняет значения переменных местами, то есть нужно добиться того, 
 * чтобы в переменной a лежит значение b, а в b — значение a.
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class task_6
{
    public:
        void run()
        {
            int a = 5;
            int b = 10;
            int c{};
            cout << "Before swap: a = " << a << ", b = " << b << endl;
            
            c = a;
            a = b;
            b = c;

            cout << "After swap: a = " << a << ", b = " << b << endl;
        }
};