#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const long double h = 0.1;
const long double x0 = 0.0;
const long double xn = 1.0;

const long double yBy0 = 0.0;
const long double yBy1 = 0.0;

const long double zBy0 = 0.0;

/* 
function: y'' = tan(x) - x ^ 2 * y'-x * y
Koshi: y' = z
	   z' = tan(x) - x^2*z - x * y
For example: z(0) = 0
*/

long double function(long double x, long double y, long double z) {
	return tan(x) - (pow(x, 2) * z) - (x * y);
}

int main() {
	long double xi = x0;
	long double yi = yBy0;
	long double zi = zBy0;

	long double Ki, Li;

	for (int i = 0; i <= 10; ++i) {
		Ki = zi;
		Li = function(xi, yi, zi);

		cout << left << "x" << setw(2) << i << " = " << setw(3)  << xi << " ";
		cout << left << "y" << setw(2) << i << " = " << setw(10) << yi << " ";
		cout << left << "z" << setw(2) << i << " = " << setw(10) << zi << " ";
		cout << left << "K" << setw(2) << i << " = " << setw(10) << Ki << " ";
		cout << left << "L" << setw(2) << i << " = " << setw(10) << Li << " " << endl;

		xi += h;
		yi += h * Ki;
		zi += h * Li;
	}
	return 0;
}