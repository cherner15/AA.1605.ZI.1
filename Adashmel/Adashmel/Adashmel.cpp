// aleksander_melehov.cpp: определяет точку входа для консольного приложения.
// ConsoleApplication26.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	string str;
	string str1;
	string str2;
	char name;
	char s1;
	char s;
	char *pass = argv[3];
	int i, k;
	string pass1;

	while (1) {
		do
		{
			cout << "Выберите соответствующий пункт меню" << endl << "1) Расшифровать файл" << endl << "2) Зашифровать файл" << endl;
			cin >> i;
			switch (i)
			{
			case 1:
			{
				str = argv[1];
				ifstream fin(str); // открыли файл для чтения

				str1 = argv[2];
				ofstream fout(str1);

				i = 0;
				while (fin.get(s)) {
					s1 = (char)((s + 255 - pass[(i) % (strlen(pass))]) % 256);
					fout << s1;
					//cout << s1;
					i++;
				}
				cout << "Mission complete" << endl;
				fin.close();
				fout.close();
			}
			break;
			case 2:
			{

				str = argv[1];
				ifstream fin(str); // открыли файл для чтения

				str1 = argv[2];
				ofstream fout(str1);

				i = 0;
				while (fin.get(s)) {
					s1 = (char)((s + pass[(i) % (strlen(pass))] + 1) % 256);
					fout << s1;
					//cout << s1;
					i++;
				}
				cout << "Mission complete" << endl;
				fin.close();
				fout.close();
			}
			break;

			}
		} while (i<1 || i>2);
	}
	return 0;
}

