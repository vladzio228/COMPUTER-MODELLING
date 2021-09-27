#include <iostream>
#include <cmath>

using namespace std;

long double eps = 0.5;
long double delta = pow(eps/6,2);
long double a = 0;
long double b = 1;

long double f(long double& x)
{
    return 1 / (sqrt(x * (1 + x + x)));
}

long double maxderivativef()
{
    long double x = delta;
    return abs(-((3 * x * x + 1) / (2 * pow(x * x * x + x, 3.0 / 2.0))));
}

long double integral1()// integral from a(0) to delta
{
    return 2 * sqrt(delta);
}

long double integral2(int& n, long double& h)// Intefral from delta to b(1)
{
    long double x = delta;
    long double res = 0;
    for (int i = 0; i < n; ++i) {
        res += f(x) * h;
        x += h;
    }
    return res;
}

int main()
{
    long double eps1 = eps - integral1();
    int n = (int)((maxderivativef()*(b-delta)*(b-delta)/(2*eps1))+1);
    long double h = (b - delta) / n;

    cout <<"I1 = " << integral1() << endl;
    cout << "I2 = " << integral2(n, h) << endl;
    cout << "I1 + I2 = " << integral1() + integral2(n, h) << endl;

    return 0;
}
