#include "Enemy.h"


Enemy::Enemy( int id,color r_c, REGION r_region, int d)
{
	ID = id;
	Clr = r_c;
	Region = r_region;
	Health = 0;
	OriginalHealth = 0;
	Power = 0;
	ArrivalTime = 0;
	ReloadPeriod = 0;
	ReloadRemaining = 0;
	FreezeRemaining = 0;
	FirstShotTime = 0;
	State = INACTIVE;
	MoveCounter = 0;
	SetDistance(d);
}
Enemy::Enemy(int id, color r_c, REGION r_region, int d, double health, double power, int reloadPeriod,
	int freezeRemaining, double arrivalTime, EnemyState state )
{
	ID = id;
	Clr = r_c;
	Region = r_region;
	Health = health;
	OriginalHealth = health;
	Power = power;
	ReloadPeriod = reloadPeriod;
	ReloadRemaining = 0;
	FreezeRemaining = freezeRemaining;
	ArrivalTime = arrivalTime;
	State = state;
	FirstShotTime = 0;
	SetDistance(d);
}

Enemy::~Enemy()
{
}
int Enemy::GetID() const
{
	return ID;
}

color Enemy::GetColor() const
{
	return Clr;
}

REGION Enemy::GetRegion() const
{
	return Region;
}
double Enemy::GetHealth() const
{
	return Health;
}
double Enemy::GetOriginalHealth() const
{
	return OriginalHealth;
}
int Enemy::GetReloadPeriod() const
{
	return ReloadPeriod;
}
int Enemy::GetReloadRemaining() const
{
	return ReloadRemaining;
}
int Enemy::GetFreezeRemaining() const
{
	return FreezeRemaining;
}
double Enemy::GetArrivalTime() const
{
	return ArrivalTime;
}
EnemyState Enemy::GetEnemyState() const
{
	return State;
}
double Enemy::GetFirstShotTime() const
{
	return FirstShotTime;
}
// Setters
void Enemy::SetEnemyState(EnemyState state)
{
	State = state;
}
void Enemy::SetID(int id)
{
	ID = id;
}

void Enemy::SetRegion(REGION region)
{
	Region = region;
}

void Enemy::SetHealth(double health)
{
	Health = health;
}

void Enemy::SetOriginalHealth(double health)
{
	OriginalHealth = health;
}

void Enemy::SetPower(double power)
{
	Power = power;
}

void Enemy::SetReloadPeriod(int reloadPeriod)
{
	ReloadPeriod = reloadPeriod;
}

void Enemy::SetArrivalTime(double arrivalTime)
{
	ArrivalTime = arrivalTime;
}

void Enemy::SetFreezeRemaining(int freezeRemaining)
{
	FreezeRemaining = freezeRemaining;
}

void Enemy::SetReloadRemaining(int reloadRemaining)
{
	ReloadRemaining = reloadRemaining;
}

void Enemy::SetFirstShotTime(double time)
{
	FirstShotTime = time;
}
void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}
void Enemy::Move()
{
	DecrementDist();
}
void Enemy::MoveAccordingToHealth()
{
	if (State != ACTIVE)
		return;

	if (Health < OriginalHealth / 2)
	{
		MoveCounter++;

		if (MoveCounter == 2)
		{
			DecrementDist();
			MoveCounter = 0;   // علشان يصفر العداد ويبدأ من جديد
		}
	}
	else
	{
		DecrementDist();
		MoveCounter = 0;
	}
}
