/** Задание 1. Реализация программы учёта времени
Что нужно сделать
Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.
Пользователь взаимодействует с программой с помощью команд:
• Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен 
ввести название задачи, над которой он планирует сейчас работать. Если уже была начата какая-то 
другая задача, предыдущая должна быть автоматически завершена и начата новая.
• Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда 
ничего не делает.
• Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на 
них потрачено. Также выводится название текущей выполняемой задачи, если таковая имеется.
• Команда exit выходит из программы.

Советы и рекомендации
Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, которое было затрачено.
*/

#include <iostream>
#include <ctime>
#include <string>
#include <vector>

// Структура для хранения задачи
struct Task {
    std::string name;
    std::time_t start_time;
    std::time_t end_time;
};

// Функция для вывода времени в формате часы:минуты:секунды
void print_time(std::time_t time) {
    std::tm* timeinfo = std::localtime(&time);
    std::cout << timeinfo->tm_hour << ":" << timeinfo->tm_min << ":" << timeinfo->tm_sec;
}

int main() {
    std::vector<Task> tasks; // Вектор для хранения задач
    std::string command; // Переменная для хранения команды пользователя
    Task current_task; // Текущая задача

    while (true) {
        std::cout << "Enter command (begin/end/status/exit): ";
        std::cin >> command;

        if (command == "begin") {
            if (current_task.name != "") {
                // Если текущая задача уже начата, завершаем её
                current_task.end_time = std::time(nullptr);
                tasks.push_back(current_task);
            }

            // Начинаем новую задачу
            std::cout << "Enter task name: ";
            std::cin >> current_task.name;
            current_task.start_time = std::time(nullptr);
        } else if (command == "end") {
            if (current_task.name != "") {
                // Если текущая задача начата, завершаем её
                current_task.end_time = std::time(nullptr);
                tasks.push_back(current_task);
                current_task.name = "";
            }
        } else if (command == "status") {
            // Выводим информацию о всех задачах
            for (const Task& task : tasks) {
                std::cout << "Task: " << task.name << ", Start time: ";
                print_time(task.start_time);
                std::cout << ", End time: ";
                print_time(task.end_time);
                std::cout << std::endl;
            }

            // Выводим информацию о текущей задаче
            if (current_task.name != "") {
                std::cout << "Current task: " << current_task.name << std::endl;
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command" << std::endl;
        }
    }

    return 0;
}