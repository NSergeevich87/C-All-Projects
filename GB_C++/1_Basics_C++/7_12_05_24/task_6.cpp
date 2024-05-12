/** Пароль (цикл for).
Перепишите программу из прошлого модуля, только теперь вместо цикла while используйте цикл for. 
Программа просит пользователя ввести пароль. Если пароль неверный, программа просит сделать это снова, 
и так до тех пор, пока пользователь не введёт правильный пароль.*/

#include <iostream>
#include <string>

using namespace std;

class task_6
{
    public:
        void password()
        {
            string password = "password";
            string user_password;
            for (int i = 0; i < 1000; i++)
            {
                cout << "Enter password: \n";
                cout << "Password is 'password'\n";
                getline(cin, user_password);
                if (user_password == password)
                {
                    cout << "Password is correct!\n";
                    break;
                }
                else
                {
                    cout << "Access denied!" << endl;
                }
            }
        }
};