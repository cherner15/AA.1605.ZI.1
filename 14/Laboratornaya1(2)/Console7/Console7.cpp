// Console7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <locale>
#include <codecvt>

using namespace std;

const int Length = 256;


void Decryption(unsigned char** lang, unsigned char* key, int counter, int textLength, unsigned char* dipher, unsigned char* decr)
{
	int row = 0, col = 0;

	for (int i = 0; i < Length; i++)
	{
		if (lang[i][0] == key[counter])
		{
			row = i;
			break;
		}
	}

	int temp = 0;
	for (int i = 0; i < Length; i++)
	{
		/*if (dipher[counter] >= 1040 && dipher[counter] <= 1103)
		{
			temp = 848;
		}*/
		if (lang[row][i] == dipher[counter])
		{
			col = i;
			temp = 0;
			break;
		}
	}

	decr[counter] = lang[0][col];
}


void Encryption(unsigned char** lang, unsigned char* key, int textLength, int counter, unsigned char* cipher, wstring text)
{
	int row = 0, col = 0;
	int temp = 0;

	// нахождение буквы в строке
	for (int i = 0; i < Length; i++)
	{
		if (text[counter] >= 1040 && text[counter] <= 1103)
		{
			temp = 848;
		}
		if (lang[i][0] == (text[counter] - temp))
		{
			row = i;
			temp = 0;
			break;
		}
	}

	// нахождение буквы в столбце
	for (int i = 0; i < Length; i++)
	{
		if (lang[0][i] == key[counter])
		{
			col = i;
			break;
		}
	}

	cipher[counter] = lang[row][col]; // шифруем букву
}


void FillKey(unsigned char* key, int textLength, wstring sKey)
{
	int temp = 0;
	// растягиваем ключ
	for (int i = 0, j = 0; i < textLength; i++, j++)
	{
		if (j == sKey.length()) j = 0; // проверка на то, чтобы ключ не вышел за границы
		if (sKey[j] >= 1040 && sKey[j] <= 1103)
		{
			temp = 848;
		}
		key[i] = (sKey[j] - temp);
		temp = 0;
	}
}


void FillTable(unsigned char** lang)
{
	int letter = 0;
	int start = 0;
	int counter = 0; // сколько строк прошли

	for (int row = 0; row < Length; row++)
	{
		for (int col = 0; col < Length; col++)
		{
			lang[row][col] = letter;			// заполняем текущий символ
			letter++;							// увеличи на 1 для изменения символа
			if (letter == 256) letter = start;	// выход за границу
		}
		counter++;								//увеличили кол-во пройденных строк
		letter = start + counter;
	}
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice = 0;

	cerr << "Input 1 for Encryption" << endl;
	cin >> choice;

	// выделение памяти для таблицы Виженера
	unsigned char** lang = new unsigned char*[Length];
	for (int i = 0; i < Length; i++)
	{
		lang[i] = new unsigned char[Length];
	}

	wstring text;
	wstring sKey;

	long sizeFile = 0;
	wifstream T(argv[1]);
	if (T.fail())
		cerr << "Error Open to File" << endl;
	else
	{
		T.imbue(locale(locale(), new std::codecvt_utf8<wchar_t, 0x10ffffUL, std::codecvt_mode::consume_header>));

		wstring tmp;
		while (getline(T, tmp))
		{
			text += tmp;
		}
	}
	T.close();

	wifstream K(argv[2]);
	if (K.fail()) cerr << "Error Open to File" << endl;
	else
	{
		K.imbue(locale(locale(), new std::codecvt_utf8<wchar_t, 0x10ffffUL, std::codecvt_mode::consume_header>));
		wstring tmp;
		while (getline(K, tmp))
		{
			sKey += tmp;
		}
	}
	K.close();

	FillTable(lang);
	ofstream I("table.txt", ios::out);
	int o = 0, p = 0;
	while (o < Length)
	{
		I << lang[o][p];
		p++;
		if (p == Length)
		{
			p = 0;
			o++;
		}
	}
	I.close();

	int textLength = text.length();
	unsigned char* key = new unsigned char[textLength];
	unsigned char* cipher = new unsigned char[textLength];
	unsigned char* decr = new unsigned char[textLength];


	FillKey(key, textLength, sKey);

	ofstream R(argv[3], ios::out);
	if (R.fail())
		cerr << "Error Open to File" << endl;
	else
	{
		if (choice == 1)
		{
			for (int i = 0; i < textLength; i++)
			{
				Encryption(lang, key, textLength, i, cipher, text);
			}

			int r = 0;
			while (r < textLength)
			{
				R << cipher[r];
				r++;
			}
			R.close();
		}
		else if (choice == 2)
		{
			wstring chichi;
			wifstream J("joj3o.txt");
			if (J.fail()) cerr << "Error Open to File" << endl;
			else
			{
				J.imbue(locale(locale(), new std::codecvt_utf8<wchar_t, 0x10ffffUL, std::codecvt_mode::consume_header>));
				wstring tmp;
				while (getline(J, tmp))
				{
					chichi += tmp;
				}
			}
			J.close();
			/*int l = 0;
			int temp = 0;
			unsigned char* chi = new unsigned char[chichi.length()];
			for (l = 0; l < chichi.length(); l++)
			{
				if (chichi[l] >= 1040 && chichi[l] <= 1103)
				{
					temp = 848;
				}
				chi[l] = chichi[l] - temp;
				temp = 0;
			}*/

			/*for (int i = 0; i < chichi.length(); i++)
			{
				Decryption(lang, key, i, textLength, chichi, decr);
			}

			int z = 0;
			while (z < chichi.length())
			{
				cout << decr[z];
				z++;
			}
*/
			/*ofstream N("toto.txt", ios::out);
			int o = 0;
			if (N.fail())
				cerr << "Error Open to File" << endl;
			else
			{
				while (o < chichi.length())
				{
					N << decr[o];
					o++;
				}
			}

			N.close();*/

			/*while (z < textLength)
			{
				R << decr[z];
				z++;
			}*/
			R.close();
		}
	}


	for (int i = 0; i < textLength; i++)
	{
		Decryption(lang, key, i, textLength, cipher, decr);
	}

	int z = 0;
	while (z < textLength)
	{
		cout << decr[z];
		z++;
	}


	//cout << endl << "Cipher: ";
	//for (int i = 0; i < textLength; i++)
	//{
	//	cout << cipher[i];
	//}
	//	
	//cout << endl << "Decryption: ";
	//for (int i = 0; i < textLength; i++)
	//{
	//	cout << decr[i];
	//}

	for (int i = 0; i < Length; i++)
	{
		delete[]lang[i];
	}
	delete[]lang;
	delete[]key;
	delete[]cipher;
	delete[]decr;
	_getch();
}