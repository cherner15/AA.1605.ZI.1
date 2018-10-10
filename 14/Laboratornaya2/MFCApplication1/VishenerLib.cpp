#include "stdafx.h"
#include "VishenerLib.h"
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


void Decryption(unsigned char** lang, unsigned char* key, int counter, int textLength, unsigned const char* dipher, unsigned char* decr)
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
		if (lang[row][i] == dipher[counter])
		{
			col = i;
			temp = 0;
			break;
		}
	}
	if (lang[0][col])
		decr[counter] = lang[0][col];
	else
		decr[counter] = ' ';
}


void Encryption(unsigned char** lang, unsigned char* key, int textLength, int counter, const char* text, unsigned char* cipher)
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
	// раст€гиваем ключ
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
			lang[row][col] = letter;			// заполн€ем текущий символ
			letter++;							// увеличи на 1 дл€ изменени€ символа
			if (letter == 256) letter = start;	// выход за границу
		}
		counter++;								//увеличили кол-во пройденных строк
		letter = start + counter;
	}
}


int VishenerEncodeDecode(VishenerOperationType type, std::string& text,wstring const& sKey,string& decriptedText)
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice = 0;

	cerr << "Input 1 for Encryption" << endl;
	cin >> choice;

	// выделение пам€ти дл€ таблицы ¬иженера
	unsigned char** lang = new unsigned char*[Length];
	for (int i = 0; i < Length; i++)
	{
		lang[i] = new unsigned char[Length];
	}

	FillTable(lang);
	int textLength = text.length();
	unsigned char* key = new unsigned char[textLength];
	decriptedText.resize(textLength);

	FillKey(key, textLength, sKey);
	if (type == Encription)
	{
		for (int i = 0; i < textLength; i++)
		{
			Encryption(lang, key, textLength, i, text.c_str(), (unsigned char*)&decriptedText[0]);
		}
	}
	else
	{
		for (int i = 0; i < textLength; i++)
		{
			Decryption(lang, key, i, textLength, (unsigned const char*)text.c_str(), (unsigned char*)&decriptedText[0]);
		}
	}

	for (int i = 0; i < Length; i++)
	{
		delete[]lang[i];
	}
	delete[]lang;
	delete[]key;
	return 0;
}