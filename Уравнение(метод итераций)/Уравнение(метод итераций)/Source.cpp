#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


double fi1(double x)
{
	//return acos(log(2.5 * x) / 1.4) / 3.9; //10 вариант
	return (1 - sin((1.8 - x) / 2.7)) / 2.22; //16 вариант 
}

double fi2(double x)
{
	return 0.4 * exp(1.4 * cos(3.9 * x)); //10 вариант
}

double iter(double x0, double eps, int& k, int& m)
{
	double xn;
	double q = 0.14;

	do
	{
		xn = x0; 
		if (m == 1) x0 = fi1(xn);
		else x0 = fi2(xn);
		k++;
	}
	while (abs(xn - x0) > (1 - q) * eps / q);
		return x0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	double x0;
	double eps = 1.E-8;
	int k = 0,m;
	cout.precision(9);
	cout << "Введите номер функции (1 или 2) и приближенное значение " << endl;
	cin >> m >> x0;
	cout << "Корни уравнения: " << iter(x0, eps, k,m) << endl;
	cout << "Количество итераций: " << k << endl;



}