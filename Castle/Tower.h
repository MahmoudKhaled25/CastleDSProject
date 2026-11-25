#pragma once
#include "..\Defs.h"
class Tower
{
private: //encapsulation 
	double Health;
	double Power; // the power of the tower (the damage it can inflict on enemies)
	bool isFrozen; //tower is frozen or not
	int MaxEnemies; // the maximum number of enemies the tower can target
	double FreezeTime; // the time for which the tower is frozen
	double accumulatedIce; // the amount of ice accumulated on the tower
	

public:

	Tower();
	void SetHealth(double h);
	double GetHealth() const;

	void SetPower(double p);
	double GetPower() const;

	void SetMaxEnemies(int n);
	int GetMaxEnemies() const;

	void SetAccumulatedIce(double ice);
	double GetAccumulatedIce() const;

	void SetFrozen(bool frozen);
	bool GetIsFrozen() const;

	void SetFreezeTime(double time);
	double GetFreezeTime() const;
};

