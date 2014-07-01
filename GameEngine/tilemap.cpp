#include <fstream>
#include <iostream>
#include <string>
#include "tilemap.h"

using namespace std;

Tile::Tile()
{
	isPassable = true;
	symbol = ' ';
}

void Map::Draw() const
{
	string tens;
	string ones;
	for (int i = 0; i < COL; i++)
	{
		if (i % 10 == 0)
		{
			tens += to_string(i / 10);
		}
		else
		{
			tens += " ";
		}
		ones += to_string(i % 10);
	}
	cout << tens << endl << ones << endl << endl;

	Tile * temp = &tile[0];
	string map = "";
	for (int y = 0; y < ROW; y++)
	{
		for (int x = 0; x < COL; x++)
		{
			map += temp->symbol;
			temp++;
		}
		map += " " + to_string(y) + "\n";
	}
	cout << map << endl;
}

int Map::GetXMax() const
{
	return COL;
}

int Map::GetYMax() const
{
	return ROW;
}

Tile Map::GetTile(int selection) const
{
	return tile[selection];
}

Tile* Map::GetStart() const
{
	return start;
}

Tile* Map::GetEnd() const
{
	return end;
}

void Map::UpdateMap(int num, char sym)
{
	tile[num].symbol = sym;
}

void Map::SetEnd(int x, int y)
{
	end = &tile[x + y * COL];
	end->symbol = 'E';
}

void Map::SetStart(int x, int y)
{
	start = &tile[x + y * COL];
	start->symbol = '@';
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
			int position = x + y * COL;
			tile[position].symbol = file.get();
			tile[position].posX = x;
			tile[position].posY = y;
			tile[position].arrPos = position;
		}
		file.ignore();
	}
	file.close();
}

Map::~Map()
{
	delete[] tile;
}
