#include <fstream>
#include <iostream>
#include "tilemap.h"

using namespace std;

Map::Map()
{
	// file extraction
	ifstream file;
	string tilemap = "tilemap.txt";
	file.open(tilemap);
	if (!file.good())
	{
		cout << "Error: Tile Map Missing" << endl;
	}
	file >> COL;
	file >> ROW;
	file.ignore();

	// creating an [x][y] setup allocation
	tile = new Tile*[COL]; // allocation of memory for column 

	for (int i = 0; i < COL; i++)
	{
		tile[i] = new Tile[ROW]; // allocation for each row
	}

	for (int y = 0; y < ROW; y++)
	{
		for (int x = 0; x < COL; x++)
		{
			if (file.get() == 'X')
			{
				tile[x][y].isPassable = false;
			}
			else
			{
				tile[x][y].isPassable = true;
			}
		}
		file.ignore();
	}
	file.close();

	for (int y = 0; y < ROW; y++)
	{
		for (int x = 0; x < COL; x++)
		{
			if (tile[x][y].isPassable)
			{
				cout << "-";
			}
			else if (!tile[x][y].isPassable)
			{
				cout << "X";
			}
		}
		cout << endl;
	}
}

Map::~Map()
{
	cout << "~Map() has been called" << endl;
	for (int i = 0; i < COL; i++)
	{
		delete[] tile[i];
	}
	delete[] tile;
}
