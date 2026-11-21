#pragma once
#include "Enemies/Enemy.h"

class Fighter : public Enemy
{
public:
    Fighter(int id, REGION region, int distance, double health,
        double power, int reloadPeriod, double arrivalTime);

    void Move() override;
};