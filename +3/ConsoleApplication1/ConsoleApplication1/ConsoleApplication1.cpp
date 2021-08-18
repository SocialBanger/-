//#include "pch.h"
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double x = 0, a, b, Sum, Y, mis, h, r, j;
	int n, k = 1;

	cout << "Введите границы изменения вашего х (a,b)\n";

	while (!(cin >> a) || cin.peek() != '\n') /*проверяет, достигнут ли конец потока входного файла или наличие перехода на новую строку */ {
		cin.clear(); //очищает память от ошибок ибобез этого цикл остановится, при введении символьного значения
		cin.ignore(256, '\n'); //пропускает символы до нажатия Enter
		cout << "Введите ЦЕЛОЧИСЛЕННОЕ значение заново ... " << endl;
	}
	while (!(cin >> b) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Введите ЦЕЛОЧИСЛЕННОЕ  значение заново ... " << endl;
	}


	cout << "Введите h \n";
	while (!(cin >> h) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Введите ЦЕЛОЧИСЛЕННОЕ  значение заново ... " << endl;
	}

	cout << "Введите количество операций (n) \n";
	while (!(cin >> n) || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Введите ЦЕЛОЧИСЛЕННОЕ  значение заново ... " << endl;
	}

		while (x <= b) {
		Sum = x;
		r = x;
		Y = (exp(x) - exp(-x)) / 2;
		x += h;

		while (k <= n, k++) {
			r *= (x * x) / ((2 * k + 1) * 2 * k); //recurent form
			Sum = Sum + r; //sum
		}

		j = abs(Y - Sum);
		cout << "Y(x)=" << Y << "..." << "S(x)=" << Sum << "..." << "|Y-S|" << j << endl;
	}
}	