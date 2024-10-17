#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f(double x) //�������
{
	//return 1/tan(1.5 * x) - 2.3 * x + 0.8; //6 �������, ��������� [0.1,1.8]
	//return pow(x,5) - 4*pow(x, 4) - 3*pow(x, 3) + 2*x +1; //7 �������, ��������� [-2, 0], [0,4], [4,6]
	return 1.4*cos(3.9*x) - log(2.5 * x); //10 �������, ��������� [0.2, 1], [1,3]
}

double fi1(double x)
{
	//return (1/tan(1.5 * x) + 0.8) / 2.3; //6 �������, �������� 0.64, � ������ ������ q > 1
	//return -(pow(x, 5) - 4 * pow(x, 4) - 3 * pow(x, 3) + 1)/2; //7 �������, �������� -0.5
	return acos(log(2.5 * x) / 1.4) / 3.9; //10 �������, �������� 0.4
	//return (1 - sin((1.8 - x) / 2.7)) / 2.22; //16 ������� 
}

double fi2(double x)
{
	//6 �������, �� ����� 2 �������
	return 0.4 * exp(1.4 * cos(3.9 * x)); //10 �������, �������� 1.5
}


double Poldel(double a, double b, double eps, int& k)
{
	double c;
	while (b - a > eps) //������� ������ �� �����
	{
		c = (a + b) / 2; //���������� ����� �����
		if (f(b) * f(c) < 0) a = c; //�������� �������
		else b = c;
		k++;
	}
	return c;
}



double Iter(double x0, double eps, int& k, int& fi)
{
	double xn;
	double q = 0.16; // 7 �������
	//double q = 0.96; // 6 �������
	//double q = 0.37; //10 �������

	do
	{
		
		xn = x0;
		if (fi == 1) x0 = fi1(xn);
		else x0 = fi2(xn);
		k++;
	} while (abs(xn - x0) > (1 - q) * eps / q);
	return x0;
}


int main()
{
	setlocale(LC_ALL, "ru");

	double  a, b,x0;
	int k = 0, m,fi;
	double eps = 1.E-8;
	cout.precision(9);
	cout << "�������� ����� ������� ��������� (1 - ����� ����������� ������� ��� 2 - ����� ��������)" << endl;
	cin >> m;
	if (m == 1)
	{
		cout << "������� ��������" << endl;
		cin >> a >> b;
		cout << "������ ���������: " << Poldel(a, b, eps, k) << endl;
	}
	else
	{
		cout << "������� ����� ������� (1 ��� 2) � ������������ �������� " << endl;
		cin >> fi >> x0;
		cout << "������ ���������: " << Iter(x0, eps, k, fi) << endl;
	}
	cout << "���������� ��������: " << k << endl;
}


