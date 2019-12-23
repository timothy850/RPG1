#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

#include "CAC.h"
#include "character.h"
#include "Map.h"

void main()
{
	srand(time(NULL));
	Map map;
	map.login();
	map.character_selection();
	map.move();
}
