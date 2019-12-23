#include"pch.h"
#include "CAC.h"
#include <iostream>
#include <fstream>

CAC::CAC()
{
}


CAC::~CAC()
{
}


void CAC::login()
{
	ifstream fin;
	ofstream fout;
	cout << "輸入AC:";
	cin >> AC;
	cout << endl;
	cout << "輸入PW";
	cin >> PW;
	cout << endl;
	string temp_AC;
	string temp_PW;
	temp_AC = AC;
	temp_AC += ".txt";
	fin.open(temp_AC);
	fin >> temp_PW;
	if (!fin || temp_PW=="0") {
		fout.open(temp_AC);
		fout << PW;
		cout << "已新增帳號";
	}
	else if (fin || temp_PW!="0") {
		fin >> temp_PW;
		if (PW == temp_PW) {
			cout << "已登入";

		}
		else { cout << "密碼錯誤";
		system("pause");
		system("cls");
		login(); }
	}
	fin.close();
	fout.close();
}