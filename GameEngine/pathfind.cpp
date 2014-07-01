#include "pathfind.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;


void Path::setRemain()
{
	int dRemain;
	int xRemain = map.getEnd()->posX - map.getStart()->posX;
	int yRemain = map.getEnd()->posY - map.getStart()->posY;
	//Euclidian Distance sqrt(x^2 + y^2)
	dRemain = static_cast<int>(sqrt(xRemain*xRemain + yRemain*yRemain));
	distance = dRemain;

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

void Path::search(int x, int y, int count) //recursive search
{
	if (mapGrid[x][y] > count)
	{
		mapGrid[x][y] = count;
	}
	else
	{
		return;
	}
	count++;
	if (isGood(x + 1, y))
		search(x + 1, y, count);
	if (isGood(x - 1, y))
		search(x - 1, y, count);
	if (isGood(x, y + 1))
		search(x, y + 1, count);
	if (isGood(x, y - 1))
		search(x, y - 1, count);
}



void Path::draw()
{
	int x = map.getEnd()->posX;
	int y = map.getEnd()->posY;
	int count = distance;
	while (count > 0)
	{
		pathSearch(x, y, count);
	}
	map.draw();
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


void Path::pathSearch(int& x, int& y, int& count)
{
	if (mapGrid[x - 1][y] == count)
	{
		x -= 1;
	}
	else if (mapGrid[x + 1][y] == count)
	{
		x += 1;
	}
	else if (mapGrid[x][y - 1] == count)
	{
		y -= 1;
	}
	else if (mapGrid[x][y + 1] == count)
	{
		y += 1;
	}
	count--;
	map.updateMap(x + y * map.getXMax(), 'p');
	cout << "Count Update: " << count << endl;
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