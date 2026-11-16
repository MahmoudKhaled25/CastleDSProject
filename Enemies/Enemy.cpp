#include "Enemy.h"


Enemy::Enemy(int _id, color r_c, REGION r_region, int d)
{
	ID = _id;
	Clr = r_c;
	Region = r_region;
	SetDistance(d);
}

Enemy::~Enemy()
{
}

color Enemy::GetColor() const
{
	return Clr;
}

REGION Enemy::GetRegion() const
{
	return Region;
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

void Enemy::SetID(int _id)
{
	if (_id >= 0)
		return;
	else
		ID = _id;
}

int Enemy::GetID() const
{
	return ID;
}
