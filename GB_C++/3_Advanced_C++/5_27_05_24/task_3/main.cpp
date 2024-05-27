/** Задание 3. Анализ заполненности вагонов в поезде* (дополнительное задание)
Что нужно сделать
В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20 пассажиров — это их 
оптимальное количество. Проанализируйте количество людей в каждом вагоне и сначала сообщите об 
излишне заполненных вагонах, далее о вагонах с пустыми пассажирскими местами. В заключение выведите 
общее количество пассажиров во всех вагонах.
При старте программы пользователь вводит количество пассажиров в каждом вагоне. Замечания о вагонах 
должны выводиться в стандартную консоль.
При выполнении задания пользоваться нельзя напрямую пользоваться for-циклами, только опосредованно, 
через макросы.

Советы и рекомендации
С помощью макроса реализуйте модульный способ вызова функции над элементами массива. Сами функции 
реализуйте отдельно, в виде обычных классических функций (не макросов).
Модульный способ вызова функции печати текста через макрос:
```

define CALL(func) { func("Hello, GeekBrains!"); }
void print(std::string str) {
std::cout << str << std::endl;
}

int main() {
CALL(print);
return 0;
}
```*/

#include <iostream>
#include <string>

#define CALL(func) { func(); }
#define WAGON_1 1
#define WAGON_2 2
#define WAGON_3 3
#define WAGON_4 4
#define WAGON_5 5
#define WAGON_6 6
#define WAGON_7 7
#define WAGON_8 8
#define WAGON_9 9
#define WAGON_10 10

int wagon_1 = 0;
int wagon_2 = 0;
int wagon_3 = 0;
int wagon_4 = 0;
int wagon_5 = 0;
int wagon_6 = 0;
int wagon_7 = 0;
int wagon_8 = 0;
int wagon_9 = 0;
int wagon_10 = 0;

void checkWagon(int wagon, int passengers) {
    if (passengers > 20) {
        std::cout << "There are too many passengers in wagon " << wagon << std::endl; // В вагоне  излишне много пассажиров
    } else if (passengers < 20) {
        std::cout << "In wagon " << wagon << " there are free seats" << std::endl; // В вагоне  есть свободные места
    }
}

void checkAllWagons() {
    checkWagon(WAGON_1, wagon_1);
    checkWagon(WAGON_2, wagon_2);
    checkWagon(WAGON_3, wagon_3);
    checkWagon(WAGON_4, wagon_4);
    checkWagon(WAGON_5, wagon_5);
    checkWagon(WAGON_6, wagon_6);
    checkWagon(WAGON_7, wagon_7);
    checkWagon(WAGON_8, wagon_8);
    checkWagon(WAGON_9, wagon_9);
    checkWagon(WAGON_10, wagon_10);
}

int main() {
    std::cout << "Enter the number of passengers in each wagon" << std::endl; // "Введите количество пассажиров в каждом вагоне
    std::cin >> wagon_1 >> wagon_2 >> wagon_3 >> wagon_4 >> wagon_5 >> wagon_6 >> wagon_7 >> wagon_8 >> wagon_9 >> wagon_10;
    checkAllWagons();
    std::cout << "Total number of passengers in all wagons: " << wagon_1 + wagon_2 + wagon_3 + wagon_4 + wagon_5 + wagon_6 + wagon_7 + wagon_8 + wagon_9 + wagon_10 << std::endl; // "Общее количество пассажиров во всех вагонах: "
    return 0;
}
