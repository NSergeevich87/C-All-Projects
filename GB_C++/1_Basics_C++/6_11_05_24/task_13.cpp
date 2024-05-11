/** Коллекторы
Что нужно сделать
Напишите робота для коллекторов. В самом начале он спрашивает имя должника и сумму долга, 
а затем начинает требовать у него погашения долга до тех пор, пока тот не будет погашен полностью. 
Сумма долга должна уменьшаться, если пользователь ввёл сумму, меньшую чем сумма долга. 
Если пользователь внёс большую сумму, чем требуется для погашения, выведите сообщение о том, 
какой у него остаток на счету после такой операции. Обеспечьте контроль ввода.

Рекомендации по выполнению
При полной выплате долга необходимо учитывать остаток на счету, если он имеется.

Что оценивается
• Правильно считается остаток после полного погашения долга.
• Программа прекращает выполнение после того, как долг полностью погашен.
• При задании отрицательного долга программа выводит предупреждение и прекращает выполнение.*/

#include <iostream>
#include <string>

using namespace std;

class task_13
{
    public:
        void run()
        {
            string name;
            cout << "Enter the name of the debtor: ";
            getline(cin, name);

            string debt;
            cout << "Enter the amount of debt: ";
            getline(cin, debt);

            int debt_amount = 0;
            try
            {
                debt_amount = stoi(debt);
            }
            catch(const std::exception& e)
            {
                std::cerr << "Wrong number!" << '\n';
            }
            
            
            if (debt_amount < 0)
            {
                cout << "You entered a negative debt amount!" << endl;
                return;
            }

            int balance = 0;
            while (debt_amount > 0)
            {
                string payment;
                cout << "Enter the amount of payment: ";
                getline(cin, payment);

                int payment_amount = 0;
                try
                {
                    payment_amount = stoi(payment);
                }
                catch(const std::exception& e)
                {
                    std::cerr << "Wrong number!" << '\n';
                }
                
                if (payment_amount < 0)
                {
                    cout << "You entered a negative payment amount!" << endl;
                    return;
                }

                if (payment_amount > debt_amount)
                {
                    balance = payment_amount - debt_amount;
                    debt_amount = 0;
                }
                else
                {
                    debt_amount -= payment_amount;
                    cout << "The remaining debt is: " << debt_amount << endl;
                }
            }

            cout << "The debt is fully repaid." << endl;
            if (balance > 0)
            {
                cout << "The balance on the account is: " << balance << endl;
            }
        }
};