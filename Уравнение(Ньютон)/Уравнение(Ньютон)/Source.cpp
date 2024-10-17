#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


double f(double x)
{
	return tan(0.63 * x) - 0.92 * x + 0.19;
}

double f1(double x)
{
	return 0.63/(cos(0.63 * x) * cos(0.63 * x)) - 0.92 ;
}

double f2(double x)
{
	return 0.63*0.63*tan(0.63 * x)/(cos(0.63 * x)*cos(0.63 * x));
}

double Newton(double a, double b, double eps, int& k)
{
	double xn, x0;

	if ((f(a) * f2(a)) > 0) x0 = a;
	else x0 = b;

	do
	{
		xn = x0;
		x0 = xn - f(xn)/f1(xn);
		
		k++;
	} while (abs(xn - x0) >  eps);
	return x0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	double a,b;
	double eps = 1.E-7;
	int k = 0;
	cout.precision(8);
	cout << "Введите интервал " << endl;
	cin >> a >> b;
	cout << "Корни уравнения: " << Newton(a,b, eps, k) << endl;
	cout << "Количество итераций: " << k << endl;



}