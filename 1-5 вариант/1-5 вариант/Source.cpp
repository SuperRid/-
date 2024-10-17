#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f(double x) //�������
{
	//return tan(0.63 * x) - 0.92 * x + 0.19; //1 �������, ��������� [-2,0], [0,2]
	//return log(0.31 * x) - 1.3 * x + 2.5; //2 �������, ��������� [0.1, 0.9],[1,3]
	//return 0.33 * sin(2.3 * x) - 0.5 * x - 0.06; //3 ������� [-1,0], [0, 0.3], [0.4, 2]
	//return 0.37 * exp(-0.75 * x) + x + 0.37; //4 ������� [-3,-1.6], [-1.6,0]
	return 0.88 * pow(x,3) - 2.81 * pow(x, 2) - 3.692 * x + 13.1; // 5 ������� [-3,0], [0, 2.6], [2.6, 3]
} 

double f1(double x) //������ �����������
{
	//return 0.63 / (cos(0.63 * x) * cos(0.63 * x)) - 0.92;
    //return 1 / x - 1.3;
	//return 0.33 * 2.3 * cos(2.3 * x) - 0.5;
	//return -0.37 * 0.75 * exp(-0.75 * x) + 1;
	return 0.88 * 3 * pow(x, 2) - 2.81 *2* x - 3.692;
}

double f2(double x) //������ �����������
{
	//return 0.63 * 0.63 * tan(0.63 * x) / (cos(0.63 * x) * cos(0.63 * x));
	//return -1 / (x * x);
	//return -0.33 * 2.3 * 2.3 * sin(2.3 * x);
	//return 0.37 * 0.75 * 0.75 * exp(-0.75 * x);
	return 0.88 * 6 * x - 2.81 * 2;
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
	cout << "�������� ����� ������� ��������� (1 - ����� ����������� ������� ��� 2 - ����� �������)" << endl;
	cin >> m;
	cout << "������� ��������" << endl;
	cin >> a >> b;
	if (m == 1) cout << "������ ���������: " << Poldel(a, b, eps, k) << endl;
	else cout << "������ ���������: " << Newton(a, b, eps, k) << endl;
	cout << "���������� ��������: " << k << endl;
}