/** Таблица степеней.

Напишите программу, которая выводила бы N первых степеней числа К. 
Посмотрите, что случится, если N или K будут достаточно большими.*/

#include <iostream>
#include <cmath>

using namespace std;

class task_3
{
public:
    void run()
    {
        int N, K;
        cout << "Enter K: ";
        cin >> K;
        cout << "Enter N: ";
        cin >> N;

        for (int i = 1; i <= N; i++)
        {
            cout << K << " ^ " << i << " = " << pow(K, i) << endl;
        }

        cin.ignore(32767, '\n');
    }
};