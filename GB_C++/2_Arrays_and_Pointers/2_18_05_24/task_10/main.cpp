/** Робот приходит в очередь и заставляет уходить из конца очереди всех, чей номер меньше, 
 * чем у него, а потом становится в очередь сам. Последний робот будет иметь номер -1 
 * (и, соответственно, не сможет никого выгнать, так как остальные имеют положительные номера). 
 * Когда он пришёл, нужно вывести все номера в очереди на экран.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> robots;
    int robot;

    while (robot != -1) {
        cout << "Enter robot number: ";
        cin >> robot;
        if (robot == -1) {
            for (int i = 0; i < robots.size(); ++i) {
                cout << robots[i] << " ";
            }
            break;
        }
        for (int i = 0; i < robots.size(); ++i) {
            if (robots[i] < robot) {
                robots.erase(robots.begin() + i);
                i--;
            }
        }
        robots.push_back(robot);
    }
    return 0;
}