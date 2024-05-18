/** Напишите электронную очередь для андроидов. Их количество неизвестно заранее. 
 * Каждый андроид вводит с клавиатуры свой идентификационный номер - целое число. 
 * Нужно сохранить их номера в векторе в том порядке, в котором они записывались в очередь.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> androids;
    int android;
    cout << "Enter identification number of android (-1 for last one): \n";
    while (android != -1) {
        cin >> android;
        androids.push_back(android);
    }
    cout << "Androids in the queue: ";
    for (int i = 0; i < androids.size(); ++i) {
        cout << androids[i] << " ";
    }
    cout << endl;
    return 0;
}