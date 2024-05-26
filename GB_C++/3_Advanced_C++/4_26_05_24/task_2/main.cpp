/** Задание 2. Регистратура
Что нужно сделать
Напишите программу «Регистратура».
На вход программе приходят строки с фамилиями или строка Next. Пришедшие люди становятся в очередь, 
а по запросу Next необходимо вызвать в регистратуру человека с фамилией, идущей первой в 
лексикографическом порядке (по алфавиту), и вывести его фамилию на экран. Фамилии пациентов 
могут повторяться.
Каждый запрос (на добавление и вывод) должен работать за O(logn).

Пример:

← Sidorov
← Ivanov
← Ivanov
← Petrov
← Next
→ Ivanov
← Next
→ Ivanov
← Next
→ Petrov

Чек-лист для проверки задачи
• Программа корректно выводит фамилии в лексикографическом порядке.
• Программа использует только заголовочные файлы <iostream>, <string>, <map>.*/

#include <iostream>
#include <string>
#include <map>

void addPatient(std::map<std::string, int>& patients, const std::string& patient) {
    patients[patient]++;
}

void nextPatient(std::map<std::string, int>& patients) {
    if (patients.empty()) {
        std::cout << "The queue is empty" << std::endl;
        return;
    }
    auto it = patients.begin();
    std::cout << it->first << std::endl;
    if (--it->second == 0) {
        patients.erase(it);
    }
}

int main() {
    std::map<std::string, int> patients;
    std::string patient;
    while (true) {
        std::cout << "<- ";
        std::cin >> patient;
        if (patient == "Next") {
            nextPatient(patients);
        } else {
            addPatient(patients, patient);
        }
    }
    return 0;
}