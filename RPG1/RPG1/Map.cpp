#include "pch.h"
#include "Map.h"
#include "character.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

vector<monster *>*vect1;
Map::Map()
{
	
	cur_H = 0;
	cur_V = 0;
	cur_city = current_Map[cur_H][cur_V];
}


Map::~Map()
{
}

string Map::map_name(int i, int j) {
	int temp = current_Map[i][j];
	switch (temp) {
	case 0: {return "商店"; break; }
	case 1: {return "遺跡"; break; }
	case 2: {return "地城"; break; }
	case 3: {return "廢墟"; break; }
	case 4: {return "草原"; break; }
	default:return"error";
	}
}

//current_Map[cur_V][cur_H + 1]
//map_name(cur_H,cur_V +1)

void Map::show_map()
{
	//cout << "0=商店 , 1=遺跡 , 2 =地城 , 3=廢墟 , 4=草原" << endl;
	if (cur_V == 0 && cur_H == 0) {
		cout <<
			"YOU" << "===" << map_name(cur_V, cur_H + 1) << endl <<
			"||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << endl <<
			map_name(cur_V + 1,cur_H) << "==" << map_name(cur_V + 1,cur_H + 1) << endl;
	}
	else if (cur_H == 0 && cur_V == 4) {
		cout <<
			map_name(cur_V - 1,cur_H) << "====" << map_name(cur_V - 1,cur_H + 1) << endl <<
			"||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << endl <<
			"YOU" << "===" << map_name(cur_V,cur_H + 1);
	}
	else if (cur_H == 4 && cur_V == 0) {
		cout <<
			map_name(cur_V,cur_H - 1) << "===" << "YOU" << endl <<
			"||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << endl <<
			map_name(cur_V + 1,cur_H - 1) << "====" << map_name(cur_V + 1,cur_H) << endl;
	}
	else if (cur_H == 4 && cur_V == 4) {
		cout <<
			map_name(cur_V - 1,cur_H - 1) << "====" << map_name(cur_V - 1,cur_H) << endl <<
			"||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << endl <<
			map_name(cur_V,cur_H - 1) << "===" << "YOU" << endl;
	}
	else if (cur_V == 0) {
		cout <<
			map_name(cur_V,cur_H - 1) << "====" << "YOU" << "===" << map_name(cur_V,cur_H + 1) << endl <<
			"||" << setw(7) << "||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << setw(7) << "||" << endl <<
			map_name(cur_V + 1,cur_H - 1) << "====" << map_name(cur_V,cur_H + 1) << "====" << map_name(cur_H + 1,cur_V + 1);
	}
	else if (cur_V == 4) {
		cout <<
			map_name(cur_V - 1,cur_H - 1) << "====" << map_name(cur_V - 1,cur_H) << "====" << map_name(cur_V - 1,cur_H + 1) << endl <<
			"||" << setw(7) << "||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << setw(7) << "||" << endl <<
			map_name(cur_V,cur_H - 1) << "====" << "YOU" << "===" << map_name(cur_V,cur_H + 1) << endl;
	}
	else if (cur_H == 0) {
		cout <<
			map_name(cur_V - 1,cur_H) << "====" << map_name(cur_V - 1,cur_H + 1) << endl <<
			"||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << endl <<
			"YOU" << "==" << map_name(cur_V,cur_H + 1) << endl <<
			"||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << endl <<
			map_name(cur_V + 1,cur_H) << "====" << map_name(cur_V + 1,cur_H + 1) << endl;
	}
	else if (cur_H == 4) {
		cout <<
			map_name(cur_V - 1,cur_H - 1) << "====" << map_name(cur_V - 1,cur_H) << endl <<
			"||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << endl <<
			 map_name(cur_V,cur_H - 1)<<"==" << "YOU" << endl <<
			"||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << endl <<
			map_name(cur_V + 1,cur_H - 1) << "====" << map_name(cur_V + 1,cur_H) << endl;
	}else {
		cout <<
			map_name(cur_V - 1,cur_H - 1) << "====" << map_name(cur_V - 1,cur_H) << "====" << map_name(cur_V - 1,cur_H + 1) << endl <<
			"||" << setw(7) << "||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << setw(7) << "||" << endl <<
			map_name(cur_V,cur_H - 1) << "===" << "YOU" << "====" << map_name(cur_V,cur_H +1) << endl <<
			"||" << setw(7) << "||" << setw(7) << "||" << endl <<
			"||" << setw(7) << "||" << setw(7) << "||" << endl <<
			map_name(cur_V + 1,cur_H - 1) << "====" << map_name(cur_V + 1,cur_H) <<"====" << map_name(cur_V + 1,cur_H + 1) << endl;
	}
}

void Map::move()
{
	character c;
	int movement = 5;
	cout << "請輸入移動方向 8.上 2.下 4.左 6.右 0.登出" << endl;
	show_map();
	cout << "移動方向 :";
	while (movement != 0) {
		cin >> movement;
		switch (movement)
		{
		case 8: { //up
			if(cur_V >0)cur_V--;
			else cout << "不能再往上方移動了" << endl;
			system("cls");
			move();
		}
		case 2: { //down
			if (cur_V < 4)cur_V++;
			else cout << "不能再往下方移動了" << endl;
			system("cls");
			move();
		}
		case 4: { //left
			if (cur_H > 0)cur_H--;
			else cout << "不能再往左方移動了" << endl;
			system("cls");
			move();
		}
		case 6: { //right
			if (cur_H < 4)cur_H++;
			else cout << "不能再往右方移動了" << endl;
			system("cls");
			move();
		}
		case 5: { //character information
			system("cls");
			show_map();
			cout << name << endl << race_name() << endl << HP << "/" << MAX_HP << endl << SP << "/" << MAX_SP << endl << EXP << "/" << MAX_EXP << endl << "level :" << level << endl;
			system("pause");
			system("cls");
			move();
			break;
		}
		case 7: {
			system("cls");
			show_map();
			load_monster_data(vect1);
			generate_moster(vect1);
			system("pause");
		}
		default: {
			cout << "錯誤指令，請重新輸入" << endl;
			system("pause");
			system("cls");
			move();
			break; }
		}
	}
}
