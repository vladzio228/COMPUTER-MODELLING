#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

 long double h = 0.1;
 long double x = 2.0;
 long double xn = 3.0;
 long double y = 1.1323;

long double function(long double x, long double y) {
    return 1 / (pow(x, 2) + pow(y, 2));
}

int main()
{
    long double k1, k2, k3;
    long double xk = x;
    long double yk = y;
    for (int i = 0; i <= 10; ++i) {
        k1 = function(xk, yk);
        k2 = function(xk + h / 2, yk + k1 / 2);
        k3 = function(xk + h, yk + 2 * k2 * h - k1 * h);
        cout << left << "x" << setw(2) << i << " = " << setw(3) << xk << "  ";
        cout << left << "y" << setw(2) << i << " = " << setw(10) << yk << "  ";
        cout << left << "k1_" << setw(2) << i << " = " << setw(10) << k1 << "  ";
        cout << left << "k2_" << setw(2) << i << " = " << setw(10) << k2 << "  ";
        cout << left << "k3_" << setw(2) << i << " = " << setw(10) << k3 << endl;
        xk = xk + h;
        yk = yk + h / 6 * (k1 + 4 * k2 + k3);
    }
    return 0;
}
