#pragma once
#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include <vector>
using namespace std;
class monster
{
public:
	monster();
	~monster();
	int ID;
	string m_name;
	int m_MAX_HP, m_HP;
	int m_MAX_ATK, m_ATK;
	int GIVE_EXP;
	void load_monster_data(vector<monster *>*vect);
	void generate_moster(vector<monster *>*vect);
};
#endif //



