// visiner.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
#include <fstream>

using namespace std;

int numcode(string n,int c) 
{
	string p,k;
	k = n[c];
	for (int i = 0; i < 256; i++ )
	{
		p = char(i);
		if (k == p)
			c = i;
	}
	return c;
}

string Decode(string text, string key)
{
	string result;
	int j, sum, a;
	for (int i = 0; i < text.length(); i++)
	{
		j = 0;
		if (j >= key.length())
			j = 0;
		j++;
		sum = numcode(text, i);
		a = numcode(key, j);
		sum -= a;
		if (sum < 1)
			sum += 256;
		result += char(sum);
	}
	j = 0;
	return result;
}

string Encode(string text, string key)
{
	string result;
	int j, sum, a;
	for (int i = 0; i < text.length(); i++) 
	{
		j = 0;
		if (j >= key.length())
			j = 0;
		j++;
		sum = numcode(text, i);
		a = numcode(key, j);
		sum += a;
		if (sum > 256)
			sum -= 256;
		result += char(sum);
	}
	j = 0;
	return result;
}

string inputtext(string file)
{	string text;
	char inf;
	ifstream in;
	in.open(file);
	if (!in.is_open())
		cout << "File can not be open!";
	else
	{
		in >> inf;
		text += inf;
		while (in.get(inf))
		{
			text += inf;
		}
	}
	in.close();
	return text;
}

int main()
{	
	setlocale(LC_ALL, "Russian");
	ifstream in;
	ofstream out;
	string  tfile, kfile, inft, infk,rfile, result;
	int menu;
	for (;;)
	{
		cout << "Hello, dear user!\n";
		cout << "Please choose an operation: \n";
		cout << "1. Encode.\n";
		cout << "2. Decode.\n";
		cout << "0. Exit." << endl;
		cin >> menu;
		if (menu > 2 or menu < 0)
			cout << "Error! Enter correct number!" << endl;
		else
		{
			switch (menu)
			{
			case 1:
			{
				cout << "Enter file name of text: ";
				cin >> tfile;
				tfile = tfile + ".txt";
				out.open(tfile);
				out.close();

				cout << "Enter file name of key: ";
				cin >> kfile;
				kfile = kfile + ".txt";
				out.open(kfile);
				out.close();

				cout << "Enter file name of result: ";
				cin >> rfile;
				rfile = rfile + ".txt";
				system("pause");

				inft = inputtext(tfile);
				infk = inputtext(kfile);
				result = Encode(inft, infk);
				out.open(rfile);
				if (!out.is_open())
					cout << "File can not be open!";
				else
					out << result;
				out.close();
				break;
			}
			case 2:
			{
				cout << "Enter file name of text: ";
				cin >> tfile;
				tfile = tfile + ".txt";
				out.open(tfile);
				out.close();

				cout << "Enter file name of key: ";
				cin >> kfile;
				kfile = kfile + ".txt";
				out.open(kfile);
				out.close();

				cout << "Enter file name of result: ";
				cin >> rfile;
				rfile = rfile + ".txt";
				system("pause");

				inft = inputtext(tfile);
				infk = inputtext(kfile);
				result = Decode(inft, infk);
				out.open(rfile);
				if (!out.is_open())
					cout << "File can not be open!";
				else
					out << result;
				out.close();
				
				break;
			}
			case 0:
			{
			exit;	
			}
			return 0;
			}
		}
		
	}

}

