#include <iostream>

using namespace std;

int main() 
{
    // task_1
    int apartmentPrice = 12'350'000;
    float shoeSize = 42.5;
    int animalsCount = 250;
    float newProductPrice = 12'500.50;

    // task_2 and task_3
    int sircle = 4;
    int speed = 358;
    string name = "Шумахер";
    int engine = 254;
    int wheels = 93;
    int steeringWheel = 49;
    int wind = -21;
    int rain = -17;

    cout << "--------------------------------" << endl;
    cout << "Супер гонки. Круг " << sircle << endl;
    cout << "--------------------------------" << endl;
    cout << "Шумахер (" << speed << "358)" << endl;
    cout << "--------------------------------" << endl;
    cout << "Водитель: " << name << endl;
    cout << "Скорость: " << speed << endl;
    cout << "-------------------" << endl;
    cout << "Оснащение:\n";
    cout << "Двигатель: +" << engine << "\n";
    cout << "Колеса: +" << wheels << "\n";
    cout << "Руль: +" << steeringWheel << "\n";
    cout << "-------------------" << endl;
    cout << "Действия плохой погоды\n";
    cout << "Ветер: " << wind << "\n";
    cout << "Дождь: " << rain << "\n";
    cout << "----------------task_3----------------" << endl;
    cout << "Auto speed: " << engine + wheels + steeringWheel + wind + rain << endl;

    // task_4
    float productPrice = 12'500.50;
    float deliveryPrice = 500.50;
    float discount = 100.50;
    cout << "----------------task_4----------------" << endl;
    cout << "Product price: " << productPrice << endl;
    cout << "Delivery price: " << deliveryPrice << endl;
    cout << "Discount: " << discount << endl;
    cout << "Total price: " << productPrice + deliveryPrice - discount << endl;

    // task_5
    int orderTime = 5;
    int serviceTime = 3;
    int clientsCount = 100;
    cout << "----------------task_5----------------" << endl;
    cout << "Order time: " << orderTime << " min" << endl;
    cout << "Service time: " << serviceTime << " min" << endl;
    cout << "Clients count: " << clientsCount << endl;
    cout << "Total time: " << orderTime + serviceTime << " min" << endl;
    cout << "Total clients: " << clientsCount / (orderTime + serviceTime) << " clients" << endl;

    // task_6
    float totalRepairCost = 1'000'000.50;
    int apartmentsCount = 100;
    cout << "----------------task_6----------------" << endl;
    cout << "Total repair cost: " << totalRepairCost << endl;
    cout << "Apartments count: " << apartmentsCount << endl;
    cout << "Total payment: " << totalRepairCost / apartmentsCount << endl;

    return 0;
}