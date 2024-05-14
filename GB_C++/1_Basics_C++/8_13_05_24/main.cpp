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
#include "task_17.cpp"
#include "task_18.cpp"
#include "task_19.cpp"
#include "task_20.cpp"
#include "task_21.cpp"

using namespace std;

int main()
{
    bool quit = false;

    while (!quit)
    {
        cout << "This homework has 0 tasks:\n";
        cout << "1. Almonds\n";
        cout << "2. Healthy lifestyle\n";
        cout << "3. Regular customer\n";
        cout << "4. Chatls\n";
        cout << "5. Computer vision\n";
        cout << "6. Weather station\n";
        cout << "7. Accuracy\n";
        cout << "8. Knight's move\n";
        cout << "9. Autopilot\n";
        cout << "10. Elevator\n";
        cout << "11. Gradient\n";
        cout << "12. Space simulator\n";
        cout << "13. Orc\n";
        cout << "14. Timber\n";
        cout << "15. Download\n";
        cout << "16. Kenyan runner\n";
        cout << "17. Pendulum\n";
        cout << "18. Friends of Ocean\n";
        cout << "19. Biolaboratory 2.0\n";
        cout << "20. Eggs\n";
        cout << "21. The hardest in learning, easy in battle\n";
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
            t1.run();
            break;
        case 2:
            task_2 t2;
            t2.run();
            break;
        case 3:
            task_3 t3;
            t3.run();
            break;
        case 4:
            task_4 t4;
            t4.run();
            break;
        case 5:
            task_5 t5;
            t5.run();
            break;
        case 6:
            task_6 t6;
            t6.run();
            break;
        case 7:
            task_7 t7;
            t7.run();
            break;
        case 8:
            task_8 t8;
            t8.run();
            break;
        case 9:
            task_9 t9;
            t9.run();
            break;
        case 10:
            task_10 t10;
            t10.run();
            break;
        case 11:
            task_11 t11;
            t11.run();
            break;
        case 12:
            task_12 t12;
            t12.run();
            break;
        case 13:
            task_13 t13;
            t13.run();
            break;
        case 14:
            task_14 t14;
            t14.run();
            break;
        case 15:
            task_15 t15;
            t15.run();
            break;
        case 16:
            task_16 t16;
            t16.run();
            break;
        case 17:
            task_17 t17;
            t17.run();
            break;
        case 18:
            task_18 t18;
            t18.run();
            break;
        case 19:
            task_19 t19;
            t19.run();
            break;
        case 20:
            task_20 t20;
            t20.run();
            break;
        case 21:
            task_21 t21;
            t21.run();
            break;
        default:
            cout << "Task not found!" << endl;
            break;
        }
    }

    return 0;
}