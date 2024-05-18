/** Напишите программу для картотеки пациентов лечебницы. 
 * С клавиатуры вводится неизвестное количество целых положительных чисел - возрастов пациентов. 
 * Когда пациенты заканчиваются, медсестра вводит число -1. Это говорит программе о том, 
 * что пора заканчивать с приемом пациентов и переходить к расчету статистики.

Напишите программу, складывающую в вектор целые положительные числа, пока не поступит отрицательное число. 
После этого выведите среднее значение всех введенных чисел и их количество.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> patients;
    int patient;
    cout << "Enter the age of the patient (-1 for quit): \n";
    while (patient != -1) {
        cin >> patient;
        if (patient != -1) {        
            patients.push_back(patient);
        }
    }
    int sum = 0;
    for (int i = 0; i < patients.size(); ++i) {
        sum += patients[i];
    }
    cout << "Average age of patients: " << sum / patients.size() << endl;
    cout << "Number of patients: " << patients.size() << endl;
    return 0;
}