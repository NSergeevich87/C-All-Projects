/** Задание 1. Заплыв на 100 метров
Что нужно сделать
Реализуйте симуляцию состязаний по заплыву на 100 метров.
Всего шесть дорожек и шесть пловцов. Имена пловцов указываются вначале из стандартного ввода. 
Каждый из них плывёт с разной скоростью, которая также задаётся пользователем при старте, через 
стандартный ввод в метрах в секунду.
Каждую секунду в стандартный вывод выдаётся информация о том, сколько проплыл тот или иной пловец.
Как только все пловцы коснулись 100-метровой отметки, заплыв заканчивается и выводится таблица с 
итоговыми результатами, отсортированная по возрастанию итогового времени заплыва.

Советы и рекомендации
Используйте threads для реализации движения каждого пловца в отдельности.*/

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>

std::vector<std::string> names;
std::vector<double> speeds;
std::vector<double> distances;
std::mutex access;

void swimmer(int index)
{
    while(distances[index] < 100)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        distances[index] += speeds[index];
        access.lock();
        std::cout << names[index] << " swam " << distances[index] << " meters" << std::endl;
        access.unlock();
    }
}

int main()
{
    for(int i = 0; i < 6; i++)
    {
        std::string name;
        double speed;
        std::cout << "Enter the name of the swimmer: ";
        std::cin >> name;
        names.push_back(name);
        std::cout << "Enter the speed of the swimmer: ";
        std::cin >> speed;
        speeds.push_back(speed);
        distances.push_back(0);
    }

    std::vector<std::thread> threads;
    for(int i = 0; i < 6; i++)
    {
        threads.push_back(std::thread(swimmer, i));
    }

    for(int i = 0; i < 6; i++)
    {
        threads[i].join();
    }

    std::vector<std::pair<std::string, double>> results;
    for(int i = 0; i < 6; i++)
    {
        results.push_back(std::make_pair(names[i], distances[i] / speeds[i]));
    }

    std::sort(results.begin(), results.end(), [](std::pair<std::string, double> a, std::pair<std::string, double> b) { return a.second < b.second; });

    for(auto i : results)
    {
        std::cout << i.first << " finished in " << i.second << " seconds" << std::endl;
    }

    return 0;
}