// Osipov_Shushkanov_Kulichkov.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	//setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	if (argc != 5){
		return 0;
	}

	string str;
	string str1;
	string str2;
	char name;
	char s1;
	char s;
	char *pass = argv[4];
	int i, k;
	string pass1;

	

	while (1) {
		do
		{
			cout << "Choose the action" << endl << "encode (1)" << endl << "decode (2)" << endl;
			cin >> i;
			switch (i)
			{
			case 1:
			{

				str = argv[1];
				ifstream fin(str, ios::binary); // открыли файл для чтения
				if (!fin){
					return 0;
				}
				str1 = argv[2];
				ofstream fout(str1, ios::binary);
				if (!fout){
					return 0;
				}

				i = 0;
				while (fin.get(s)) {
					s1 = (char)((s + pass[(i) % (strlen(pass))] + 1) % 256);
					fout << s1;
					//cout << s1;
					i++;
				}
				cout << "Mission complete" << endl;
				fin.close();
				fout.close();
			}
			break;

			case 2:
			{
				str1 = argv[2];
				ifstream fin(str1, ios::binary); // открыли файл для чтения
				if (!fin){
					return 0;
				}
				str2 = argv[3];
				ofstream fout(str2, ios::binary);
				if (!fout){
					return 0;
				}
				i = 0;
				while (fin.get(s)) {
					s1 = (char)((s + 255 - pass[(i) % (strlen(pass))]) % 256);
					fout << s1;
					//cout << s1;
					i++;
				}
				cout << "Mission complete" << endl;
				fin.close();
				fout.close();
			}
			break;


			}
		} while (i<1 || i>2);
	}
	return 0;
}

