#include "pathfind.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

Path::Path(const Map tilemap)
{
	destination = tilemap.GetEnd();
	current = tilemap.GetStart();
	open_map = tilemap.GetMap();
	SetRemain();
}

void Path::SetRemain()
{
	int dRemain;
	int xRemain = destination->posX - current->posX;
	int yRemain = destination->posY - current->posY;

	//Euclidian Distance sqrt(x^2 + y^2)
	//force int
	dRemain = static_cast<int>(sqrt(xRemain*xRemain + yRemain*yRemain));
	distance = dRemain;
}

// x + y * xMax
void Path::Draw()
{
	vector<Node> path;

}


int Path::GetDistance() const
{
	return distance;
}