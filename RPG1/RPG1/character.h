#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "CAC.h"
#include <vector>
class character : public CAC
{
public:
	character(int initHP = 0, int initSP = 0, int initATK = 0, int initEXP = 0, string initname = " ");
	virtual ~character();
	void character_selection();
	void new_character();	
	string race_name();
	string name;
	int race;
	int MAX_HP, HP;
	int MAX_ATK, ATK;
	int MAX_SP, SP;
	int MAX_EXP, EXP;
	int level;
	vector<character *> *vect;
};

#endif