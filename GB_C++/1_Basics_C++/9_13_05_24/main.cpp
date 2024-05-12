#include <iostream>
#include <string>

using namespace std;

#include "task_1.cpp"
#include "task_2.cpp"

int main()
{
    bool quit = false;

    while (!quit)
    {
        cout << "This homework has 2 tasks:\n";
        cout << "1. Count word in text.\n";
        cout << "2. Check if string is repeated.\n";
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
        default:
            cout << "Task not found!" << endl;
            break;
        }
    }

    return 0;
}