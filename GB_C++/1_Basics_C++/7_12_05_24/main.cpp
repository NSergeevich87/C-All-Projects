#include <iostream>
#include <string>

// #include "task_1.cpp"
// #include "task_2.cpp"
// #include "task_3.cpp"
// #include "task_4.cpp"
// #include "task_5.cpp"
// #include "task_6.cpp"
// #include "task_7.cpp"
// #include "task_8.cpp"
// #include "task_9.cpp"
// #include "task_10.cpp"
// #include "task_11.cpp"
// #include "task_12.cpp"
// #include "task_13.cpp"
// #include "task_14.cpp"
// #include "task_15.cpp"
// #include "task_16.cpp"
// #include "task_17.cpp"
// #include "task_18.cpp"

using namespace std;

int main()
{
    bool quit = false;

    while (!quit)
    {
        cout << "This homework has 0 tasks:\n";
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
            // task_1();
            break;
        default:
            cout << "Task not found!" << endl;
            break;
        }
    }

    return 0;
}