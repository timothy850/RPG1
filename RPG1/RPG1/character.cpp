#include "pch.h"
#include "character.h"
#include "CAC.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

character::character(int initHP, int initSP, int initATK, int initEXP, string initname)
{
	MAX_HP = HP = initHP;
	MAX_SP = SP = initSP;
	MAX_ATK = ATK = initATK;
	EXP = initEXP;
	name = initname;
	MAX_EXP = 100;

}


character::~character()
{
}

void character::character_selection()
{
	int choice;
	character *temp;
	ifstream fin, fin1, fin2, fin3;
	ofstream fout, fout1, fout2, fout3;
	string temp_name, temp_name1, temp_name2,temp_name3;
	string name1, name2, name3;
	cout << "1 建立角色 2 選擇角色 3 刪除角色 4刪除帳號" << endl;
	cin >> choice;

	temp_name = AC;
	temp_name += "3";
	temp_name += ".txt";

	temp_name1 = AC;
	temp_name1 += "2";
	temp_name1 += ".txt";

	temp_name2 = AC;
	temp_name2 += "1";
	temp_name2 += ".txt";

	temp_name3 = AC;
	temp_name3 += ".txt";

	fin.open(temp_name);
	fin1.open(temp_name1);
	fin2.open(temp_name2);
	fin3.open(temp_name3);

	switch (choice)
	{
	case 1: {
		cout << "輸入角色名稱";
		cin >> name;
		fin >> name1;
		fin1 >> name2;
		fin2 >> name3;
		if (!fin2 || name3 == "0") {
			new_character();
			cout << name << endl << race << endl << MAX_HP << endl << HP << endl << MAX_SP << endl << SP << endl << MAX_ATK << endl << ATK << endl << MAX_EXP << endl << EXP << endl << level;
			fout.open(temp_name2);
			fout << name << endl << race << endl << MAX_HP << endl << HP << endl << MAX_SP << endl << SP << endl << MAX_ATK << endl << ATK << endl << MAX_EXP << endl << EXP << endl << level;
			
			fout.close();
		}
		else if (!fin1 || name2 == "0") {
			new_character();
			cout << name << endl << race << endl << MAX_HP << endl << HP << endl << MAX_SP << endl << SP << endl << MAX_ATK << endl << ATK << endl << MAX_EXP << endl << EXP << endl << level;
			fout.open(temp_name1);
			fout << name << endl << race << endl << MAX_HP << endl << HP << endl << MAX_SP << endl << SP << endl << MAX_ATK << endl << ATK << endl << MAX_EXP << endl << EXP << endl << level;
			fout.close();
		}
		else if (!fin || name1 == "0") {
			new_character();
			cout << name << endl << race << endl << MAX_HP << endl << HP << endl << MAX_SP << endl << SP << endl << MAX_ATK << endl << ATK << endl << MAX_EXP << endl << EXP << endl << level;
			fout.open(temp_name);
			fout << name << endl << race << endl << MAX_HP << endl << HP << endl << MAX_SP << endl << SP << endl << MAX_ATK << endl << ATK << endl << MAX_EXP << endl << EXP << endl << level;
			fout.close();
		}
		else cout << "角色數量已達上限";
		break;
	}
	case 2: {
		system("cls");
		while (fin2 >> name >> race >> MAX_HP >> HP >> MAX_SP >> SP >> MAX_ATK >> ATK >> MAX_EXP >> EXP >> level) {
			cout << name << endl << race_name() << endl << HP << "/" << MAX_HP << endl << SP << "/" << MAX_SP << endl << EXP << "/" << MAX_EXP << endl << "level :" << level << endl;
		}
		cout << endl;
		while (fin1 >> name >> race >> MAX_HP >> HP >> MAX_SP >> SP >> MAX_ATK >> ATK >> MAX_EXP >> EXP >> level) {
			cout << name << endl << race_name() << endl << HP << "/" << MAX_HP << endl << SP << "/" << MAX_SP << endl << EXP << "/" << MAX_EXP << endl << "level :" << level << endl;
		}
		cout << endl;
		while (fin >> name >> race >> MAX_HP >> HP >> MAX_SP >> SP >> MAX_ATK >> ATK >> MAX_EXP >> EXP >> level) {
			cout << name << endl << race_name() << endl << HP << "/" << MAX_HP << endl << SP << "/" << MAX_SP << endl << EXP << "/" << MAX_EXP << endl << "level :" << level << endl;
		}
		break;
	}
	case 3: {
		while (fin2 >> name >> race >> MAX_HP >> HP >> MAX_SP >> SP >> MAX_ATK >> ATK >> MAX_EXP >> EXP >> level) {
			if (name != "0") {
				cout << name << endl << race_name() << endl << HP << "/" << MAX_HP << endl << SP << "/" << MAX_SP << endl << EXP << "/" << MAX_EXP << endl << "level :" << level << endl;
			}
		}
		cout << endl;
		while (fin1 >> name >> race >> MAX_HP >> HP >> MAX_SP >> SP >> MAX_ATK >> ATK >> MAX_EXP >> EXP >> level) {
			if (name != "0") {
				cout << name << endl << race_name() << endl << HP << "/" << MAX_HP << endl << SP << "/" << MAX_SP << endl << EXP << "/" << MAX_EXP << endl << "level :" << level << endl;
			}
		}
		cout << endl;
		while (fin >> name >> race >> MAX_HP >> HP >> MAX_SP >> SP >> MAX_ATK >> ATK >> MAX_EXP >> EXP >> level) {
			if (name != "0") {
				cout << name << endl << race_name() << endl << HP << "/" << MAX_HP << endl << SP << "/" << MAX_SP << endl << EXP << "/" << MAX_EXP << endl << "level :" << level << endl;
			}
		}
		int choice;
		cout << "請選擇要刪除的角色" << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			fout.open(temp_name2);
			fout << "0";
			fout.close();
		}
		else if (choice == 2) {
			fout.open(temp_name1);
			fout << "0";
			fout.close();
		}
		else if (choice == 3) {
			fout.open(temp_name);
			fout << "0";
			fout.close();
		}
		else cout << "錯誤選擇，請輸入要刪除第幾位角色";
		break;
	}
	case 4:
		fout.open(temp_name);
		fout1.open(temp_name1);
		fout2.open(temp_name2);
		fout3.open(temp_name3);
		fout << "0";
		fout1 << "0";
		fout2 << "0";
		fout3 << "0";
	default:
		break;


	}
	fout.close();
	fout1.close();
	fout2.close();
	fout3.close();
	fin.close();
	fin1.close();
	fin2.close();
	fin3.close();
}

void character::new_character()
{
	int choice;
	cout << "選擇種族 1.人類 2.矮人 3.妖精 ";
	cin >> choice;
	if (choice == 1) {
		race = 1;
		MAX_HP = HP = rand() % 10 + 100;
		MAX_SP = SP = rand() % 10 + 100;
		MAX_ATK = ATK = rand() % 10 + 5;
		level = 1;
		MAX_EXP = 100;
		EXP = 0;
	}
	else if (choice == 2)
	{
		race = 2;
		MAX_HP = HP = rand() % 10 + 90;
		MAX_SP = SP = rand() % 10 + 100;
		MAX_ATK = ATK = rand() % 10 + 15;
		level = 1;
		MAX_EXP = 100;
		EXP = 0;
	}
	else if (choice == 3) {
		race = 3;
		MAX_HP = HP = rand() % 10 + 100;
		MAX_SP = SP = rand() % 10 + 120;
		MAX_ATK = ATK = rand() % 10 + 5;
		level = 1;
		MAX_EXP = 100;
		EXP = 0;
	}
	else {
		cout << "選擇錯誤";
		new_character();
	}
}



string character::race_name()
{
	if (race == 1)return "人類";
	else if (race == 2)return "矮人";
	else if (race == 3)return "妖精";
}

