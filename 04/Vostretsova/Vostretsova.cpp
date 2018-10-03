// Vostretsova.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;


void Code(int n, char* mas[])
{
	fstream file(mas[1], ios::binary);
	if (!file) 
	{
		return;
	}
	char ch, c;
	string s;
	fstream key(mas[2], ios::binary);
	if (!key)
	{
		return;
	}
	key >> s;
	int l = s.length();
	char k;
	ofstream fout(mas[3], ios::binary);
	if (!fout)
	{
		return;
	}
	ch = file.get();
	int i = 1;
	while (!file.eof())
	{

		k = s[i];
		int p;
		p = int(ch + k) % 256;
		c = (char)p;
		fout << c;
		ch = file.get();
		i++;
		if (i == l) i = 1;
	}
	fout.close();
	file.close();
	key.close();
}

void Decode(int n, char* mas[])
{
	fstream fout(mas[3], ios::binary);
	if (!fout)
	{
		return;
	}
	char ch, c;
	string s;
	fstream key(mas[2], ios::binary);
	if (!key)
	{
		return;
	}
	key >> s;
	int l = s.length();
	char k;
	ofstream ffout(mas[4], ios::binary);
	if (!ffout)
	{
		return;
	}
	ch = fout.get();
	int i = 1;
	while (!fout.eof())
	{
		k = s[i];
		int p;
		p = int(ch - k + 256) % 256;
		c = (char)p;
		fout << c;
		ch = fout.get();
		i++;
		if (i == l) i = 1;
	}
	ffout.close();
	fout.close();
	key.close();
}

int Menu()
{
	int i;
	cout << "Menu:\n1 - Code\n2 - Decode\n0 - Exit" << endl;
	cin >> i;
	return i;
}

void start(int n, char* mas[])
{
	while (1)
	{
		switch (Menu())
		{
		case 1:
		{
			Code(n, mas);
			break;
		}
		case 2:
		{
			Decode(n, mas);
			break;
		}
		default:
		{
			return;
		}
		}
	}
}

int main(int argc, char* argv[])
{
	start(argc, argv);
	return 0;
}

