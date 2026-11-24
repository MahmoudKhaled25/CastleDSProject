
#include "Healer.h"
Healer::Healer(int id, color r_c, REGION r_region, int d)
    : Enemy(id, r_c, r_region, d) {}
Healer::Healer(int id, REGION region, int distance,
    double health, double power,
    int reloadPeriod, double arrivalTime)
    : Enemy(id, HEALER_CLR, region, distance,
        health, power, reloadPeriod, 0,
        arrivalTime, INACTIVE)
{
}

void Healer::Move()
{
    MoveAccordingToHealth();
}
