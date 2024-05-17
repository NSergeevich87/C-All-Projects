#include <iostream>
#include <string>

using namespace std;

#include "task_1.cpp"
#include "task_2.cpp"
#include "task_3.cpp"
#include "task_4.cpp"

int main()
{
    bool quit = false;

    while (!quit)
    {
        cout << "This homework has 4 tasks:\n";
        cout << "1. Multifamily house\n";
        cout << "2. Sorting\n";
        cout << "3. Travel time\n";
        cout << "4. Array of numbers\n";
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
        
        string str;
        string crypt_str;

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
            default:
                cout << "Task not found!" << endl;
                break;
        }
    }

    return 0;
}