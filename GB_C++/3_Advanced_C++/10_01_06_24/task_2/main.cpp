/** Задание 2. Симуляция работы вокзала
Что нужно сделать
С помощью многопоточности реализуйте простую модель железнодорожного вокзала.
С трёх точек отправления в разное время отбывают три разных поезда с условными обозначениями A, B, C. 
Все они идут на один и тот же вокзал и могут дойти до него в разное время.
На этом целевом вокзале единовременно может находиться только один поезд. Остальные поезда должны ждать, 
пока уже занятое место освободится.
В начале программы пользователь последовательно вводит для каждого поезда время в пути до вокзала 
(в секундах). После этого поезда начинают своё движение за заданное количество времени. Как только 
поезд прибыл на вокзал, он ожидает от пользователя команды depart, которая сигнализирует о его отбытии 
с вокзала.
По всем событиям (прибытие на вокзал, ожидание свободного места, отбытие с вокзала) вместе с условным 
обозначением поезда выводятся сообщения в консоль.
Программа завершается, когда на вокзале побывают все три поезда.

Советы и рекомендации
Используйте для вокзала отдельный мьютекс и симулируйте ожидание с помощью него.*/

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <chrono>

std::mutex station_access;
std::vector<std::string> station;
std::vector<std::string> trains = {"A", "B", "C"};
bool is_station_busy = false;

void train_arrival(std::string train_name, int travel_time) {
    std::this_thread::sleep_for(std::chrono::seconds(travel_time));
    station_access.lock();
    if (is_station_busy) {
        std::cout << "Train " << train_name << " is waiting for the station to be free\n";
        station_access.unlock();
    } else {
        is_station_busy = true;
        station.push_back(train_name);
        std::cout << "Train " << train_name << " has arrived at the station\n";
        station_access.unlock();
    }
}

void train_departure(std::string train_name) {
    station_access.lock();
    if (station.size() > 0) {
        std::cout << "Train " << station[0] << " has left the station\n";
        station.erase(station.begin());
    } else {
        is_station_busy = false;
    }
    station_access.unlock();
}

int main() {
    std::vector<std::thread> threads;
    int travel_time;
    for (int i = 0; i < 3; i++) {
        std::cout << "Enter travel time for train " << trains[i] << " in seconds: ";
        std::cin >> travel_time;
        threads.push_back(std::thread(train_arrival, trains[i], travel_time));
    }
    for (int i = 0; i < 3; i++) {
        threads[i].join();
    }
    while (station.size() > 0)
    {
        std::string command;
        std::cout << "Enter depart command\n";
        std::cin >> command;
        if (command == "depart")
        {
            train_departure(station[0]);
        }
    }
    return 0;
}