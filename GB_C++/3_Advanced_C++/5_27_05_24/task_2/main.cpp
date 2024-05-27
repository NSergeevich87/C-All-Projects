/** Задание 2. Вывод времени года
Что нужно сделать
Используя макросы вместе с условными директивами прекомпиляции (#if / #endif), реализуйте простую программу 
по выводу названия времени года в консоль.
Пользователь программы, который будет иметь дело с вашим кодом, в этом случае тоже программист. 
С помощью определения одного из макросов (в самом коде): SPRING, SUMMER, AUTUMN или WINTER он задаёт сезон, 
название, которое хочет увидеть на экране. При компиляции и запуске программы на экране должно появиться 
название именно этого сезона и только его.

Советы и рекомендации
Так как препроцессор работает до компиляции, то в #if/#endif-директивы вы можете обернуть всю функцию 
main сразу.*/

#include <iostream>

#define SPRING 1
#define SUMMER 2
#define AUTUMN 3
#define WINTER 4

using namespace std;

int main()
{
    cout << "Enter the season number: ";
    int season;
    cin >> season;

    if (season == SPRING)
        cout << "Spring" << endl;
    if (season == SUMMER)
        cout << "Summer" << endl;
    if (season == AUTUMN)
        cout << "Autumn" << endl;
    if (season == WINTER)
        cout << "Winter" << endl;

    return 0;
}