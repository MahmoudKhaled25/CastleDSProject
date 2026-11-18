#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"

class Castle
{
private:

    Tower Towers[NoOfRegions];

public:

    Castle();

    // Set tower data
    void SetTowerHealth(REGION TowerRegion, double h);
    void SetTowerPower(REGION TowerRegion, double p);
    void SetTowerMaxEnemies(REGION TowerRegion, int n);

    // Get tower data
    double GetTowerHealth(REGION TowerRegion) const;
    double GetTowerPower(REGION TowerRegion) const;
    int GetTowerMaxEnemies(REGION TowerRegion) const;

    // Tower freezing
    void SetTowerAccumulatedIce(REGION TowerRegion, double ice);
    double GetTowerAccumulatedIce(REGION TowerRegion) const;

    void SetTowerFrozen(REGION TowerRegion, bool frozen);
    bool GetTowerIsFrozen(REGION TowerRegion) const;

    // Initialize all towers  TH , N , TP
    void SetAllTowersData(double health, int n, double power);
};