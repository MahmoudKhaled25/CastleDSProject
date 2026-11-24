#pragma once
#include <string>
#include"Defs.h"

// Raw values of one enemy line: S TYP T H POW RLD REG
struct EnemyData
{
	int id;
	int type;        // 1 = Fighter, 2 = Healer, 3 = Freezer
	int arrival;
	double health;
	int power;
	int reload;
	REGION region;
};

// Raw values of the first line: TH N TP
struct TowerData
{
	double health;
	int maxAttack;   // N
	int power;       // TP
};

// Reads the whole input file.
// Returns false if the file cannot be opened or a line is invalid.
// enemies[] must have room for MaxEnemyCount items; count = number of enemies read.
bool ReadInputFile(const std::string& fileName, TowerData& tower,
	EnemyData enemies[], int& count);

// Converts 'A'..'D' (or 'a'..'d') to REGION. Returns false for any other letter.
bool CharToRegion(char c, REGION& region);