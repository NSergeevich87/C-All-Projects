/** Задача 3
Что нужно сделать:
Напишите рекурсивную функцию, которая принимает большое число n типа long long и переменную ans, 
а возвращает void. После завершения работы функции в переменной ans должно оказаться количество чётных цифр 
в записи числа n.

Пример:

int ans;
evendigits(9 223 372 036 854 775 806, ans);
//ans == 10*/

#include <iostream>

using namespace std;

void evendigits(long long n, int &ans) {
    if (n == 0) {
        return;
    }
    if (n % 10 % 2 == 0) {
        ans++;
    }
    evendigits(n / 10, ans);
}

int main() {
    long long n;
    int ans = 0;
    cout << "Enter n: ";
    cin >> n;
    evendigits(n, ans);
    cout << ans << endl;
    return 0;
}