/** Задание 1. Реализация продвинутого ввода и вывода дней недели
Что нужно сделать
Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу этого дня недели в текстовом 
виде в консоль.
В начале программы пользователь вводит день недели в виде его порядкового номера. В результате в 
консоли появляется буквенное отображение этого дня недели.
В этом упражнении запрещается использовать классические переменные, кроме как для хранения ввода 
пользователя. Использовать строковые литералы напрямую тоже нельзя. Всё должно быть реализовано 
исключительно на макросах.

Советы и рекомендации
Конкатенация двух фрагментов может породить токен, который в свою очередь является именем макроса, и 
этот макрос тоже раскроется. Используйте это свойство для перевода константы дня недели в строковый литерал.
Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью Shift-Shift → Preprocess current TU.*/

#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

#define DAY_OF_WEEK(day) #day

int main() {
    int day;
    std::cout << "Enter the day of the week: ";
    std::cin >> day;
    switch (day) {
        case MONDAY:
            std::cout << DAY_OF_WEEK(MONDAY) << std::endl;
            break;
        case TUESDAY:
            std::cout << DAY_OF_WEEK(TUESDAY) << std::endl;
            break;
        case WEDNESDAY:
            std::cout << DAY_OF_WEEK(WEDNESDAY) << std::endl;
            break;
        case THURSDAY:
            std::cout << DAY_OF_WEEK(THURSDAY) << std::endl;
            break;
        case FRIDAY:
            std::cout << DAY_OF_WEEK(FRIDAY) << std::endl;
            break;
        case SATURDAY:
            std::cout << DAY_OF_WEEK(SATURDAY) << std::endl;
            break;
        case SUNDAY:
            std::cout << DAY_OF_WEEK(SUNDAY) << std::endl;
            break;
        default:
            std::cout << "Invalid day of the week" << std::endl;
    }
    return 0;
}