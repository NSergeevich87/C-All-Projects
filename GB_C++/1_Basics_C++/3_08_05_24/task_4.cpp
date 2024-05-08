#include <iostream>
#include <string>
#include <limits>

using namespace std;

class task_4
{
    public:
        void run()
        {
            string login;
            string pussword;

            cout << "Enter login: ";
            getline(cin, login);
            cout << "Enter password: ";
            getline(cin, pussword);

            cout << login << " you entered with success!" << endl;
        }
};