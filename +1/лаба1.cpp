#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian"); // switch to the russian language
	double x, y, z, g;
	
	cout << "Число x=" << endl; //запрос ввода
	cin >> x; // считывание

	cout << "Число y=" << endl;
	cin >> y;

	cout << "Число z=" << endl;
	cin >> z;

	//x = 12.3 * pow(10, -1); y = 15.4; z = 0.252 * pow(10, 3);

	if (sin(z) > 1) {
		cout << "Вы ввели недопустимое значение z" << endl;
	}

	else {
		g = pow(y, x + 1) / (pow(abs(y - 2), 1. / 3) + 3) + (x + y / 2.) / ( 2 * abs ( x + y ) ) * pow( x + 1 , -1. / sin(z) );
		cout << "Результат g=" << g;
	}
	

}
