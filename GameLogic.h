#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> CreateGrid(int gridSize);

void AddShips(vector<vector<int>>* grid, int shipCount);

int MissType(vector<vector<int>> grid, int x, int y);

vector<int> SearchAround(vector<vector<int>>* grid, int x, int y, int currentFound, int startX, int startY);

int FindShips(vector<vector<int>>* grid);

void PrintGrid(vector<vector<int>>* grid);


