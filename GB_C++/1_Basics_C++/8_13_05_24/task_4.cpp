/** Ку!
Общеизвестно, что на планете Плюк можно купить гравицапу за пол-КЦ или, что то же самое, 2 200 чатлов. 
Причем чатлы неделимы и всегда являются целым числом. Напишите простую программу-конвертер валют. 
В программу вводится количество чатлов, а она сообщает, сколько это КЦ и сколько гравицап можно купить 
на эту сумму. Обеспечьте контроль ввода.*/

#include <iostream>
#include <string>

using namespace std;

class task_4
{
    public:
        void run()
        {
            cout << "Enter amount of chatls: ";
            string chatls;
            getline(cin, chatls);
            int chatls_amount = stoi(chatls);
            if (chatls_amount < 0)
            {
                cout << "Chatls amount can't be less than 0" << endl;
                return;
            }
            cout << "You can buy " << float(chatls_amount / 2) << " KZT and " << float(chatls_amount / 2200) << " gravitsapa" << endl;
        }
};