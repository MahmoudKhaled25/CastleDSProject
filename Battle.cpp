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
int* Battle::getRandomIDs(LinkedList<Enemy>* list, int& selectedCount)
{
	mt19937 gen(
		chrono::high_resolution_clock::now().time_since_epoch().count()
	);
	selectedCount = 0;

	if (list == nullptr)
		return nullptr;

	int size = list->getCount();

	uniform_int_distribution<int> countDist(1, 4);

	selectedCount = countDist(gen);

	int* ids = list->getAllIds();

	shuffle(ids, ids + size, gen);

	int* killedArr = new int[selectedCount];

	for (int i = 0; i < selectedCount; i++)
	{
		killedArr[i] = ids[i];
	}

	delete[] ids;

	return killedArr;
}

Castle* Battle::GetCastle()
{
	return &BCastle;
}






void Battle::RunSimulation()
{
	Just_A_Demo();
}


//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
void Battle::Just_A_Demo()
{
	Fighter e1(1, DARKBLUE, A_REG, 6);
	Fighter e2(2, DARKBLUE, D_REG, 60);
	Fighter e3(3, DARKOLIVEGREEN, B_REG, 60);
	Fighter e4(4, DARKOLIVEGREEN, A_REG, 4);
	Freezer e5(5, ORANGERED, C_REG, 19);
	Freezer e6(6, ORANGERED, C_REG, 30);
	Freezer e7(6, ORANGERED, A_REG, 2);
	Freezer e8(7, DARKOLIVEGREEN, C_REG, 7);
	Healer e9(8, ORANGERED, A_REG, 30);
	Healer e10(9, DARKBLUE, C_REG, 4);
	Healer e11(10, GREEN, A_REG, 20);

	LinkedList<Enemy>l1;
	l1.Insert(&e1);
	l1.Insert(&e2);
	l1.Insert(&e3);
	l1.Insert(&e4);
	l1.Insert(&e5);
	l1.Insert(&e6);
	l1.Insert(&e7);
	l1.Insert(&e8);
	l1.Insert(&e9);
	l1.Insert(&e10);

	int selectedCount;

	int* killed = getRandomIDs(&l1, selectedCount);

	if (killed == NULL)
	{
		cout << "Not enough IDs" << endl;
		return;
	}

	cout << "Random IDs: ";

	for (int i = 0; i < selectedCount; i++)
	{
		cout << killed[i] << " ";
	}

	cout << endl;

	delete[] killed;


	std::cout << "\nWelcome to Castle Battle:\n";
	std::cout << "\nIn phase2, you will be asked to select game mode\n";
	std::cout << "\nFor now just press ENTER key to continue...";

	char tmp[10];
	std::cin.getline(tmp, 10);
	//
	// THIS IS JUST A DEMO
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	//

	GUI* pGUI = new GUI;

	pGUI->PrintMessage("This is Just a Demo. It should be changed ib phase1 & phase2. Click to move to next step");



	// Declare some enemies and fill their data
	// In the game, enemies should be loaded from an input file
	// and should be dynamically allocated




	// Adding the enemies to the battle
	AddEnemy(&e1);
	AddEnemy(&e2);
	AddEnemy(&e3);
	AddEnemy(&e4);
	AddEnemy(&e5);
	AddEnemy(&e6);
	AddEnemy(&e7);
	AddEnemy(&e8);
	AddEnemy(&e9);
	AddEnemy(&e10);
	AddEnemy(&e11);

	// Drawing the battle
	pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

	Point p;
	pGUI->GetPointClicked(p);

	// Now a demo to move enemies some time steps
	// TimeStep is a normal integer that is incremented each time by 1
	for (int TimeStep = 1; TimeStep <= 30; TimeStep++)
	{

		// Decrement the distance of each enemy. Just for the sake of demo
		e1.DecrementDist();
		e2.DecrementDist();
		e3.DecrementDist();
		e4.DecrementDist();
		e5.DecrementDist();
		e6.DecrementDist();
		e7.DecrementDist();
		e8.DecrementDist();
		e9.DecrementDist();
		e10.DecrementDist();

		// Redraw the enemies
		pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

		pGUI->GetPointClicked(p);
	}

	delete pGUI;
}