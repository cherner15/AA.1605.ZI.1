// methods_LR1_Ershova.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void Encode(char* word, char* key, char* out)
{
	vector<unsigned char> Word;
	vector<unsigned char> Encoded;
	vector<unsigned char> Key;
	unsigned char ch, ci, cj;
	int b, d, code, j;
	char che;
	ifstream f;
	cout << "Исходный текст: ";
	f.open(word);
	while (!f.eof())
	{
		while (f.get(che))
		{
			Word.push_back(che);
			cout << che;
		}
	}
	f.close();
	cout << endl;
	f.open(key);
	cout << "Ключ: ";
	while (!f.eof())
	{
		while (f.get(che))
		{
			Key.push_back(che);
			cout << che;
		}
	}
	f.close();
	cout << endl;
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
	ofstream t;
	cout << "Зашифрованный текст: ";
	t.open(out);
	for (int i = 0; i < Encoded.size(); i++)
	{
		cout << Encoded[i];
		t << Encoded[i];
	}
	cout << endl;
	t.close();
}

void Decode(char* key, char* out, char* deout)
{
	vector<unsigned char> Decoded;
	vector<unsigned char> Encoded;
	vector<unsigned char> Key;
	char che;
	ifstream f;
	f.open(out);
	while (!f.eof())
	{
		while (f.get(che))
		{
			Encoded.push_back(che);
			//cout << che;
		}
	}
	f.close();
	f.open(key);
	while (!f.eof())
	{
		while (f.get(che))
		{
			Key.push_back(che);
			//cout << che;
		}
	}
	f.close();
	for (int i = 0; i < Encoded.size(); i++)
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
	ofstream d;
	d.open(deout);
	cout << "Расшифрованный текст: ";
	for (int i = 0; i < Decoded.size(); i++)
	{
		cout << Decoded[i];
		d << Decoded[i];
	}
	cout << endl;
	d.close();
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	Encode(argv[1], argv[2], argv[3]);
	Decode(argv[2], argv[3], argv[4]);
	return 0;
}

