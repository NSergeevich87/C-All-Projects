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
#include "task_16.cpp"
#include "task_17.cpp"
#include "task_18.cpp"

using namespace std;

int main()
{
    bool quit = false;

    while (!quit)
    {
        cout << "This homework has 18 tasks:\n";
        cout << "1. Boss_and_his_ask.\n";
        cout << "2. Buy_an_elephant.\n";
        cout << "3. Table_of_powers.\n";
        cout << "4. Reminder.\n";
        cout << "5. ATM_3.0.\n";
        cout << "6. Sum_of_numbers.\n";
        cout << "7. ATM_4.0.\n";
        cout << "8. Square_of_the_plot.\n";
        cout << "9. Leather_bag.\n";
        cout << "10. Military_time.\n";
        cout << "11. Cuckoo.\n";
        cout << "12. Too_large_numbers.\n";
        cout << "13. Collectors.\n";
        cout << "14. Lucky_ticket.\n";
        cout << "15. Fibonacci_numbers.\n";
        cout << "16. Deposits.\n";
        cout << "17. Fractions.\n";
        cout << "18. Guess_the_number.\n";
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
        else if (task == "16")
        {
            cout << "Task 16:\n";
            task_16 t16;
            t16.run();
        }
        else if (task == "17")
        {
            cout << "Task 17:\n";
            task_17 t17;
            t17.run();
        }
        else if (task == "18")
        {
            cout << "Task 18:\n";
            task_18 t18;
            t18.run();
        }
        else
        {
            cout << "Wrong task number.\n";
        }
    }

    return 0;
}