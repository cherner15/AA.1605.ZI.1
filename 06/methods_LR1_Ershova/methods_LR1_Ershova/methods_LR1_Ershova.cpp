// methods_LR1_Ershova.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<unsigned char> Word;
vector<unsigned char> Encoded;
vector<unsigned char> Key;
vector<unsigned char> Decoded;

void GetWord()
{
	string name;
	char ch;
	ifstream f(name);
	cout << "Введите название файла с текстом (без .TXT):" << endl;
	cin >> name;
	name = name + ".txt";
	f.open(name);
	while (!f.is_open()) {
		cout << "Введите заново: " << endl;
		cin >> name;
		name = name + ".txt";
		f.open(name);
	}
	cout << "Исходный текст: ";
	while (!f.eof())
	{
		while (f.get(ch))
		{
			Word.push_back(ch);
			cout << ch;
		}
	}
	cout << endl;
	f.close();
}

void GetKey()
{
	string name;
	char ch;
	ifstream f(name);
	cout << "\nВведите название файла с ключом (без .TXT):" << endl;
	cin >> name;
	name = name + ".txt";
	f.open(name);
	while (!f.is_open()) {
		cout << "Введите заново: " << endl;
		cin >> name;
		name = name + ".txt";
		f.open(name);
	}
	cout << "Ключ: ";
	while (!f.eof())
	{
		while (f.get(ch))
		{
			Key.push_back(ch);
			cout << ch;
		}
	}
	cout << endl;
}

void Vizhener()
{
	unsigned char ch, ci, cj;
	int b, d, code, j;
	for (int i = 0; i < Word.size(); i++)
	{
		j = 0;
		if (j < Key.size())
		{
			ch = Word[i];
			b = (int)ch;
			ci = Key[j];
			d = (int)ci;
			if ((d + b) <= 255)
			{
				code = (d + b);
				cj = (char)code;
				Encoded.push_back(cj);
			}
			else
			{
				code = (d + b - 256);
				cj = (char)code;
				Encoded.push_back(cj);
			}
			j++;
		}
		else {
			j = 0;
			ch = Word[i];
			b = (int)ch;
			ci = Key[j];
			d = (int)ci;
			if ((d + b) <= 255)
			{
				code = (d + b);
				cj = (char)code;
				Encoded.push_back(cj);
			}
			else
			{
				code = (d + b - 256);
				cj = (char)code;
				Encoded.push_back(cj);
			}
			j++;
		}
	}
}

void Decode()
{
	for (int i = 0; i < Word.size(); i++)
	{
		unsigned char ch, ci, cj;
		int b, d, code, j;
		j = 0;
		if (j < Key.size())
		{
			ch = Encoded[i];
			b = (int)ch;
			ci = Key[j];
			d = (int)ci;
			if ((b - d) < 0)
			{
				code = (b - d + 256);
				cj = (char)code;
				Decoded.push_back(cj);
			}
			else
			{
				code = (b - d);
				cj = (char)code;
				Decoded.push_back(cj);
			}
			j++;
		}
		else {
			j = 0;
			ch = Encoded[i];
			b = (int)ch;
			ci = Key[j];
			d = (int)ci;
			if ((b - d) < 0)
			{
				code = (b - d + 256);
				cj = (char)code;
				Decoded.push_back(cj);
			}
			else
			{
				code = (b - d);
				cj = (char)code;
				Decoded.push_back(cj);
			}
			j++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	GetWord();
	GetKey();
	Vizhener();

	string name, name1;
	cout << "\nВведите название файла для вывода зашифрованного текста:" << endl;
	cin >> name;
	name = name + ".txt";
	cout << "Зашифрованный текст: ";
	ofstream f(name);
	for (int i = 0; i < Encoded.size(); i++)
	{
		cout << Encoded[i];
		f << Encoded[i];
	}
	cout << endl;

	Decode();
	cout << "\nВведите название файла для вывода расшифрованного текста:" << endl;
	cin >> name1;
	name1 = name1 + ".txt";
	while (name == name1) {
		cout << "Названия совпадают, введите заново: " << endl;
		cin >> name1;
		name1 = name1 + ".txt";
		f.open(name);
	}
	cout << "Расшифрованный текст: ";
	ofstream fout(name1);
	for (int i = 0; i < Encoded.size(); i++)
	{
		cout << Decoded[i];
		fout << Decoded[i];
	}
	cout << endl;
	return 0;
}

