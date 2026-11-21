#include "Castle.h"

#include "..\GUI\GUI.h"

Castle::Castle()
{
}

void Castle::SetTowerHealth(REGION TowerRegion, double h)
{
    int index = static_cast<int>(TowerRegion);

    if (index >= 0 && index < NoOfRegions)
        Towers[index].SetHealth(h);
}
void Castle::SetTowerPower(REGION TowerRegion, double p)
{
    int index = static_cast<int>(TowerRegion);

    if (index >= 0 && index < NoOfRegions)
        Towers[index].SetPower(p);
}

void Castle::SetTowerMaxEnemies(REGION TowerRegion, int n)
{
    Towers[TowerRegion].SetMaxEnemies(n);
}

// Get tower data

double Castle::GetTowerHealth(REGION TowerRegion) const
{
    return Towers[TowerRegion].GetHealth();
}

double Castle::GetTowerPower(REGION TowerRegion) const
{
    return Towers[TowerRegion].GetPower();
}

int Castle::GetTowerMaxEnemies(REGION TowerRegion) const
{
    return Towers[TowerRegion].GetMaxEnemies();
}

// Tower freezing

void Castle::SetTowerAccumulatedIce(REGION TowerRegion, double ice)
{
    Towers[TowerRegion].SetAccumulatedIce(ice);
}

double Castle::GetTowerAccumulatedIce(REGION TowerRegion) const
{
    return Towers[TowerRegion].GetAccumulatedIce();
}

void Castle::SetTowerFrozen(REGION TowerRegion, bool frozen)
{
    Towers[TowerRegion].SetFrozen(frozen);
}

bool Castle::GetTowerIsFrozen(REGION TowerRegion) const
{
    return Towers[TowerRegion].GetIsFrozen();
}

// Initialize all towers

void Castle::SetAllTowersData(double health, int n, double power)
{
    for (int i = 0; i < NoOfRegions; i++)
    {
        Towers[i].SetHealth(health);
        Towers[i].SetMaxEnemies(n);
        Towers[i].SetPower(power);
    }
}