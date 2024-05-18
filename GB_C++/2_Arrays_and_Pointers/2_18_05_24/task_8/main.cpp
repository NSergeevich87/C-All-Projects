/** Представим, что роботов могут не только покупать, забирая с витрины, но и “выставлять” в конец витрины. 
 * Пусть с клавиатуры вводят число K, а потом -- K запросов вида “1 n” и “2 m”. 
 * Запрос вида “1 n” означает, что в конец витрины поставили робота номер n. Запроc “2 m” означает, 
 * что из витрины забрали робота по индексу m. Необходимо смоделировать такое взаимодействие и после 
 * проведения всех запросов вывести на экран оставшихся на витрине роботов.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> buy_robot(vector<int> vec, int index) {
    vec.erase(vec.begin() + index);
    return vec;
}

vector<int> add_robot(vector<int> vec, int robot) {
    vec.push_back(robot);
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
    vector<int> robots {100, 200, 300, 400, 500};
    robots_left(robots);

    int K, robot;
    string request;
    cout << "Enter number of requests (1 n or 2 m): ";
    cin >> K;
    cin.ignore();

    for (int i = 0; i < K; ++i)
    {
        cout << "Enter request " << i + 1 << ":\n";
        getline(cin, request);
        if (request == "1 n") {
            cout << "Enter robot number to add: ";
            cin >> robot;
            cin.ignore();
            robots = add_robot(robots, robot);
            robots_left(robots);
        } else if (request == "2 m") {
            cout << "Enter robot index to buy: ";
            cin >> robot;
            cin.ignore();
            robots = buy_robot(robots, robot);
            robots_left(robots);
        }
        else {
            cout << "Invalid request\n";
        }
    }
    
    return 0;
}