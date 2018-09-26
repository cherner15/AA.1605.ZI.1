// ChulkovaVizhL1.cpp: ������� ���� �������.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


/*argv[1] = "phrase.txt";
argv[2] = "key.txt";
argv[3] = "shifr.txt";
argv[4] = "ans.txt";*/

void Shifr(char* phrase, char* key, char* shifr)
{
	vector<unsigned char> Phrase;
	vector<unsigned char> shifr_V;
	vector<unsigned char> Key;
	unsigned char let;
	int p, k, c, j = 0;
	char simv;

	ifstream f;
	cout << "������� ����� ��� ����������!!!" << endl;
	f.open(phrase);
	while (!f.eof())
	{
		while (f.get(simv))
		{
			Phrase.push_back(simv);
			//cout << simv;
		}
	}
	f.close();


	f.open(key);
	cout << "������� ���� ��� ����������!!!" << endl;;
	while (!f.eof())
	{
		while (f.get(simv))
		{
			Key.push_back(simv);
			//cout << simv;
		}
	}
	f.close();


	cout << endl;
	for (int i = 0; i < Phrase.size(); i++)
	{
		if (j > Key.size() - 1)
		{
			j = 0;
		}
		let = Phrase[i];
		p = (int)let;
		let = Key[j];
		k = (int)let;
		c = (p + k) % 256;
		simv = (char)c;
		shifr_V.push_back(simv);
		j++;
	}


	ofstream t;
	cout << "����� ������� ����������� � �������� � ����!!! ���!!" << endl;
	t.open(shifr);
	for (int i = 0; i < shifr_V.size(); i++)
	{
		//cout << shifr_V[i];
		t << shifr_V[i];
	}
	t.close();


	shifr_V.clear();
	Phrase.clear();
	Key.clear();
}

void Rasshifr(char* key, char* shifr, char* rasshifr)
{
	vector<unsigned char> shifr_V;
	vector<unsigned char> rasshifr_V;
	vector<unsigned char> Key;
	char simv;
	int j = 0, p, k, c;


	ifstream f;
	f.open(shifr);
	while (!f.eof())
	{
		while (f.get(simv))
		{
			rasshifr_V.push_back(simv);
		}
	}
	f.close();


	f.open(key);
	while (!f.eof())
	{
		while (f.get(simv))
		{
			Key.push_back(simv);
		}
	}
	f.close();


	for (int i = 0; i < rasshifr_V.size(); i++)
	{
		if (j > Key.size() - 1)
		{
			j = 0;
		}
		c = (int)rasshifr_V[i];
		k = (int)Key[j];
		p = (c - k) % 256;
		simv = (char)p;
		shifr_V.push_back(simv);
		j++;
	}


	ofstream d;
	d.open(rasshifr);
	cout << "����� ������� ������������ � �������� � ����!!! ���!!! ";
	for (int i = 0; i < shifr_V.size(); i++)
	{
		//cout << rasshifr_V[i];
		d << shifr_V[i];
	}
	cout << endl;
	d.close();


	rasshifr_V.clear();
	shifr_V.clear();
	Key.clear();

}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	Shifr(argv[1], argv[2], argv[3]);
	Rasshifr(argv[2], argv[3], argv[4]);

	return 0;
}