// vijiner.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>  


using namespace std;

string key;

void shifr()
{
	int i = 0;
	int check = 0;
	ofstream fout("OutputFile.txt", ofstream::binary);
	ifstream finCheck("InputFile.txt", ifstream::binary);
	cout << "insert key word: ";
	cin >> key;
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
		cout << "File not found" << endl;
	}


	ifstream fin("InputFile.txt", ifstream::binary);

	for (int k = 0; k < check - 1; k++)
	{
		char x;
		unsigned char y;
		fin.get(x);
		y = ((unsigned char)x + (unsigned char)key[i]) % 256;
		fout << y;
		i = i + 1;
		if (i == key.length()) i = 0;
	}
	fin.close();
	fout.close();
	{
		ofstream fout1("ReturnFile.txt", ifstream::binary);
		ifstream finFl("OutputFile.txt", ifstream::binary);
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
			cout << "FIle not found" << endl;
		}
		ifstream fin1("OutputFile.txt", ifstream::binary);
		int i = 0;
		for (int k = 0; k < check - 1; k++)
		{
			char x;
			unsigned char y;

			fin1.get(x);
			y = ((unsigned char)x - (unsigned char)key[i]) % 256;
			fout1 << y;
			i = i + 1;
			if (i == key.length()) i = 0;
		}
	}
}





void main(int argc ,char *argv[])
{
	

	
	setlocale(LC_ALL, "Russian");

	
	{
		shifr();
	} 

	
}