#include <fstream>
#include <iostream>
#include "tilemap.h"

using namespace std;

Tile::Tile()
{
	isPassable = true;
	symbol = '-';
}
void Map::Draw() const
{
	for (int y = 0; y < ROW; y++)
	{
		for (int x = 0; x < COL; x++)
		{
			cout << tile[x + y * COL].symbol;
		}
		cout << endl;
	}
}

void Map::SetEnd(int x, int y)
{
	EndLocation = x + y * COL;
	tile[EndLocation].symbol = 'E';
}

void Map::SetStart(int x, int y)
{
	StartLocation = x + y * COL;
	tile[StartLocation].symbol = '@';
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
			tile[x + y * COL].symbol = file.get();
		}
		file.ignore();
	}
	file.close();
}

Map::~Map()
{
	delete[] tile;
}
