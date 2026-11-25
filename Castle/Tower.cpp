#include "Tower.h"


Tower::Tower()
{
	SetHealth(TowerInitHealth);
	Power = 0;
	MaxEnemies = 0;
	FreezeTime = 0;
	accumulatedIce = 0;
	isFrozen = false;
}


void Tower::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

double Tower::GetHealth() const
{
	return Health;
}
void Tower::SetPower(double p) {
	if (p > 0)
		Power = p;
	else
		Power = 0;
}
double Tower::GetPower() const {
	return Power;
}
void Tower::SetMaxEnemies(int n)
{
	if (n > 0)
		MaxEnemies = n;
	else
		MaxEnemies = 0;
}

int Tower::GetMaxEnemies() const
{
	return MaxEnemies;
}

void Tower::SetAccumulatedIce(double ice)
{
	if (ice > 0)
		accumulatedIce = ice;
	else
		accumulatedIce = 0;
}

double Tower::GetAccumulatedIce() const
{
	return accumulatedIce;
}

void Tower::SetFrozen(bool frozen)
{
	isFrozen = frozen;
}

bool Tower::GetIsFrozen() const
{
	return isFrozen;
}
void Tower::SetFreezeTime(double time)
{
	if (time > 0)
		FreezeTime = time;
	else
		FreezeTime = 0;
}
double Tower::GetFreezeTime() const
{
	return FreezeTime;
}