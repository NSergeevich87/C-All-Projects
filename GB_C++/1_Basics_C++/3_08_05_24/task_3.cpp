#include <iostream>
#include <string>
#include <limits>

using namespace std;

class task_3
{
    public:
        void run()
        {
            string name;
            string race;

            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter race: ";
            getline(cin, race);

            cout << "Was born new "<< race << ", his name is " << name << ". Welcome to this wild world!" << endl;
        }
};