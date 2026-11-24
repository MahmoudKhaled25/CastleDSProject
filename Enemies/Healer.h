#pragma once
#include "Enemy.h"

class Healer : public Enemy
{
public:
    Healer(int id, color r_c, REGION r_region, int d = MaxDistance);
    Healer(int id, REGION region, int distance,
        double health, double power,
        int reloadPeriod, double arrivalTime);

    void Move() override;
};
