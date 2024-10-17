#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f(double x) //�������
{
	return log(0.31 * x) - 1.3 * x + 2.5;
}

double f1(double x) //������ �����������
{
	return 1/x - 1.3;
}

double f2(double x) //������ �����������
{
	return -1/(x*x);
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

double Newton(double a, double b, double eps, int& k)
{
	double xn, x0;

	if ((f(a) * f2(a)) > 0) x0 = a; //����� ��������� ����� �� ���� ������
	else x0 = b;

	do
	{
		xn = x0;
		x0 = xn - f(xn) / f1(xn); //���������� ����� ����� 

		k++;
	} while (abs(xn - x0) > eps); //������� ������ �� �����
	return x0;
}


int main()
{
	setlocale(LC_ALL, "ru");

	double  a, b;
	int k = 0, m;
	double eps = 1.E-7;
	cout.precision(8);
	cout << "�������� ����� ������� ��������� (1 ��� 2)" << endl;
	cin >> m;
	cout << "������� ��������" << endl;
	cin >> a >> b;
	if (m == 1) cout << "������ ���������: " << Poldel(a, b, eps, k) << endl;
	else cout << "������ ���������: " << Newton(a, b, eps, k) << endl;
	cout << "���������� ��������: " << k << endl;
}