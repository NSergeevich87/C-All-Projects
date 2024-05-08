#include <iostream>
#include <string>
#include <limits>

#include "task_1.cpp"
#include "task_2.cpp"
#include "task_3.cpp"
#include "task_4.cpp"
#include "task_5.cpp"
#include "task_6.cpp"
#include "task_7.cpp"
#include "task_8.cpp"

using namespace std;

int main() 
{
    bool quit = false;

    while (!quit)
    {
        cout << "This homework has 7 tasks:\n";
        cout << "1. Scuare of numbers.\n";
        cout << "2. Recalc price of item.\n";
        cout << "3. Create a character.\n";
        cout << "4. Logging.\n";
        cout << "5. Bus simulator.\n";
        cout << "6. Swap two numbers.\n";
        cout << "7. Bamboo height.\n";
        cout << "8. Star * Swap two numbers.\n";
        cout << "Enter number of task or 'q' for quit: ";
        string task;
        getline(cin, task);
        if (task == "q" || task == "Q")
        {
            quit = true;
        }
        else if (task == "1")
        {
            cout << "Task 1:\n";
            task_1 t1;
            t1.run();
        }
        else if (task == "2")
        {
            cout << "Task 2:\n";
            task_2 t2;
            t2.run();
        }
        else if (task == "3")
        {
            cout << "Task 3:\n";
            task_3 t3;
            t3.run();
        }
        else if (task == "4")
        {
            cout << "Task 4:\n";
            task_4 t4;
            t4.run();
        }
        else if (task == "5")
        {
            cout << "Task 5:\n";
            task_5 t5;
            t5.run();
        }
        else if (task == "6")
        {
            cout << "Task 6:\n";
            task_6 t6;
            t6.run();
        }
        else if (task == "7")
        {
            cout << "Task 7:\n";
            task_7 t7;
            t7.run();
        }
        else if (task == "8")
        {
            cout << "Task 8:\n";
            task_8 t8;
            t8.run();
        }
        else
        {
            cout << "Wrong task number.\n";
        }
    }

    return 0;
}