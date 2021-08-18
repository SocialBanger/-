#include <iostream>
#include <conio.h>
typedef double (*TF)(double, int); // указатель на функцию
double fun1(double, int), fun2(double, int); // прототип функции
void Out_Rez(TF, double, double, double, int);
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	
	double a, b, h;
	int n;
	char code;
	do
	{
		do
		{
			cout << "Введите a: "; cin >> a;
			cout << "Введите b: "; cin >> b;
			if (a > b) cout << "Число b должно быть больше числа a" << endl;
		} while (a > b);
		do
		{
			cout << "Введите h: "; cin >> h;
			if (h < 0) cout << "Шаг функции h должен быть больше 0" << endl;
		} while (h < 0);
		do
		{
			cout << "Введите n: "; cin >> n;
			if (n < 1) cout << "Число n должно быть больше 0" << endl;
		} while (n < 1);
		cout << "Функция 1 - Y(x):" << endl;
		Out_Rez(fun1, a, b, h, n);
		cout << "Функция 2 - S(x):" << endl;
		Out_Rez(fun2, a, b, h, n);

		
		cout << "Для повторения программы нажмите R" << endl;
		code = _getch();
	} while (code == 'R' || code == 'r');
}

double fun1(double x, int xn)// реализация f-ии
{
	return (exp(x) - exp(-x)) / 2; 
}

double fun2(double x, int xn)
{
	double r, sum;
	r = sum = 1;
	for (int k = 1; k <= xn; ++k)
	{
		r *= (x * x) / ((2 * k + 1) * 2 * k);
		sum += r;
	}
	return sum;
}


void Out_Rez(TF f, double xa, double xb, double xh, int xn)
{
	for (double x = xa; x <= xb; x += xh) {
		cout << "x=" << x << "\t y=" << f(x, xn) << endl;
	}
}
