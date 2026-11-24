
#include "Freezer.h"

Freezer::Freezer(int id, color r_c, REGION r_region, int d)
    : Enemy(id, r_c, r_region, d) {}
Freezer::Freezer(int id, REGION region, int distance,
    double health, double power, int reloadPeriod,
    double arrivalTime)
    : Enemy(id, FREEZER_CLR, region, distance,
        health, power, reloadPeriod, 0,
        arrivalTime, INACTIVE)
{
}

void Freezer::Move()
{
    MoveAccordingToHealth();
}
