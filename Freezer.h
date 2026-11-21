
#pragma once

#include "Enemies/Enemy.h"

class Freezer : public Enemy
{
public:
    Freezer(int id, REGION region, int distance,
        double health, double power,
        int reloadPeriod, int freezeRemaining,
        double arrivalTime, EnemyState state);

    void Move() override;
};
