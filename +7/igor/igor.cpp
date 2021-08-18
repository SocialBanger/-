#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


int main()
{
	int i, j, p;
	setlocale(0, "");

	do {
		cout << "введите слова на английском "<< endl;//ввод значений
		cout << "символы, не входящие в английский алфавит и лишние пробелы будут удалены; больше буквы авоматически изменяться на малые" << endl;
		string str, * wrds;
		getline(cin, str);  //считывание dat

		p = 0;
		for (i = 0; i <= '\0'; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')//проверка на символ ангийского алфавита
				continue;
			else if (str[i] >= 'A' && str[i] <= 'Z')//приведение к нижнему регистру
			{
				cout << " большая " << str[i] << " будет заменена на малую" << endl;
				str[i] += 32;
				continue;
			}
			else if (str[i] == ' ' && str[i + 1] != ' ' || str[i] == '\0')//счетчик слов для задания массива
				++p;
			else//удаление неподходящих символов
			{
				cout << "в строке присутствует символ "<< "{" << str[i] << "}"<<", не входящий в английский алфавит(или лишний пробел) -- он будет удален" <<endl;
				str.erase(i, 1);
				--i;
			}
		}


		j = 0;
		wrds = new string[p];									//создание динамического массива для "p" слов
		string buf;
		for (i = 0; i <= str.length(); i++)
		{
			if (str[i] != ' ' && str[i] != '\0')				//занесение букв в массив-буфер
				buf.push_back(str[i]);
			else if (str[i] == ' ')								//занесение слов из буфера в основной массив
			{
				wrds[j].append(buf);
				buf.clear();
				j++;
			}
			else												//занесение последнего слова
			{
				wrds[j].append(buf);
				buf.clear();
				break;
			}

		}

		int k;
		do
		{
			k = 0;
			for (i = 0; i < j; i++)
			{
				if (wrds[i] > wrds[i + 1])							//сравнение i-того и последующего слова
				{
					swap(wrds[i], wrds[i + 1]);						//поменять их местами если стоят не по алфавиту
					k++;
				}
			}
		} while (k != 0);											//пока пройдет без перестановок

		cout << "слова в алфавитном порядке \n";					//вывод итоговых значений
		for (int i = 0; i <= j; i++)
			cout << wrds[i] << endl;

		delete[]wrds;
		cout << "хотите повторить выполнение программы -- нажмите \"R\" " << endl;
	} while (_getch() == 'r' || _getch() == 'R');
}