/** Задание 4. Реализация симуляции банкомата
Что нужно сделать
Требуется реализовать упрощённую симуляцию работы банкомата. В банкомате могут храниться только 
бумажные купюры номиналом от 100 до 5000 рублей. Максимально в банкомате может храниться только 1000 купюр. 
Все они записываются в отдельный файл. У банкомата, как у устройства, две основных операции — снятие денег 
пользователем и наполнение деньгами инкассаторами банка.

Наполнение банкомата происходит, если при старте программы в консоль вводится символ плюс “+”. 
Количество купюр рассчитывается так, чтобы банкомат был заполнен полностью. Все купюры при этом выбираются 
случайным образом.
Если на старте программы в консоль вводится минус (“-”), то симулируется снятие пользователем денег. 
Пользователь указывает сумму с точностью до 100 рублей. Мы будем считать, что каждый клиент обладает 
неограниченным балансом в системе и теоретически может снять любую сумму. На практике, если данная 
сумма не может быть снята из-за отсутствия подходящих денег в машине, показывается сообщение, 
что эта операция невозможна.
После выполнения любой из операций программа завершает выполнение. Состояние банкомата должно 
храниться в отдельном бинарном файле, автономно.*/

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

enum class BanknoteValue {
    V100 = 100,
    V500 = 500,
    V1000 = 1000,
    V2000 = 2000,
    V5000 = 5000
};

struct Banknote {
    BanknoteValue value;
};

void fillATM() 
{
    // Проверяем количество купюр в банкомате в файле atm.bin
    std::ifstream atmFile("atm.bin", std::ios::binary);
    if (!atmFile.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return;
    }

    std::vector<Banknote> banknotes;
    Banknote banknote;
    while (atmFile.read(reinterpret_cast<char*>(&banknote), sizeof(Banknote))) {
        banknotes.push_back(banknote);
    }
    atmFile.close();

    // Пополняем банкомат необходимым количеством случайных купюр из enum class BanknoteValue
    while (banknotes.size() < 1000) {
        Banknote newBanknote;
        switch (rand() % 5) {
            case 0:
                newBanknote.value = BanknoteValue::V100;
                break;
            case 1:
                newBanknote.value = BanknoteValue::V500;
                break;
            case 2:
                newBanknote.value = BanknoteValue::V1000;
                break;
            case 3:
                newBanknote.value = BanknoteValue::V2000;
                break;
            case 4:
                newBanknote.value = BanknoteValue::V5000;
                break;
        }
        banknotes.push_back(newBanknote);
    }

    // for (const auto& banknote : banknotes) {
    //     std::cout << static_cast<int>(banknote.value) << std::endl;
    // }

    // Записываем новое состояние банкомата в файл
    std::ofstream atmFileOut("atm.bin", std::ios::binary);
    if (!atmFileOut.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return;
    }

    for (const auto& banknote : banknotes) {
        atmFileOut.write(reinterpret_cast<const char*>(&banknote), sizeof(Banknote));
    }
    atmFileOut.close();
}

void withdrawMoney(int sum)
{
    // Снимаем деньги из банкомата из файла atm.bin
    std::ifstream atmFile("atm.bin", std::ios::binary);
    if (!atmFile.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return;
    }

    std::vector<Banknote> banknotes;
    Banknote banknote;
    while (atmFile.read(reinterpret_cast<char*>(&banknote), sizeof(Banknote))) {
        banknotes.push_back(banknote);
    }
    atmFile.close();

    // Снимаем деньги из банкомата учитывая номинал купюр и удаляем их из банкомата
    int sumTemp = sum;
    // Запишем индексы для удаления из вектора
    std::vector<int> indexes;
    for (auto banknote : banknotes) {
        if (sumTemp >= static_cast<int>(banknote.value)) {
            sumTemp -= static_cast<int>(banknote.value);
            // Сохраняем индекс купюры для удаления
            indexes.push_back(&banknote - &banknotes[0]);
        }
    }

    // Удаляем купюры из вектора
    for (int i = indexes.size() - 1; i >= 0; --i) {
        banknotes.erase(banknotes.begin() + indexes[i]);
    }

    if (sumTemp != 0) {
        std::cerr << "Error: operation is impossible, we dont have enaugh banknotes!" << std::endl;
        return;
    }

    // Записываем в файл оставшиеся купюры
    std::ofstream atmFileOut("atm.bin", std::ios::binary);
    if (!atmFileOut.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return;
    }

    for (const auto& banknote : banknotes) {
        atmFileOut.write(reinterpret_cast<const char*>(&banknote), sizeof(Banknote));
    }
    atmFileOut.close();

    std::cout << "Operation is successful!" << std::endl;
}

void printRest()
{
    // Выводим оставшиеся купюры в банкомате
    std::ifstream atmFile("atm.bin", std::ios::binary);
    if (!atmFile.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return;
    }

    std::vector<Banknote> banknotes;
    Banknote banknote;
    while (atmFile.read(reinterpret_cast<char*>(&banknote), sizeof(Banknote))) {
        banknotes.push_back(banknote);
    }
    atmFile.close();

    for (const auto& banknote : banknotes) {
        std::cout << static_cast<int>(banknote.value) << std::endl;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    char operation;
    std::cout << "Enter operation (+ or -) or = (to show rest): ";
    std::cin >> operation;

    if (operation == '+') {
        fillATM();
    }
    else if (operation == '-') {
        // Снимаем деньги
        int sum;
        std::cout << "Enter sum: ";
        std::cin >> sum;
        withdrawMoney(sum);
    }
    else if (operation == '=') {
        printRest();
    }
    else {
        std::cerr << "Error: invalid operation" << std::endl;
    }

    return 0;
}