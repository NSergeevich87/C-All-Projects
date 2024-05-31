/** Задание 3. Симуляция работы компании
Что нужно сделать
Реализуйте симуляцию работы компании. В компании существует вертикальное управление с иерархией. 
Есть основные рабочие, подчинённые, разбитые на команды. У каждой команды есть менеджер среднего звена. 
Всей компанией руководит глава компании. У всех сотрудников, включая руководителя, есть имена.

Глава компании выполняет стратегическое управление. Он определяет основной вектор движения — задачи 
верхнего уровня. Менеджеры среднего звена разбивают эти задачи на подзадачи и раздают их своим подчинённым. 
Подчинённые выполняют работу.
• Реализация данной логики должна проходить упрощённым образом. Указания главы компании поступают из 
стандартного ввода и являются не более чем целочисленными идентификаторами.
• Данные идентификаторы служат зерном для генератора случайных чисел. Каждый из менеджеров, принимая 
себе эту целочисленную команду, добавляет к ней свой порядковый номер и вызывает с результирующей 
суммой функцию std::srand().
• На основе этой суммы вычисляется общее количество задач, которое требуется выполнить данной командой, 
— от 1 до количества работников в группе. Всего есть три типа задач для работников: A, B и C. Они тоже 
выбираются случайно и распределяются между незанятыми рабочими.
• При старте программы пользователь указывает в стандартном вводе количество команд и количество работников 
в каждой из команд.
• Далее пользователь вводит целые числа, которые соответствуют указаниям руководителя компании. 
Когда какой-то работник или менеджер получил указания или задачу, об этом сообщается в стандартный вывод, 
включая имя работающего сотрудника. Программа завершается, когда все работники заняты какими-то задачами.

Советы и рекомендации
Используйте иерархии классов для представления сотрудников и указатель this, если потребуется.
Чтобы проинициализировать генератор случайных чисел, используйте std::srand(hash); где hash — некое 
случайное и уникальное значение, например, ID вашей группы и команды. Для получения количества задач 
используйте полученный генератор случайных чисел так: int tasksCount = rand() % (team->workers.size() + 1);*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

class Worker
{
public:
    Worker(std::string inName) : name(inName) {}
    void getTask()
    {
        std::cout << "Worker " << name << " got task" << std::endl;
    }
protected:
    std::string name;
};

class Manager : public Worker
{
public:
    Manager(std::string inName) : Worker(inName) {}
    void getTask()
    {
        std::cout << "Manager " << name << " got task" << std::endl;
    }
};

class Boss : public Manager
{
public:
    Boss(std::string inName) : Manager(inName) {}
    void getTask()
    {
        std::cout << "Boss " << name << " got task" << std::endl;
    }
};

class Team
{
public:
    Team(int inWorkersCount, std::string inName) : workersCount(inWorkersCount), name(inName)
    {
        for (int i = 0; i < workersCount; i++)
        {
            workers.push_back(Worker(name + std::to_string(i)));
        }
    }
    void getTask(int task)
    {
        std::cout << "Team " << name << " got task " << task << std::endl;
        std::srand(task);
        int tasksCount = rand() % (workers.size() + 1);
        for (int i = 0; i < tasksCount; i++)
        {
            workers[i].getTask();
        }
    }
protected:
    int workersCount;
    std::string name;
    std::vector<Worker> workers;
};

int main()
{
    int teamsCount;
    std::cout << "Enter teams count: ";
    std::cin >> teamsCount;
    std::vector<Team> teams;
    for (int i = 0; i < teamsCount; i++)
    {
        int workersCount;
        std::cout << "Enter workers count for team " << i + 1 << ": ";
        std::cin >> workersCount;
        teams.push_back(Team(workersCount, "Team " + std::to_string(i)));
    }
    int task;
    
    for (int i = 0; i < teamsCount; i++)
    {
        std::cout << "Enter number of task for team " << i + 1 << ": ";
        std::cin >> task;
        teams[i].getTask(task);
    }
    return 0;
}