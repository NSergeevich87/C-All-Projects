/** Задание 3. Симуляция работы кухни онлайн-ресторана
Что нужно сделать
Требуется реализовать упрощённую модель работы кухни ресторана, работающего в режиме онлайн-доставки.
Онлайн-заказ поступает каждые 5–10 секунд. Это случайное блюдо из пяти: пицца, суп, стейк, салат, суши. 
Официант, принявший заказ онлайн, оставляет его у кухни. Если кухня свободна, она принимает заказ 
и спустя 5–15 секунд возвращает уже готовое блюдо на выдачу. Время определяется случайным образом 
с помощью функции std::rand() в указанных диапазонах.
Курьер приезжает каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по заказчикам.
Программа завершается после 10 успешных доставок. На каждом из этапов, будь то заказ, или готовка, 
или доставка заказа, выводятся соответствующие сообщения в консоль.

Советы и рекомендации
Для симуляции готовки, используйте отдельный мьютекс и запускайте отдельную нить ожидания с вызовом 
detach для неё.*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <string>
#include <ctime>
#include <cstdlib>

std::mutex mtx;
std::condition_variable cv;
std::queue<std::string> orders;
bool ready = false;
bool finished = false;
int count = 0;

void kitchen()
{
    while (!finished)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !orders.empty(); });
        std::string order = orders.front();
        orders.pop();
        lock.unlock();
        std::cout << "Cooking " << order << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5 + std::rand() % 11));
        std::cout << "Ready " << order << std::endl;
        count++;
        if (count == 10)
        {
            finished = true;
        }
    }
}

void waiter()
{
    while (!finished)
    {
        std::unique_lock<std::mutex> lock(mtx);
        std::string order;
        switch (std::rand() % 5)
        {
        case 0:
            order = "Pizza";
            break;
        case 1:
            order = "Soup";
            break;
        case 2:
            order = "Steak";
            break;
        case 3:
            order = "Salad";
            break;
        case 4:
            order = "Sushi";
            break;
        }
        orders.push(order);
        std::cout << "Order " << order << std::endl;
        lock.unlock();
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(5 + std::rand() % 6));
    }
}

void courier()
{
    while (!finished)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !orders.empty(); });
        std::string order = orders.front();
        orders.pop();
        lock.unlock();
        std::cout << "Delivering " << order << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::srand(std::time(nullptr));
    std::thread t1(kitchen);
    std::thread t2(waiter);
    std::thread t3(courier);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}