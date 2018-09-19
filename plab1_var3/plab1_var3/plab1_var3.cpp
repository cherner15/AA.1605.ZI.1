// plab1_var3.cpp : Defines the entry point for the console application.
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

void GetText()
{
	string filename;
	char ch;
	ifstream f(filename);
	cout << "Input the name of the file with text:" << endl;
	cin >> filename;
	filename = filename + ".txt";
	f.open(filename);
	while (!f.is_open()) {
		cout << "input the correct filename : " << endl;
		cin >> filename;
		filename = filename + ".txt";
		f.open(filename);
	}
	cout << "Your text: ";
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

void GetPass()
{
	int len,check;
	char ch[10];

	  for (int i = 0; i < 10; i++){
		  ch[i] = 0;
	  	  }
	  
	len = 0;
	check = 0;

	cout << "\nInput the key length (<10)" << endl;
	cin >> len;
	while ((len < 1) || (len>10) || (Text.size() < len)){
		cout << "\nInput the correct key length" << endl;
		cin >> len;
	};

	cout << "\nInput the key" << endl;
	cin >> ch;
	check = 0;
	for (int j = 0; j < 10; j++){
		if (ch[j]){
			check++;
		}
	};
	while (check!=len) {
		for (int i = 0; i < 10; i++){
			ch[i] = 0;
		};
		cout << "\nInput the correct key" << endl;
		cin >> ch;
		check = 0;
		for (int j = 0; j < 10; j++){
			if (ch[j]){
				check++;
			}
		}
	};
	
		Key.assign(ch, ch + len);
		cout << "Key: ";
		cout << ch;
		cout << endl;
			
	}


void ShifrKoroley()
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

int main()
{
	setlocale(LC_ALL, "Russian");
	GetText();
	GetPass();
	ShifrKoroley();
	string filename, filename1;
	cout << "\nInput the filename for encoded text output:" << endl;
	cin >> filename;
	filename = filename + ".txt";
	cout << "Encoded text: ";
	ofstream f(filename);
	for (int i = 0; i < Encoded.size(); i++)
	{
		cout << Encoded[i];
		f << Encoded[i];
	}
	cout << endl;

	Decode();
	cout << "\nInput the filename for decoded text output:" << endl;
	cin >> filename1;
	filename1 = filename1 + ".txt";
	while (filename == filename1) {
		cout << "Filenames are the same. Enter the correct filename: " << endl;
		cin >> filename1;
		filename1 = filename1 + ".txt";
		f.open(filename);
	}
	cout << "Decoded text: ";
	ofstream fout(filename1);
	for (int i = 0; i < Encoded.size(); i++)
	{
		cout << Decoded[i];
		fout << Decoded[i];
	}
	cout << endl;
	return 0;
}


