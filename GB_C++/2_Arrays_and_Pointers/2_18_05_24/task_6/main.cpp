/** Роботы и коррупция*
Улучшите электронную очередь для роботов. К нам приходят роботы разного социального статуса. 
Каждый робот вводит не только свой уникальный номер, но и свое место в очереди. Например, 
пусть в нашей очереди 10 роботов и к нам приходит 11-й. Сначала он вводит свой номер, как и раньше, 
а затем свое место в очереди - например, 5. В этом случае он должен оказаться в очереди пятым, 
а все остальные, начиная со старого пятого - подвинуться дальше в конец очереди.
Реализуйте функцию std::vector<int> add_to_position(std::vector vec, int val, int position)*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> add_to_position(vector<int> vec, int val, int position) {
    vec.insert(vec.begin() + position - 1, val);
    return vec;
}

int main() {
    vector<int> robots { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int robot, position;
    
    while (robot != -1) {
        cout << "Enter identification number of robot (-1 for last one): \n";
        cin >> robot;

        if (robot != -1) {
            cout << "Enter position of robot in the queue: \n";
            cin >> position;
            robots = add_to_position(robots, robot, position);
        }
    }
    cout << "Robots in the queue: ";
    for (int i = 0; i < robots.size(); ++i) {
        cout << robots[i] << " ";
    }
    cout << endl;
    return 0;
}