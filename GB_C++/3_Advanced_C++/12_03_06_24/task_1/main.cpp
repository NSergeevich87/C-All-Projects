/** Задание 1. Пользовательские запросы
Что нужно сделать
Реализуйте программу по осуществлению различных типов HTTP-запросов к сервису httpbin.org.
Пользователь взаимодействует с программой с помощью команд: “get”, “post”, “put”, “delete”, “patch”. 
В зависимости от команды к серверу httpbin.org осуществляется запрос того или иного типа. 
Содержимое ответа сервера выводится в стандартный вывод.
Программа завершается, когда пользователь вводит команду “exit”.

Рекомендации
Для каждого HTTP-запроса в CPR есть отдельный метод, например cpr::Get.*/
#include <iostream>
#include <cpr/cpr.h>

int main() 
{
    std::string command;
    while (true)
    {
        std::cin >> command;
        if (command == "exit")
        {
            break;
        }
        else if (command == "get")
        {
            cpr::Response r = cpr::Get(cpr::Url("https://httpbin.org/get"));
            std::cout << r.text << std::endl;
        }
        else if (command == "post")
        {
            cpr::Response r = cpr::Post(cpr::Url("https://httpbin.org/post"));
            std::cout << r.text << std::endl;
        }
        else if (command == "put")
        {
            cpr::Response r = cpr::Put(cpr::Url("https://httpbin.org/put"));
            std::cout << r.text << std::endl;
        }
        else if (command == "delete")
        {
            cpr::Response r = cpr::Delete(cpr::Url("https://httpbin.org/delete"));
            std::cout << r.text << std::endl;
        }
        else if (command == "patch")
        {
            cpr::Response r = cpr::Patch(cpr::Url("https://httpbin.org/patch"));
            std::cout << r.text << std::endl;
        }
    }
    return 0;
}
