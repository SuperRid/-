#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f(double x) 
{
	return 2.7*asin(2.22*x-1) - x +1.8; 
}

double fi(double x)
{
	return (1 - sin((1.8 - x) / 2.7)) / 2.22; 
}




double hord(double a, double b, double eps, int& k)
{
	double c = 0, d;

	do
	{
		d = c;
		c = a - f(a) * (b - a) / (f(b) - f(a));

		if (f(a) > 0)
		{
			if (f(a) * f(c) < 0) b = c;
			else a = c;
			k++;
		}

		else
		{
			if (f(b) * f(c) < 0) a = c;
			else b = c;
			k++;
		}

	} while (abs(d - c) > eps);
	{
		return c;
	}
}



double Iter(double x0, double eps, int& k)
{
	double xn;
	double q = 0.14;

	do
	{

		xn = x0;
		x0 = fi(xn);
		
		k++;
	} while (abs(xn - x0) > (1 - q) * eps / q);
	return x0;
}


int main()
{
	setlocale(LC_ALL, "ru");

	double  a, b, x0;
	int k = 0, m;
	double eps = 1.E-10;
	cout.precision(11);
	cout << "Выберете метод решение уравнения (1 - Метод хорд или 2 - Метод Итераций)" << endl;
	cin >> m;
	if (m == 1)
	{
		cout << "Введите интервал" << endl;
		cin >> a >> b;
		cout << "Корень уравнения: " << hord(a, b, eps, k) << endl;
	}
	else
	{
		cout << "Введите приближенное значение " << endl;
		cin  >> x0;
		cout << "Корень уравнения: " << Iter(x0, eps, k) << endl;
	}
	cout << "Количество итераций: " << k << endl;
}


