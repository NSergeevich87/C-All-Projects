/** Роботы приходят в очередь и называют(вводят с клавиатуры) свои порядковые номера (целые положительные). 
 * Комната, в которой роботы-андроиды занимают своё место, имеет ограниченный размер 
 * (который равен capacity вектора, в который вы их записываете). Когда комната заполняется, 
 * роботам приходится “переходить” в другую комнату, чуть больше (но вы этого не видите). 
 * Необходимо отследить, когда в комнате будет оставаться всего 2 свободных места для роботов, 
 * и вывести сообщение об этом на экран.
Последний робот будет иметь номер -1.*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> robots;
    int robot;
    int capacity = 10;
    while (robot != -1) {
        std::cout << "Enter robot number: ";
        std::cin >> robot;
        if (robot == -1) {
            for (int i = 0; i < robots.size(); ++i) {
                std::cout << robots[i] << " ";
            }
            std::cout << "\nSize: " << robots.size() << std::endl;
            std::cout << "Capacity: " << robots.capacity() << std::endl;
            break;
        }
        robots.push_back(robot);
        if (robots.size() == capacity - 2) {
            std::cout << "Only 2 places left!" << std::endl;
        }
    }
    return 0;
}