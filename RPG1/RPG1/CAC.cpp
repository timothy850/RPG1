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
	cout << "��JAC:";
	cin >> AC;
	cout << endl;
	cout << "��JPW";
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
		cout << "�w�s�W�b��";
	}
	else if (fin || temp_PW!="0") {
		fin >> temp_PW;
		if (PW == temp_PW) {
			cout << "�w�n�J";

		}
		else { cout << "�K�X���~";
		system("pause");
		system("cls");
		login(); }
	}
	fin.close();
	fout.close();
}