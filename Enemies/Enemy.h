#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

//Enemies colors for next phases
//You can choose whatever colors you like for your enemies
const color FIGHTER_CLR = DARKBLUE;
const color FREEZER_CLR = CYAN;
const color HEALER_CLR = ORANGERED;


// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases

//Enemy State
enum EnemyState {
	ACTIVE , 
	INACTIVE , 
	KILLED , 
	FROZEN
};
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	double OriginalHealth;
	double Power;	//Enemy power
	
	int ReloadPeriod;  // Relod time
	int ReloadRemaining; 
	int FreezeRemaining;
	double ArrivalTime;
	EnemyState State;	//The state of the enemy (active, killed, frozed, inactive)
	double FirstShotTime; // يحسب اول مره enemy اتضرب فيها لحساب ال kill delay 
	int MoveCounter;
	double KillTime; // يحسب وقت موت ال enemy  لحساب ال kill delay

public:
	Enemy( color r_c, REGION r_region, int d = MaxDistance);
	Enemy(int id, color r_c, REGION r_region, int d, double health, double power, int reloadPeriod, int freezeRemaining
		, double arrivalTime, EnemyState state ,double killTime);
	virtual ~Enemy();

	int GetID() const;
	void SetID(int id);

	color GetColor() const;

	void SetRegion(REGION region);
	REGION GetRegion() const;


	void SetHealth(double health);
	double GetHealth() const;

	void SetOriginalHealth(double health);
	double GetOriginalHealth() const;

	void SetPower(double power);
	double GetPower() const;

	void SetReloadPeriod(int reloadPeriod);
	int GetReloadPeriod() const;

	void SetEnemyState(EnemyState state);
	EnemyState GetEnemyState() const;

	void SetArrivalTime(double arrivalTime);
	double GetArrivalTime() const;

	void SetFreezeRemaining(int freezeRemaining);
	int GetFreezeRemaining() const;

	void SetReloadRemaining(int reloadRemaining);
	int GetReloadRemaining() const;

	void SetDistance(int d);
	int GetDistance() const;

	void SetFirstShotTime(double time);
	double GetFirstShotTime() const;

	// Virtual Functions: ----------------

	void DecrementDist();
	virtual void Move() = 0;	//All enemies can move
	//virtual void Act() = 0;	//Acting means fighting or healing

	void SetKillTime(double time);
	double GetKillTime() const;
	void MoveAccordingToHealth();
};

