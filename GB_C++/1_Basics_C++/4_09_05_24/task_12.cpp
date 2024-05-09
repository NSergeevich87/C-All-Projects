/** Зарплата (дополнительное задание)
Что нужно сделать:
В отделе маркетинга работают три сотрудника. Их зарплаты могут быть как разными, так и одинаковыми. 
Напишите программу, которая вычисляет разницу между самой высокой и самой низкой зарплатами сотрудников, 
а также среднее арифметическое зарплат всех сотрудников отдела.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class task_12
{
    public:
        void run()
        {
            vector<double> salaries;

            cout << "Enter salary of first employee: ";
            double salary1;
            cin >> salary1;
            if (salary1 < 0)
            {
                cout << "Salary can't be negative. Try again." << endl;
                return;
            }
            salaries.push_back(salary1);
            cout << "Enter salary of second employee: ";
            double salary2;
            cin >> salary2;
            if (salary2 < 0)
            {
                cout << "Salary can't be negative. Try again." << endl;
                return;
            }
            salaries.push_back(salary2);
            cout << "Enter salary of third employee: ";
            double salary3;
            cin >> salary3;
            if (salary3 < 0)
            {
                cout << "Salary can't be negative. Try again." << endl;
                return;
            }
            salaries.push_back(salary3);
        
            double max_salary = *max_element(salaries.begin(), salaries.end());
            double min_salary = *min_element(salaries.begin(), salaries.end());
            double average_salary = 0;
            for (double salary : salaries)
            {
                average_salary += salary;
            }
            average_salary /= salaries.size(); 

            cout << "Highest salary: " << max_salary << endl;
            cout << "Difference between the highest and the lowest salaries: " << max_salary - min_salary << endl;
            cout << "Average salary: " << average_salary << endl;
            cin.ignore(32767, '\n');
        }
};