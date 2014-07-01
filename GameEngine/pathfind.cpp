#include "pathfind.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;


void Path::setDirection()
{
	int dx = map.getEnd()->posX - map.getStart()->posX;
	int dy = map.getEnd()->posY - map.getStart()->posY;
	//Euclidian Distance sqrt(x^2 + y^2) if needed
	int dRemain = static_cast<int>(sqrt(dx*dx + dy*dy));

}


void Path::loadMap(const Map& m)
{
	map = m;
	vector<int> yVector(map.getYMax(), 999);
	mapGrid.resize(map.getXMax(), yVector);
	setDistance();
}

bool Path::isGood(int x, int y) const
{
	if (x < 0 || y < 0 || x >= map.getXMax() || y >= map.getYMax()){
		return false;
	}

	if (!map.getTile(x, y).isPassable){
		return false;
	}
	return true;
}

void Path::search(int x, int y, int level) //recursive search
{
	if (mapGrid[x][y] > level)
	{
		mapGrid[x][y] = level;
	}
	else
	{
		return;
	}
	level++;
	if (isGood(x + 1, y))
		search(x + 1, y, level);
	if (isGood(x - 1, y))
		search(x - 1, y, level);
	if (isGood(x, y + 1))
		search(x, y + 1, level);
	if (isGood(x, y - 1))
		search(x, y - 1, level);
}



void Path::draw()
{
	int x = map.getEnd()->posX;
	int y = map.getEnd()->posY;
	int level = distance - 1;
	if (level >= 900)
	{
		cout << "Path not found" << endl;
	}
	else
	{
		while (level > 0)
		{
			pathSearch(x, y, level);
		}
		map.draw();
	}
}

void Path::drawGrid() const
{
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 15; j++){
			if (mapGrid[j][i] >= 300)
				cout << setw(3) << left << "##";
			else
				cout << setw(3) << left << mapGrid[j][i];
		}
		cout << endl;
	}
}


void Path::pathSearch(int& x, int& y, int& level)
{
	if (mapGrid[x - 1][y] == level)
	{
		x -= 1;
	}
	else if (mapGrid[x + 1][y] == level)
	{
		x += 1;
	}
	else if (mapGrid[x][y - 1] == level)
	{
		y -= 1;
	}
	else if (mapGrid[x][y + 1] == level)
	{
		y += 1;
	}
	level--;
	map.updateMap(x + y * map.getXMax(), 249);
}

void Path::setDistance()
{
	search(map.getStart()->posX, map.getStart()->posY, 0);
	distance = mapGrid[map.getEnd()->posX][map.getEnd()->posY];
}

int Path::getDistance() const
{
	return distance;
}