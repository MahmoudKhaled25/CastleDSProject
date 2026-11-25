#pragma once
#include "Enemy.h"

class Fighter : public Enemy
{
public:
    Fighter(int id, color r_c, REGION r_region, int d = MaxDistance);
    Fighter(int id, REGION region, int distance,
        double health, double power,
        int reloadPeriod, double arrivalTime);

    void Move() override;
};
