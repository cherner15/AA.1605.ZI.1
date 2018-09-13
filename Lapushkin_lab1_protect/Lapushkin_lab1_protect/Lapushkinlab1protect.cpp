// Lapushkinlab1protect.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "string"
#include "vector"


using namespace std;

vector <char> Word;

string WordIn(string C)
{
	ofstream fin;
	fstream fin1;
	string Y;
	fin.open(C);
	fin.close();
	cout << " Write your word and press any letter then enter to continue.";
	cin >> Y;
	fin1.open(C);
	char ch;
	string W = "";

	fin1 >> ch;
	W = W + ch;
	while (fin1.get(ch))
	{
		W = W + ch;
	}
	fin1.close();
	return W;
}

void   WordOut(string C, int c, int *YY = new int[100])
{
	ofstream out;
	out.open(C);

	if (!out.is_open())
	{
		cout << "err";
	}
	else
	{
		for (int i = 0; i<c; i++)
			out << (char)YY[i];
	}
	delete[] YY;
}

void ALAN()
{
	string A, B, Q;
	int *YY = new int[100];

	cout << "Name of input word file  " << endl;
	cin >> A;
	A = A + ".txt";

	cout << "Name of input key file  " << endl;
	cin >> B;
	B = B + ".txt";

	cout << "Name of ouput word file  " << endl;
	cin >> Q;
	Q = Q + ".txt";

	string C, D, M;
	string T = "";
	int c, d;
	C = WordIn(A);
	D = WordIn(B);
	c = C.length();
	d = D.length();
	if (c >= d)
	{
		for (int i = 0; i < (c / d); i++) {
			T = T + D;

		}
		for (int j = 0; j < (c%d); j++) {
			T = T + D[j];
		}
	}

	else {
		for (int s = 0; s < c; s++)
			T = T + D[s];
	}



	for (int i = 0; i < c; i++)
	{
		YY[i] = 255 - (int)T[i] + (int)C[i] + 1;
		if (YY[i] > 255)
			YY[i] - 255;

	}
	WordOut(Q, c, YY);

}

void TURING()
{
	string A, B, Q;
	int *YY = new int[100];

	cout << "Name of input coded word file  " << endl;
	cin >> A;
	A = A + ".txt";

	cout << "Name of input key file  " << endl;
	cin >> B;
	B = B + ".txt";

	cout << "Name of ouput word file  " << endl;
	cin >> Q;
	Q = Q + ".txt";

	string C, D, M;
	string T = "";
	int c, d;
	C = WordIn(A);
	D = WordIn(B);
	c = C.length();
	d = D.length();
	if (c >= d)
	{
		for (int i = 0; i < (c / d); i++) {
			T = T + D;

		}
		for (int j = 0; j < (c%d); j++) {
			T = T + D[j];
		}
	}

	else {
		for (int s = 0; s < c; s++)
			T = T + D[s];
	}



	for (int i = 0; i < c; i++)
	{
		YY[i] = (int)T[i] + (int)C[i];
		if (YY[i] > 255)
			YY[i] - 255;

	}
	WordOut(Q, c, YY);

}


int main()
{
	int k;
	cout << "1- code , 2 - uncode  ";
	cin >> k;
	switch (k) {
	case 1: ALAN();
	break;
	case 2: TURING(); 
	return 0;
	}


	system("pause");

	return 0;
}
