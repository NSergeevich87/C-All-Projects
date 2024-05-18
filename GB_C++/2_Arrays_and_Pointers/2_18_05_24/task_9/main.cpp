/** С помощью push_back() реализуйте очередь из роботов-андроидов. 
 * Роботы приходят в очередь и называют(вводят с клавиатуры) свои порядковые номера (целые положительные). 
 * Последний робот в очереди всегда имеет номер -1. Когда он пришёл, необходимо вывести на экран 
 * все номера в очереди.*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> robots;
    int robot;

    while (robot != -1) {
        std::cout << "Enter robot number: ";
        std::cin >> robot;
        if (robot == -1) {
            for (int i = 0; i < robots.size(); ++i) {
                std::cout << robots[i] << " ";
            }
            break;
        }
        robots.push_back(robot);
    }
    return 0;
}