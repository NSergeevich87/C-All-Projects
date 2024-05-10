#include <iostream>

#include "task_1.cpp"
#include "task_2.cpp"
#include "task_3.cpp"
#include "task_4.cpp"
#include "task_5.cpp"
#include "task_6.cpp"
#include "task_7.cpp"
#include "task_8.cpp"
#include "task_9.cpp"
#include "task_10.cpp"
#include "task_11.cpp"
#include "task_12.cpp"
#include "task_13.cpp"
#include "task_14.cpp"
#include "task_15.cpp"

using namespace std;

int main()
{
    bool quit = false;

    while (!quit)
    {
        cout << "This homework has 1 tasks:\n";
        cout << "1. Coordinate plane\n";
        cout << "2. ATM\n";
        cout << "3. Leap year\n";
        cout << "4. Bridge and overload\n";
        cout << "5. Triangle\n";
        cout << "6. Matching numbers\n";
        cout << "7. Military enlistment office\n";
        cout << "8. Winnie the Pooh and the day of troubles\n";
        cout << "9. Time to have lunch\n";
        cout << "10. Normal flight\n";
        cout << "11. May holidays\n";
        cout << "12. May holidays - complication\n";
        cout << "13. ATM - 2\n";
        cout << "14. Brick - complication\n";
        cout << "15. Sad adulthood\n";
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
        else if (task == "9")
        {
            cout << "Task 9:\n";
            task_9 t9;
            t9.run();
        }
        else if (task == "10")
        {
            cout << "Task 10:\n";
            task_10 t10;
            t10.run();
        }
        else if (task == "11")
        {
            cout << "Task 11:\n";
            task_11 t11;
            t11.run();
        }
        else if (task == "12")
        {
            cout << "Task 12:\n";
            task_12 t12;
            t12.run();
        }
        else if (task == "13")
        {
            cout << "Task 13:\n";
            task_13 t13;
            t13.run();
        }
        else if (task == "14")
        {
            cout << "Task 14:\n";
            task_14 t14;
            t14.run();
        }
        else if (task == "15")
        {
            cout << "Task 15:\n";
            task_15 t15;
            t15.run();
        }
        else
        {
            cout << "Wrong task number.\n";
        }
    }

    return 0;
}