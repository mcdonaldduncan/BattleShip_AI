#include "GameLogic.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int gridSize = 16;
	int shipCount = 10;
	int steps;

    vector<vector<int>> grid = CreateGrid(gridSize);
	AddShips(&grid, shipCount);

	PrintGrid(&grid);

	steps = FindShips(&grid);

	cout << "Finished in " << steps << " steps!" << endl;

	PrintGrid(&grid);

	std::getchar();
}
