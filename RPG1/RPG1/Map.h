#pragma once
#ifndef MAP_H
#define MAP_H
#include <string>
#include "character.h"
#include "monster.h"
static class Map : public character,public monster
{
public:
	Map();
	~Map();
	int current_Map[5][5] = { {0,3,2,3,4},
							  {1,2,3,4,0},
							  {2,3,4,0,1},
							  {3,2,0,1,2},
							  {4,0,1,2,3} };
	int cur_H;
	int cur_V;
	int cur_city;
	std::string map_name(int i, int j);
	void show_map();
	void move();
};


#endif

