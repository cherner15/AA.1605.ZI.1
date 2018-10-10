#include <iostream>
#include <fstream> 
#include <vector> 
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	argv[1] = "a.txt";
	argv[2] = "b.txt";
	argv[3] = "c.txt";
	argv[4] = "d.txt";

	char che;
	unsigned char ch;
	ifstream file_1(argv[1]);
	vector <unsigned char> text_vector;
	while (!file_1.eof())
	{
		while (file_1.get(che)) //get(ch) читает из потока 1 символ и помещает его в ch
		{
			text_vector.push_back(che);
		}
	}
	file_1.close();
	ifstream file_2(argv[2]);
	vector <unsigned char> code_vector;
	while (!file_2.eof())
	{
		while (file_2.get(che))
		{
			code_vector.push_back(che);
		}
	}
	file_2.close();

	//делаем шифр длины текста
	int j = 0;
	int raznitsa = text_vector.size() - code_vector.size();
	for (int i = 0; i < raznitsa; i++)
	{
		ch = code_vector[j];
		code_vector.push_back(ch);
		j++;
	}
	
	//шифр Виженера
	vector <unsigned char> otext_vector;
	int otext_ascii;
	for (int i = 0; i < text_vector.size(); i++)
	{
		int text_ascii = (int)(text_vector[i]);
		int code_ascii = (int)(code_vector[i]);
		if (text_ascii + code_ascii < 256)
		{
			otext_ascii = code_ascii + text_ascii;
		}
		else
		{
			otext_ascii = code_ascii + text_ascii - 256;
		}
		char ch2 = (char)(otext_ascii);
		otext_vector.push_back(ch2);
	}

	ofstream file_3(argv[3]);
	for (int i = 0; i < otext_vector.size(); i++)
	{
		file_3 << otext_vector[i];
	}
	file_3.close();
		
		//дешифр Виженера
		vector <unsigned char> ootext_vector;
		int ootext_ascii;
		for (int i = 0; i < otext_vector.size(); i++)
		{
			int otext_ascii = (int)(otext_vector[i]);
			int code_ascii = (int)(code_vector[i]);
			if (otext_ascii + code_ascii < 0)
			{
				ootext_ascii = otext_ascii - code_ascii;
			}
			else
			{
				ootext_ascii = otext_ascii - code_ascii + 256;
			}
			char ch2 = (char)(ootext_ascii);
			ootext_vector.push_back(ch2);
		}

		ofstream file_4(argv[4]);
		for (int i = 0; i < ootext_vector.size(); i++)
		{
			file_4 << ootext_vector[i];
		}
		file_4.close();
		system("Pause");
}
