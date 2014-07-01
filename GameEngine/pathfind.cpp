#include "pathfind.h"
#include <iostream>
#include <cmath>

using namespace std;

Path::Path(const Map map)
{
	destination = map.GetEnd();
	current = map.GetStart();
	distance = GetRemain();
	level = 0;
}

int Path::GetRemain()
{
	int dRemain;
	int xRemain = destination->posX - current->posX;
	int yRemain = destination->posY - current->posY;

	//Euclidian Distance sqrt(x^2 + y^2)
	//force int
	dRemain = static_cast<int>(sqrt(xRemain*xRemain + yRemain*yRemain));
	return dRemain;
}

// x + y * xMax
void Path::Draw()
{
}

int Path::GetDistance() const
{
	return distance;
}