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

void Map::draw() const
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
	string map = "";
	for (int y = 0; y < ROW; y++)
	{
		for (int x = 0; x < COL; x++)
		{
			map += tile[x + y * COL].symbol;
		}
		map += " " + to_string(y) + "\n";
	}
	cout << map << endl;
}

int Map::getXMax() const
{
	return COL;
}

int Map::getYMax() const
{
	return ROW;
}

Tile Map::getTile(int selection) const
{
	return tile[selection];
}

Tile Map::getTile(int x, int y) const
{
	return tile[x + y * COL];
}

vector<Tile> Map::getMap() const
{
	return tile;
}

Tile* Map::getStart() const
{
	return start;
}

Tile* Map::getEnd() const
{
	return end;
}

void Map::updateMap(int num, char sym)
{
	tile[num].symbol = sym;
}

void Map::setEnd(int x, int y)
{
	end = &tile[x + y * COL];
	end->symbol = 'E';
}

void Map::setStart(int x, int y)
{
	start = &tile[x + y * COL];
	start->symbol = 'S';
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

	int range = ROW * COL;
	for (int i = 0; i < range; i++)
	{
		if (i % COL == 0 && i != 0)
		{
			file.ignore();
		}
		Tile temp;
		temp.symbol = file.get();
		if (temp.symbol == '#')
		{
			temp.isPassable = false;
			temp.symbol = 178;
		}
		temp.posX = i % COL;
		temp.posY = i / COL;
		temp.arrayPos = temp.posX + temp.posY * COL;
		tile.push_back(temp);
	}
	file.close();
}


bool Map::isGood(int x, int y) const
{
	if (x < 0 || y < 0 || x >= getXMax() || y >= getYMax()){
		return false;
	}

	if (!getTile(x, y).isPassable){
		return false;
	}
	return true;
}