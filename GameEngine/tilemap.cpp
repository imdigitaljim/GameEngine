#include <fstream>
#include <iostream>
#include "tilemap.h"

using namespace std;

Tile::Tile()
{
	isPassable = true;
	isStartLocation = false;
	isEndLocation = false;
}
void Map::DrawMap(Map tilemap) const
{
	for (int j = 0; j < ROW; j++)
	{
		for (int i = 0; i < COL; i++)
		{

			if (tile[i + j * COL].isEndLocation)
			{
				cout << "E";
			}
			else if (tile[i + j * COL].isStartLocation)
			{
				cout << "@";
			}
			else if (tile[i + j * COL].isPassable)
			{
				cout << "-";
			}
			else if (!tile[i + j * COL].isPassable)
			{
				cout << "X";
			}
		}
		cout << endl;
	}
}


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

	// creating an [x * y] setup allocation
	// accessible by [x + y * w(max x)]
	tile = new Tile[COL * ROW]; // allocation of memory for column/ROW
	for (int y = 0; y < ROW; y++)
	{
		for (int x = 0; x < COL; x++)
		{
			if (file.get() == 'X')
			{
				tile[x + y * COL].isPassable = false;
			}
		}
		file.ignore();
	}
	file.close();
}

Map::~Map()
{
	cout << "~Map() has been called" << endl;
	delete[] tile;
}
