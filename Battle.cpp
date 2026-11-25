#include "Battle.h"

#include <iostream>



Battle::Battle()
{
	EnemyCount = 0;
}

void Battle::AddEnemy(Enemy* Ptr)
{
	if (EnemyCount < MaxEnemyCount)
		BEnemiesForDraw[EnemyCount++] = Ptr;

	// Note that this function doesn't allocate any enemy objects
	// It only makes the first free pointer in the array
	// points to the same enemy pointed to by "Ptr"
}
int* Battle::GetRandomIDs(LinkedList<Enemy>* list, int& selectedCount)
{
	mt19937 gen(
		chrono::high_resolution_clock::now().time_since_epoch().count()
	);
	selectedCount = 0;

	if (list == nullptr)
		return nullptr;

	int size = list->GetCount();

	uniform_int_distribution<int> countDist(1, 4);

	selectedCount = countDist(gen);

	int* ids = list->GetAllIds();

	shuffle(ids, ids + size, gen);

	int* killedArr = new int[selectedCount];

	for (int i = 0; i < selectedCount; i++)
	{
		killedArr[i] = ids[i];
	}

	delete[] ids;

	return killedArr;
}

bool Battle::LoadEnemiesFromFile(const std::string& fileName)
{
	TowerData tower;
	EnemyData enemies[MaxEnemyCount];
	int count = 0;

	// Step 1: Read data from file
	if (!ReadInputFile(fileName, tower, enemies, count))
		return false;

	// Step 2: Initialize Castle
	BCastle.SetAllTowersData(
		tower.health,
		tower.maxAttack,
		tower.power
	);

	// Step 3: Create Enemy objects and enqueue them
	for (int i = 0; i < count; i++)
	{
		Enemy* enemy = CreateEnemy(enemies[i]);

		if (enemy == nullptr)
			return false;

		InactiveEnemies.Enqueue(enemy);
	}

	return true;
}

void Battle::MoveArrivedEnemies(int currentTime)
{
	Enemy* enemy = nullptr;

	while (InactiveEnemies.Peek(enemy))
	{
		if (enemy->GetArrivalTime() > currentTime)
			break;

		InactiveEnemies.Dequeue(enemy);

		enemy->SetEnemyState(ACTIVE);

		ActiveEnemies.Insert(enemy);
	}
}

void Battle::UpdateEnemiesForDraw()
{
	EnemyCount = ActiveEnemies.GetCount();

	for (int i = 0; i < EnemyCount; i++)
	{
		if (!ActiveEnemies.GetAt(i, BEnemiesForDraw[i]))
		{
			EnemyCount = i;
			break;
		}
	}
}

Castle* Battle::GetCastle()
{
	return &BCastle;
}






void Battle::RunSimulation()
{
	GUI* pGUI = new GUI;

	// Step 1: Load enemies from input file
	if (!LoadEnemiesFromFile("TestFiles/TestFile1.txt"))
	{
		pGUI->PrintMessage("Error loading input file!");
		delete pGUI;
		return;
	}

	int currentTime = 0;
	Point p;

	// Step 2: Process arrival of enemies
	while (!InactiveEnemies.IsEmpty())
	{
		MoveArrivedEnemies(currentTime);

		// Step 3: Prepare enemies for GUI
		UpdateEnemiesForDraw();

		// Step 4: Draw current battle state
		pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

		pGUI->PrintMessage(
			"Time Step: " + std::to_string(currentTime)
		);

		pGUI->GetPointClicked(p);

		currentTime++;
	}

	delete pGUI;
}



Enemy* Battle::CreateEnemy(const EnemyData& data)
{
	switch (data.type)
	{
	case 1:
		return new Fighter(data.id, data.region,
			MaxDistance, data.health, data.power,
			data.reload, data.arrival);

	case 2:
		return new Healer(data.id, data.region,
			MaxDistance, data.health, data.power,
			data.reload, data.arrival);

	case 3:
		return new Freezer(data.id, data.region,
			MaxDistance, data.health, data.power,
			data.reload, data.arrival);

	default:
		return nullptr;
	}
}