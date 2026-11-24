
#include "Fighter.h"

Fighter::Fighter(int id, REGION region, int distance, double health,
    double power, int reloadPeriod, double arrivalTime)
    : Enemy(id, FIGHTER_CLR, region, distance, health, power,
        reloadPeriod, 0, arrivalTime, INACTIVE)
{
}

void Fighter::Move()
{
    MoveAccordingToHealth();
}
