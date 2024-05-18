/** На витрине стоят несколько роботов, у каждого есть свой номер. Номера задаются с клавиатуры 
 * (сначала вводится число n, потом -- n номеров роботов). 
 * Далее вводится число m и после этого -- m индексов (от 0 до количества оставшихся роботов на витрине). 
 * Когда введён очередной индекс -- робота покупают, то есть он покидает витрину, 
 * а остальные роботы “группируются”, смещаясь на один шаг назад. Необходимо вывести список оставшихся, 
 * после всех покупок, роботов.

Пример: на витрине стояли роботы {100, 200, 250, 300}. Сначала забрали робота с индексом 1, 
то есть с номером 200, осталось {100,250,300}. Потом забрали робота с индексом 1, то есть с номером 250, 
осталось {100,300}*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> buy_robot(vector<int> vec, int index) {
    vec.erase(vec.begin() + index);
    return vec;
}

void robots_left(vector<int> vec) {
    cout << "Robots left: ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> robots;
    int n, m, robot;
    cout << "Enter number of robots: ";
    cin >> n;
    cout << "Enter robots numbers: \n";
    for (int i = 0; i < n; ++i) {
        cin >> robot;
        robots.push_back(robot);
    }
    cout << "Enter number of robots to buy: ";
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cout << "Enter index of robot to buy: \n";
        cin >> robot;
        robots = buy_robot(robots, robot);
        robots_left(robots);
    }
    
    return 0;
}