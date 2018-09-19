// ShilovaZI1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;


void Code(char* file, char* key)
{
	//setlocale(LC_ALL, "RU");
	char ch;
	vector< char> tword;
	vector< char> tkey;
	ifstream d,k;
	
	d.open(file);
		while (!d.eof())
		{
			while (d.get(ch))
			{
				tword.push_back(ch);
				cout << ch;
			}
			cout << endl;
		}
	d.close();	
	
	//key
	
	k.open(key);
	while (!k.eof())
	{
		while (k.get(ch))
		{
			tkey.push_back(ch);
			cout << ch;
		}
	}
	k.close();

	//делаем шифр длины текста
	int j = 0;
	int raznitsa = tword.size() - tkey.size();
	for (int i = 0; i < raznitsa; i++)
	{
		 char ch1 = tkey[j];
		tkey.push_back(ch1);
		j++;
	}
	//шифрование  Виженера
	vector <char> ztextvec;
	int ztext;
	for (int i = 0; i < tword.size(); i++)
	{
		int textasc = (int)(tword[i]);
		int shifrasc = (int)(tkey[i]);
		if (textasc + shifrasc < 256)
		{
			ztext = shifrasc + textasc;
		}
		else
		{
			ztext = shifrasc + textasc - 256;
		}
		char ch2 = (char)(ztext);
		ztextvec.push_back(ch2);
	}

	//Запись в файл
	string textz;
	cout << "Output file name(name.txt)  " << endl;
	cin >> textz;
	ofstream ostr(textz);
	if (ostr)
	{
		for (int i = 0; i < ztextvec.size(); i++)
		{
			ostr << ztextvec[i];
		}
		cout << endl;
		cout << "The recording was successful" << endl;
		ostr.close();
	}
	else
	{
		cerr << "The file did not open" << endl;
		return;
	}
	
}

void Decode(char* file,char* key)
{
	setlocale(LC_ALL, "RU");
	char ch;
	vector< char> tword;
	vector< char> tkey;
	ifstream d;
	
	d.open(file);
	while (!d.eof())
	{
		while (d.get(ch))
		{
			tword.push_back(ch);
			cout << ch;
		}
		cout << endl;
	}
		d.close();

			//key
			
			ifstream k;
			k.open(key);
				while (!k.eof())
				{
					while (k.get(ch))
					{
						tkey.push_back(ch);
						cout << ch;
					}
				}
            k.close();
			

			//делаем шифр длины текста
			int j = 0;
			int raznitsa = tword.size() - tkey.size();
			for (int i = 0; i < raznitsa; i++)
			{
				ch = tkey[j];
				tkey.push_back(ch);
				j++;
			}
			//дешифровка Виженера
			vector <char> ztextvec;
			int ztext;
			for (int i = 0; i < tword.size(); i++)
			{
				int textasc = (int)(tword[i]);
				int shifrasc = (int)(tkey[i]);
				if (textasc + shifrasc < 0)
				{
					ztext = textasc - shifrasc;
				}
				else
				{
					ztext = textasc - shifrasc + 256;
				}
				char ch1 = (char)(ztext);
				ztextvec.push_back(ch1);
			}
			//Запись в файл
			string textz;
			cout << endl;
			cout << "Output file name(name.txt)  " << endl;
			cin >> textz;
			ofstream ostr(textz);
			if (ostr)
			{
				for (int i = 0; i < ztextvec.size(); i++)
				{
					ostr << ztextvec[i];
				}
				cout << endl;
				cout << "The recording was successful" << endl;
				ostr.close();
			}
			else
			{
				cerr << "The file did not open" << endl;
				return;
			}		
		}
		
int main(int argc, char* argv[])
{
	Code(argv[1], argv[2]);
	Decode(argv[1], argv[1]);
	return 0;
}
	

