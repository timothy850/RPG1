#include "pch.h"
#include "monster.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

monster::monster()
{
	ID = m_MAX_HP = m_MAX_ATK = m_HP = m_ATK = GIVE_EXP = 0;
}


monster::~monster()
{
}

void monster::load_monster_data(vector<monster *>*vect)
{
	monster *temp;
	ifstream fin;
	fin.open("monster.txt");
	while( fin >> ID >> m_name >> m_MAX_HP >> m_MAX_ATK >> GIVE_EXP){
		temp = new monster;
		temp->ID = ID;
		temp->m_name = m_name;
		temp->m_MAX_HP = m_MAX_HP;
		temp->m_HP = temp->m_MAX_HP;
		temp->m_MAX_ATK = m_MAX_ATK;
		temp->GIVE_EXP = GIVE_EXP;
		vect->push_back(temp);
	}
	fin.close();
}

void monster::generate_moster(vector<monster*>* vect)
{
	int i = rand() % 10 + 1;
	if(i>=1 && i <4){
		int m_id = rand() % 6;
		for (vector<monster *>::iterator it = vect->begin(); it != vect->end(); it++) {
			if( (*it)->ID == m_id){
				cout << (*it)->m_name << " " << (*it)->m_HP << "/" << (*it)->m_MAX_HP << endl;
			}
		}
	}
	else if(i>=4 && i<7){
		int number;
		for (number = 0; number < 2; number++) {
			int m_id = rand() % 6;
			for (vector<monster *>::iterator it = vect->begin(); it != vect->end(); it++) {
				if ((*it)->ID == m_id) {
					cout << (*it)->m_name << " " << (*it)->m_HP << "/" << (*it)->m_MAX_HP << endl;

				}
			}
		}
	}
	else if (i >= 7 && i <= 10) {
		int number;
		for (number = 0; number < 3; number++) {
			int m_id = rand() % 6;
			for (vector<monster *>::iterator it = vect->begin(); it != vect->end(); it++) {
				if ((*it)->ID == m_id) {
					cout << (*it)->m_name << " " << (*it)->m_HP << "/" << (*it)->m_MAX_HP << endl;
				}
			}
		}
	}
}

