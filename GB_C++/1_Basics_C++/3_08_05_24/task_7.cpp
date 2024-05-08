/**
 * Задача 3. Злостные вредители Что нужно сделать: На бамбуковой плантации завелись гусеницы. 
 * Они спят днём и едят бамбук ночью. Бамбук генно-модифицированный, растёт только при свете дня, 
 * зато очень быстро — по 50 сантиметров ежедневно! Гусеницы съедают 20 сантиметров бамбука каждую ночь. 
 * Бамбуковые саженцы при посадке утром имеют высоту один метр. Напишите программу, которая считает, 
 * какой высоты будет бамбук в середине третьего дня. Усложнение — посчитайте это не за несколько подходов, 
 * а одной формулой.

Советы и рекомендации: • Допускается погрешность в один сантиметр. • Все расчёты проводите в сантиметрах.

Что оценивается: • Правильность подсчёта высоты бамбука к третьему дню. • Допускается, 
если в решении используется пользовательский ввод для задания значения переменных.

Подсказка: Высоту бамбука к середине третьего дня можно посчитать с помощью формулы: 
beginHeight + (dailyGrowth - nightFade) * 2 + dailyGrowth / 2; 
В ней: • dailyGrowth — ежедневный рост; • nightFade — размер съедаемого гусеницами бамбука за одну ночь; 
• beginHeight — начальная высота бамбука.
*/

#include <iostream>
#include <limits>

using namespace std;

class task_7
{
    public:
        void run()
        {
            int beginHeight = 100;
            int dailyGrowth = 50;
            int nightFade = 20;
            int result = beginHeight + (dailyGrowth - nightFade) * 2 + dailyGrowth / 2;
            cout << "Height of bamboo in the middle of the third day: " << result << " cm" << endl;

            cout << "Enter your begin height of bamboo: ";
            cin >> beginHeight;
            cout << "Enter daily growth of bamboo: ";
            cin >> dailyGrowth;
            cout << "Enter night fade of bamboo: ";
            cin >> nightFade;
            result = beginHeight + (dailyGrowth - nightFade) * 2 + dailyGrowth / 2;
            cout << "Height of bamboo in the middle of the third day: " << result << " cm" << endl;

            /** clean the input buffer from the previous input */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
};