// vijiner.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>  


using namespace std;

string flag;

void shifrovka(char* argv[])
{
	for (int o = 0; o < 5; o++)
	{
		cout << argv[o] << endl;
	}

	int i = 0;
	int check = 0;
	ofstream fout("вывод.txt", ofstream::binary);
	ifstream finCheck("ввод.txt", ifstream::binary);
	cout << "ВВЕДИТЕ КЛЮЧ: ";
	cin >> flag;
	if (finCheck.is_open())
	{

		while (!finCheck.eof())
		{
			char x;
			finCheck.get(x);
			check++;
		}
		finCheck.close();
	}
	else {
		cout << "файл не найден" << endl;
	}


	ifstream fin("ввод.txt", ifstream::binary);

	for (char n = 0; n < check - 1; n++)
	{
		char x;
		char y;
		fin.get(x);
		y = (( char)x + ( char)flag[i]) % 256;
		fout << y;
		i = i + 1;
		if (i == flag.length()) i = 0;
	}
	fin.close();
	fout.close();
	{
		ofstream fout1("дешифровка.txt", ifstream::binary);
		ifstream finFl("вывод.txt", ifstream::binary);
		int check = 0;



		if (finFl.is_open()) {
			//return 0; // проверка на существование файла
			while (!finFl.eof())
			{
				char x;
				finFl.get(x);
				check++;
			}
			finFl.close();
		}
		else {
			cout << "файл не найден" << endl;
		}
		ifstream fin1("вывод.txt", ifstream::binary);
		int i = 0;
		for (char n = 0; n < check - 1; n++)
		{
			char x;
			char y;

			fin1.get(x);
			y = (( char)x - ( char)flag[i]) % 256;
			fout1 << y;
			i = i + 1;
			if (i == flag.length()) i = 0;
		}
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc < 5)
	{
		cout << "not enugh args" << endl;
		return 1;
	}

	shifrovka(argv);

	return 0;
}