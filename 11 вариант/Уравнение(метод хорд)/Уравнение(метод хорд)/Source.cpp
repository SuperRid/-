#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f(double x)
{
	//return x*x - log(3.3 * x + 0.12) -1.3;
	return 2.7 * asin(2.22 * x - 1) - x + 1.8;
	//return 2.56 * log(x + 0.4) - 0.17 / tan(0.42 * x) + 3;
	//return 1.13 + 1 / (x - 2.92) - 0.75 * exp(-x);
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
		
	} 
	while (abs(d - c) > eps);
	{
		return c;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	double a, b;
	double eps = 1.E-10;
	int k = 0;
	cout.precision(11);
	cout << "Введите интервал" << endl;
	cin >> a >> b;
	cout << "Корни уравнения: " << hord(a, b, eps, k) << endl;
	cout << "Количество итераций: " << k << endl;
	

	
}