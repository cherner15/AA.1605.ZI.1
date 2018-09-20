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
	//шифрование  Виженера
	vector <char> ztextvec;
	int ztext;
	for (int i = 0; i < tword.size(); i++)
	{
		int text = (int)(tword[i]);
		int shifr = (int)(tkey[i]);
		if (text + shifr < 256)
		{
			ztext = shifr + text;
		}
		else
		{
			ztext = shifr + text - 256;
		}
		char ch1 = (char)(ztext);
		ztextvec.push_back(ch1);
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
	
	/*d.open(file);
	while (!d.eof())
	{
		while (d.get(ch))
		{
			tword.push_back(ch);
			cout << ch;
		}
	}
    d.close();*/

	string w;
	cout << "Input file name for decode(name.txt)  " << endl;
	cin >> w;
	ifstream in(w);
	if (in)
	{
		while (!in.eof())
		{
			while (in.get(ch))
			{
				tword.push_back(ch);
				cout << ch;
				
			}cout << endl;
		}
		cout << endl;
		cout << "The recording was successful" << endl;
		in.close();
	}
	else
	{
		cerr << "The file did not open" << endl;
		return;
	}
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
			cout << "Output file name(name.txt)  " << endl;
			cin >> textz;
			ofstream ostr(textz);
			if (ostr)
			{
				for (int i = 0; i < ztextvec.size(); i++)
				{
					ostr << ztextvec[i];
				}
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
	cout << " "<< endl;
	Decode(argv[1], argv[2]);
	return 0;
}
	

 