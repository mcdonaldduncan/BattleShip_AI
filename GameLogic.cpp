#include "GameLogic.h"

vector<vector<int>> CreateGrid(int gridSize)
{
	vector<vector<int>> tempGrid;
	for (int i = 0; i < gridSize; i++)
	{
		vector<int> tempPoint;
		for (int j = 0; j < gridSize; j++)
		{
			tempPoint.push_back(0);
		}
		tempGrid.push_back(tempPoint);
	}

	return tempGrid;
}

void AddShips(vector<vector<int>>* grid, int shipCount)
{
	int iterations = shipCount;
	int i = 0;
	srand(time(NULL));
	while (i < iterations)
	{
		int x = rand() % grid->size();
		int y = rand() % grid->size();
		if (grid->at(x)[y] == 0)
		{
			grid->at(x)[y] = 1;
		}
		else
		{
			iterations++;
		}
		i++;
	}
}

int MissType(vector<vector<int>> grid, int x, int y)
{
	string temp = "Miss!";
	int val = 0;
	for (int i = -1; i <= 1; i++)
	{
		int tempX = x + i;
		if (tempX >= grid.size() || tempX < 0) continue;

		for (int j = -1; j <= 1; j++)
		{
			int tempY = y + j;
			if (tempY >= grid.size() || tempY < 0) continue;

			if (grid[tempX][tempY] == 1)
			{
				temp = "Near Miss!";
				val = 1;
			}
		}
	}
	cout << temp << endl;
	return val;
}

vector<int> SearchAround(vector<vector<int>>* grid, int x, int y, int currentFound)
{
	vector<int> outValues;
	int steps = 0;
	int found = currentFound;
	for (int i = -1; i <= 1; i++)
	{
		int tempX = x + i;
		if (tempX >= grid->size() || tempX < 0) continue;

		for (int j = -1; j <= 1; j++)
		{
			int tempY = y + j;
			if (tempY >= grid->size() || tempY < 0) continue;
			steps++;

			if (grid->at(tempX)[tempY] == 1)
			{
				cout << "Hit ship at: " << tempX << "," << tempY << endl;
				grid->at(tempX)[tempY] = 0;
				found++;

				outValues.push_back(steps);
				outValues.push_back(found);

				return outValues;
			}
			else
			{
				int temp = MissType(*grid, tempX, tempY);
			}
		}
	}
	outValues.push_back(steps);
	outValues.push_back(found);

	return outValues;
}

int FindShips(vector<vector<int>>* grid)
{
	int found = 0;
	int steps = 0;
	int x = 1;
	int y = 1;

	while (x < grid->size())
	{
		while (y < grid->at(x).size())
		{
			if (grid->at(x)[y] == 1)
			{
				cout << "Hit ship at: " << x << "," << y << endl;
				grid->at(x)[y] = 0;
				found++;
				if (found >= 10) return steps;
			}
			while (MissType(*grid, x, y) == 1)
			{
				vector<int> tempV = SearchAround(grid, x, y, found);
				steps += tempV[0];
				found = tempV[1];
				if (found >= 10) return steps;
			}
			steps++;

			y += 3;

			if (y >= grid->at(x).size())
			{
				y--;
			}
		}

		x += 3;

		if (x >= grid->size())
		{
			x--;
		}

		y = 1;
	}

	return steps;
}

void PrintGrid(vector<vector<int>>* grid)
{
	for (int i = 0; i < grid->size(); i++)
	{
		for (int j = 0; j < grid->at(i).size(); j++)
		{
			cout << grid->at(i)[j];
		}
		cout << endl;
	}
}
