#pragma once
#include <random>
#include <algorithm>
#include <chrono>

#include "Enemies\Enemy.h"
#include "Enemies\fighter.h"
#include "Enemies\freezer.h"
#include "Enemies\healer.h"
#include "Castle\Castle.h"

#include "DSs\LinkedList.h"
#include "DSs\Queue.h"
#include "FileReading.h"


// it is the controller of the project
class Battle
{
private:
	Castle BCastle;
	int EnemyCount;	//the actual number of enemies in the game
	Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function


	Queue<Enemy> InactiveEnemies;
	LinkedList<Enemy> ActiveEnemies;

	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Battle();
	void AddEnemy(Enemy* Ptr);
	Castle * GetCastle();
	void RunSimulation();

	int* GetRandomIDs(LinkedList<Enemy>* list, int& selectedCount);


	Enemy* CreateEnemy(const EnemyData& data);			// to create a specific enemy due to its type chosen in the file

	bool LoadEnemiesFromFile(const std::string& fileName);  // to convert the data in file into real enemies and gives real values for towers

	void MoveArrivedEnemies(int currentTime); // to move inactive enemies to active state when their time is coming

	void UpdateEnemiesForDraw(); 

	

	//
	// TODO: Add More Member Functions As Needed
	//
};

