#include <iostream>
#include <fstream> 
#include <vector> 
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int i;
	cout << "��� ��� ���������?" << endl;
	cout << "1 - ����������� �����" << endl;
	cout << "2 - ������������ �����" << endl;
	cin >> i;
	do
	{
		switch (i)
		{
		case 1:
			break;
		case 2:
			break;
		default:
			cout << "�� ����� �� ��! ���������� ����� :)" << endl;
			int i;
			cout << "��� ��� ���������?" << endl;
			cout << "1 - ����������� �����" << endl;
			cout << "2 - ������������ �����" << endl;
			cin >> i;
		}
	} while (!((i == 1) || (i == 2)));

	char ch;

	if (i == 1)
	{
		//��������� �� text.txt � ������ text_vector
		string text;
		cout << "������� �������� ����� ��� ���������� (text.txt): " << endl;
		cin >> text;
		ifstream file_1(text);
		vector <unsigned char> text_vector;
		while (!file_1.eof())
		{
			while (file_1.get(ch)) //get(ch) ������ �� ������ 1 ������ � �������� ��� � ch
			{
				text_vector.push_back(ch);
			}
		}
		file_1.close();
		//cout << text_vector.size() << endl;

		//��������� �� code.txt � ������ code_vector

		string code;
		cout << "������� �������� ����� � ������ (code.txt): " << endl;
		cin >> code;
		ifstream file_2(code);
		vector <unsigned char> code_vector;
		while (!file_2.eof())
		{
			while (file_2.get(ch))
			{
				code_vector.push_back(ch);
			}
		}
		file_2.close();
		//cout << code_vector.size() << endl;

		//������ ���� ����� ������
		int j = 0;
		int raznitsa = text_vector.size() - code_vector.size();
		for (int i = 0; i < raznitsa; i++)
		{
			ch = code_vector[j];
			code_vector.push_back(ch);
			j++;
		}
		//cout << code_vector.size() << endl;

		//���� ��������
		vector <char> otext_vector;
		int otext_ascii;
		for (int i = 0; i < text_vector.size(); i++)
		{
			int text_ascii = (int)(text_vector[i]);
			//cout << "text: " << text_ascii << endl;
			int code_ascii = (int)(code_vector[i]);
			//cout << "code: " << code_ascii << endl; 
			if (text_ascii + code_ascii < 256)
			{
				otext_ascii = code_ascii + text_ascii;
				//cout << "otext: " << otext_ascii << endl;
			}
			else
			{
				otext_ascii = code_ascii + text_ascii - 256;
				//cout << "otext: " << otext_ascii << endl;
			}
			char ch2 = (char)(otext_ascii);
			otext_vector.push_back(ch2);
		}

		//���������� � �������� ���� otext_txt ������ otext.txt
		string otext;
		cout << "������� �������� ����� ��� ������ �������������� ����� (otext.txt): " << endl;
		cin >> otext;
		ofstream file_3(otext);
		for (int i = 0; i < otext_vector.size(); i++)
		{
			file_3 << otext_vector[i];
		}
	}
	else 
	{
		//��������� �� text.txt � ������ text_vector
		string text;
		cout << "������� �������� ����� ��� ����������� (text.txt): " << endl;
		cin >> text;
		ifstream file_1(text);
		vector <unsigned char> text_vector;
		while (!file_1.eof())
		{
			while (file_1.get(ch)) //get(ch) ������ �� ������ 1 ������ � �������� ��� � ch
			{
				text_vector.push_back(ch);
			}
		}
		file_1.close();
		//cout << text_vector.size() << endl;

		//��������� �� code.txt � ������ code_vector

		string code;
		cout << "������� �������� ����� � ������ (code.txt): " << endl;
		cin >> code;
		ifstream file_2(code);
		vector <unsigned char> code_vector;
		while (!file_2.eof())
		{
			while (file_2.get(ch))
			{
				code_vector.push_back(ch);
			}
		}
		file_2.close();
		//cout << code_vector.size() << endl;

		//������ ���� ����� ������
		int j = 0;
		int raznitsa = text_vector.size() - code_vector.size();
		for (int i = 0; i < raznitsa; i++)
		{
			ch = code_vector[j];
			code_vector.push_back(ch);
			j++;
		}
		//cout << code_vector.size() << endl;

		//������ ��������
		vector <char> otext_vector;
		int otext_ascii;
		for (int i = 0; i < text_vector.size(); i++)
		{
			int text_ascii = (int)(text_vector[i]);
			//cout << text_ascii << endl;
			int code_ascii = (int)(code_vector[i]);
			if (text_ascii + code_ascii < 0)
			{
				otext_ascii = text_ascii - code_ascii;
				//cout << otext_ascii << endl; 
			}
			else
			{
				otext_ascii = text_ascii - code_ascii + 256;
				//cout << otext_ascii << endl; 
			}
			char ch2 = (char)(otext_ascii);
			otext_vector.push_back(ch2);
		}

		//���������� � �������� ���� otext_txt ������ otext.txt
		string otext;
		cout << "������� �������� ����� ��� ������ �������������� ����� (otext.txt): " << endl;
		cin >> otext;
		ofstream file_3(otext);
		for (int i = 0; i < otext_vector.size(); i++)
		{
			file_3 << otext_vector[i];
		}
	}
	//for (vector <char> ::const_iterator i = otext_vector.begin(); i != otext_vector.end(); ++i)
	//	otext << *i;
	//otext.close();

	//system("Pause");
}