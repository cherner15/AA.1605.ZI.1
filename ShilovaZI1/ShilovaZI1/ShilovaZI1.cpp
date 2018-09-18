// ShilovaZI1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

int menu()
{
	setlocale(LC_ALL, "RU");
	cout << "Menu\n1-Code\n2-Decode\n3-Exit\n" << endl;
	int n;
	cin >> n;
	return n;
}
void start()
{
	setlocale(LC_ALL, "RU");
	int k;
	char ch;
	while (1)
	{
		switch (menu())
		{
		case 1:
		{
			//char ch1;
			ifstream d;
			d.open("text1.txt");
			vector< unsigned char> tword;
			if (!d.is_open()) // если файл не открыт
				cout << "The file did not open!" << endl; // сообщить об этом
			else
			{
				cout << "File is open!\n";
				while (!d.eof())
				{
					while (d.get(ch))
					{
						tword.push_back(ch);
						cout << ch;
					}
					cout << endl;
				}
			}
			d.close();

			//key
			char key;
			ifstream k;
			k.open("key.txt");
			vector< unsigned char> tkey;
			if (!k.is_open()) // если файл не открыт
				cout << "The file did not open!\n" << endl; // сообщить об этом
			else
			{
				cout << endl;
				cout << "File is open!"; // сообщить об этом
				cout << endl;
				while (!k.eof())
				{
					while (k.get(ch))
					{
						tkey.push_back(ch);
						cout << ch;
					}
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
				char ch1 = (char)(ztext);
				ztextvec.push_back(ch1);
			}

			ofstream ostr;
			ostr.open("ztext.txt");
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
			break; 
		}
		case 2:
		{
				ifstream d;
				d.open("ztext.txt");
				vector< unsigned char> tword;
				if (!d.is_open()) // если файл не открыт
					cout << "The file did not open!" << endl; // сообщить об этом
				else
				{
					cout << "File is open!\n";
					while (!d.eof())
					{
						while (d.get(ch))
						{
							tword.push_back(ch);
							cout << ch;
						}
					}
				}
				d.close();

				//key
				char key;
				ifstream k;
				k.open("key.txt");
				vector< unsigned char> tkey;
				if (!k.is_open()) // если файл не открыт
					cout << "The file did not open!\n" << endl; // сообщить об этом
				else
				{
					cout << endl;
					cout << "File is open!"; // сообщить об этом
					cout << endl;
					while (!k.eof())
					{
						while (k.get(ch))
						{
							tkey.push_back(ch);
							cout << ch;
						}
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

				ofstream ostr;
				ostr.open("text2.txt");
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
				else { cerr << "The file did not open" << endl; return; }
				break;
			}
		case 3:
		{
			return;
		}
		}
	}
}
int main()
{
	start();
}

