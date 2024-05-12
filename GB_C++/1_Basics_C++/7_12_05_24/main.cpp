#include <iostream>
#include <string>

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

using namespace std;

int main()
{
    bool quit = false;

    while (!quit)
    {
        cout << "This homework has 16 tasks:\n";
        cout << "1. Cuckoo (loop for).\n";
        cout << "2. Sum of numbers (loop for).\n";
        cout << "3. Multiplication table (loop for).\n";
        cout << "4. Sum of odd numbers.\n";
        cout << "5. Chief (loop for).\n";
        cout << "6. Password (loop for).\n";
        cout << "7. Cadastre problems (loop for).\n";
        cout << "8. Tough nut (loop for).\n";
        cout << "9. Food supplies (loop for).\n";
        cout << "10. Coffee machine (loop while).\n";
        cout << "11. Red Mars (loop while).\n";
        cout << "12. Frame (loop for).\n";
        cout << "13. Coordinate axes (loop for).\n";
        cout << "14. Important announcements (loop for).\n";
        cout << "15. Bio lab (loop while).\n";
        cout << "16. Christmas tree (loop for).\n";
        cout << "Enter number of task or 'q' for quit: ";
        string task;
        getline(cin, task);

        if (task == "q")
        {
            quit = true;
            break;
        }

        int task_number = 0;
        try
        {
            task_number = stoi(task);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Wrong number!" << '\n';
        }
        
        switch (task_number)
        {
        case 1:
            task_1 t1;
            t1.cuckoo();
            break;
        case 2:
            task_2 t2;
            t2.sum();
            break;
        case 3:
            task_3 t3;
            t3.multiplication_table();
            break;
        case 4:
            task_4 t4;
            t4.sum_odd();
            break;
        case 5:
            task_5 t5;
            t5.chief();
            break;
        case 6:
            task_6 t6;
            t6.password();
            break;
        case 7:
            task_7 t7;
            t7.cadastre();
            break;
        case 8:
            task_8 t8;
            t8.bomb();
            break;
        case 9:
            task_9 t9;
            t9.buckwheat();
            break;
        case 10:
            task_10 t10;
            t10.coffee_machine();
            break;
        case 11:
            task_11 t11;
            t11.red_mars();
            break;
        case 12:
            task_12 t12;
            t12.frame();
            break;
        case 13:
            task_13 t13;
            t13.coordinate_axes();
            break;
        case 14:
            task_14 t14;
            t14.important_announcements();
            break;
        case 15:
            task_15 t15;
            t15.bio_lab();
            break;
        case 16:
            Task16 t16;
            t16.christmas_tree();
            break;
        default:
            cout << "Task not found!" << endl;
            break;
        }
    }

    return 0;
}