#include <iostream>
#include <math.h>

double F(double x); //  2.7 * asin(2.22 * x - 1) - x + 1.8 = 0

double ChordMethod(double a, double b, double E);
double HalfDivisionMethod(double a, double b, double E);
double SimpleIterationMethod(double x0, double E);

using namespace std;


int main()
{
	cout << ChordMethod(0.0, 0.8, 10e-10) << endl;
	cout << HalfDivisionMethod(0.0, 1, 10e-10) << endl;
	cout << SimpleIterationMethod(0.3, 10e-10) << endl;
}

double F(double x)
{
	return 2.7 * asin(2.22 * x - 1) - x + 1.8;
}
double Phi(double x)
{
	return 2.7 * asin(2.22 * x - 1) + 1.8;
}
double DifPhi(double x)
{
	return 5.9994 / (sqrt(4.9284 * pow(x, 2) - 2.22 * x));
}

double ChordMethod(double a, double b, double E)
{
	if (F(a) * F(b) > 0)
	{
		cout << " Wrong interval!";
		return 1;
	}

	double xn = 0.0;
	while (abs(F(b) - F(a)) > E)
	{
		xn = a - (F(a) / (F(b) - F(a))) * (b - a);
		if (F(a) * F(xn) < 0) b = xn;
		else a = xn;
	}
	return xn;
}

double HalfDivisionMethod(double a, double b, double E)
{
	if (F(a) * F(b) > 0)
	{
		cout << " Wrong interval!" << endl;
	}

	double xn = 0.0;
	while ((b - a > E))
	{
		xn = (a + b) / 2;
		if (F(a) * F(xn) < 0) b = xn;
		else a = xn;
	}
	return xn;
}

double SimpleIterationMethod(double x0, double E)
{

	double xn = Phi(x0);
	double q;
	do
	{
		cout << "xn: " << xn << " x0: " << x0 << endl;
		xn = Phi(x0);
		q = 0.5;
		cout << "q: " << q << endl;
		x0 = xn;
	} while (abs(xn - x0) <= (1 - q) * E / q);

	return xn;
}

