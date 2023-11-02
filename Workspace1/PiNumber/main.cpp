#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    long double pi = 0.0;
    long double term = 1.0;
    long long sign = 1;
    long long i = 1;

    while (fabs(term) > 1e-8) {
        pi += term;
        sign = -sign;
        term = sign / (2.0 * i + 1.0);
        i++;
    }

    pi *= 4.0;

    cout << fixed << setprecision(10) << "π = " << pi << endl;
}