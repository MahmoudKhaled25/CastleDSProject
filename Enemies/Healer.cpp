
#include "Healer.h"
Healer::Healer(int id, color r_c, REGION r_region, int d)
    : Enemy(id, r_c, r_region, d) {}
Healer::Healer(int id, REGION region, int distance,
    double health, double power,
    int reloadPeriod, int freezeRemaining,
    double arrivalTime, EnemyState state)
    : Enemy(id, HEALER_CLR, region, distance,
        health, power, reloadPeriod, freezeRemaining,
        arrivalTime, state)
{
}

void Healer::Move()
{
    MoveAccordingToHealth();
}
