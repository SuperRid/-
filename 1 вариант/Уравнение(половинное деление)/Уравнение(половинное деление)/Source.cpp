#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f(double x)
{
	return tan(0.63 * x) - 0.92 * x + 0.19;
}

double poldel(double a, double b, double eps,int& k)
{
	double c;
	while (b - a > eps)
	{
		c = (a + b) / 2;
		if (f(b) * f(c) < 0) a = c;
		else b = c;
		k++;
	}
	return c;
}

int main()
{
	setlocale(LC_ALL, "ru");

	double  a, b;
	int k = 0;
	double eps = 1.E-7;
	cout.precision(10);
	cout << "Введите интервал" << endl;
	cin >> a >> b;
	cout << "Корни уравнения: " << poldel(a, b, eps, k) << endl;
	cout <<"Количество итераций: "<< k<< endl;
}