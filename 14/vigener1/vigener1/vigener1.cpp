// Vigener.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

const int rusLengh = 256;


void CipherViginer(unsigned char** lang, int rusLengh, unsigned char* key, int textLengh, int counter, unsigned char* cipher, string text)
{
	int row = 0, col = 0;

	// поиск в строке
	for (int i = 0; i < rusLengh; i++)
	{
		if (lang[i][0] == text[counter])
		{
			row = i;
			break;
		}
	}

	// поиск в столбце
	for (int i = 0; i < rusLengh; i++)
	{
		if (lang[0][i] == key[counter])
		{
			col = i;
			break;
		}
	}

	cipher[counter] = lang[row][col]; // буква на пересечении
}


void FillKey(unsigned char* key, int textLengh, string sKey)
{
	for (int i = 0, j = 0; i < textLengh; i++, j++)
	{
		if (j == sKey.length()) j = 0; // ключ не вышел за границы
		key[i] = sKey[j];		// растяжение
	}
}


void Print(unsigned char** lang, int rusLengh)
{
	for (int i = 0; i < rusLengh; i++)
	{
		for (int j = 0; j < rusLengh; j++)
		{
			cout << lang[i][j];
		}
		cout << endl;
	}
}


void FillRussian(unsigned char** lang, int rusLengh)
{
	int letter = 0; // А 
	int start = 0;
	int counter = 0; // сколько строк мы прошли

	for (int row = 0; row < rusLengh; row++)
	{
		for (int col = 0; col < rusLengh; col++)
		{
			lang[row][col] = letter; // заполняем текущую букву
			letter++; // +1 для изменения буквы
			if (letter == 256) letter = start; // выход за границу
		}
		counter++; //увеличили количество пройденных строк
		letter = start + counter;
	}
}

//void ReadFromFile(ifstream& in,string text) //чтение с файла
//{
//	in >> text;
//	string t;
//}

void main()
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// выделение памяти для таблицы Виженера
	unsigned char** lang = new unsigned char*[rusLengh];
	for (int i = 0; i < rusLengh; i++)
	{
		lang[i] = new unsigned char[rusLengh];
	}

	string text;
	string sKey;
	string fole;
	string fole2;

	/*cout << "введите название файла, с которого хотите считать слово";
	cin >> fole;
	ifstream f(fole);
	if (f.is_open()) {
		getline(f, text);
		f.close();
	}*/

	/*cout << "введите название файла, с которого хотите считать ключ";
	cin >> fole2;
	ifstream y(fole2);
	if (y.is_open()) {
		getline(y, sKey);
		f.close();
	}*/
	cout << "Введите слово, которое нужно зашифровать:" << endl;
			cin >> text;
			cin.get();
	cout << "Введите ключ:" << endl;
			cin >> sKey;
			
		FillRussian(lang, rusLengh);

		int textLengh = text.length();
		unsigned char* key = new unsigned char[textLengh];
		unsigned char* cipher = new unsigned char[textLengh];

		//Print(lang, rusLengh);
		FillKey(key, textLengh, sKey);

		for (int i = 0; i < textLengh; i++)
		{
			CipherViginer(lang, rusLengh, key, textLengh, i, cipher, text);
		}

		cout << endl << "Cipher: " << endl;
		for (int i = 0; i < textLengh; i++)
		{
			cout << cipher[i];
		}

		delete[]key;
		delete[]cipher;


	for (int i = 0; i < rusLengh; i++)
	{
		delete[]lang[i];
	}
	delete[]lang;

	_getch();
}