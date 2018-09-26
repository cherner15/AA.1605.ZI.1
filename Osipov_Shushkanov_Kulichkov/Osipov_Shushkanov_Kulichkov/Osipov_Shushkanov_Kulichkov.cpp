// Osipov_Shushkanov_Kulichkov.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<unsigned char> Text;
vector<unsigned char> Encoded;
vector<unsigned char> Key;
vector<unsigned char> Decoded;

void GetText(string name)
{
	//string name;
	char ch;
	ifstream f(name);
	//cout << "������� �������� ����� � ������� (��� .TXT):" << endl;
	//cin >> name;
	name = name + ".txt";
	f.open(name);
	while (!f.is_open()) {
		cout << "������� ������: " << endl;
		cin >> name;
		name = name + ".txt";
		f.open(name);
	}
	cout << "�������� �����: ";
	while (!f.eof())
	{
		while (f.get(ch))
		{
			Text.push_back(ch);
			cout << ch;
		}
	}
	cout << endl;
	f.close();
}

void GetKey(char a, char ch[10])
{
	int len = a;
	//cout << "\n������� ����� �����" << endl;
	//cin >> len;
	//cout << "\n������� ����" << endl;
	//cin >> ch;
	//while (!ch==0) {
	//    cout << "������� ������: " << endl;
	// cin >> ch;
	//}
	Key.assign(ch, ch + len);
	cout << "����: ";
	cout << ch;
	cout << endl;
}

void Shifr_Koroley()
{
	unsigned char ch, ci, cj;
	int b, d, code, j;
	for (int i = 0; i < Text.size(); i++)
	{
		j = 0;
		if (j > Key.size()) {
			j = 0;
		}
		else
		{
			ch = Text[i];
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
	for (int i = 0; i < Text.size(); i++)
	{
		unsigned char ch, ci, cj;
		int b, d, code, j;
		j = 0;
		if (j > Key.size()) {
			j = 0;
		}
		else
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
	}
}

int main(int argc, char* argv[])
{
	for (int y = 0; y < argc; y++) {
		cout << argv[y] << endl;
	}

	setlocale(LC_ALL, "rus");
	GetText(argv[1]);
	GetKey(*argv[2], argv[3]);
	Shifr_Koroley();

	string name, name1;
	name = argv[4];
	//cout << "\n������� �������� ����� ��� ������ �������������� ������:" << endl;
	//cin >> name;
	name = name + ".txt";
	cout << "������������� �����: ";
	ofstream f(name);
	for (int i = 0; i < Encoded.size(); i++)
	{
		cout << Encoded[i];
		f << Encoded[i];
	}
	cout << endl;

	Decode();
	name1 = argv[5];
	//cout << "\n������� �������� ����� ��� ������ ��������������� ������:" << endl;
	//cin >> name1;
	name1 = name1 + ".txt";
	while (name == name1) {
		cout << "�������� ���������, ������� ������: " << endl;
		cin >> name1;
		name1 = name1 + ".txt";
		f.open(name);
	}
	cout << "�������������� �����: ";
	ofstream fout(name1);
	for (int i = 0; i < Encoded.size(); i++)
	{
		cout << Decoded[i];
		fout << Decoded[i];
	}
	cout << endl;
	return 0;
}


