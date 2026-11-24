#include "FileReading.h"
#include <fstream>

bool CharToRegion(char c, REGION& region)
{
	switch (c)
	{
	case 'A':
	case 'a':
		region = A_REG;
		return true;
	case 'B': 
	case 'b': 
		region = B_REG; 
		return true;
	case 'C': 
	case 'c': 
		region = C_REG; 
		return true;
	case 'D': 
	case 'd': 
		region = D_REG; 
		return true;
	default: 
		return false;
	}
}

bool ReadInputFile(const std::string& fileName, TowerData& tower,
	EnemyData enemies[], int& count)
{
	count = 0;
	std::ifstream in(fileName);
	if (!in.is_open())
		return false;

	// First line: TH N TP
	if (!(in >> tower.health >> tower.maxAttack >> tower.power))
		return false;

	// Then one line per enemy, until -1
	int id;
	while (in >> id && id != -1)
	{
		if (count >= MaxEnemyCount)
			return false;

		EnemyData e;
		char regChar;
		e.id = id;
		if (!(in >> e.type >> e.arrival >> e.health >> e.power >> e.reload >> regChar))
			return false;
		if (!CharToRegion(regChar, e.region))
			return false;

		enemies[count++] = e;
	}
	return true;
}