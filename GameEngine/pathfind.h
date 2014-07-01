#ifndef _H_PATHFIND
#define _H_PATHFIND
#include "tilemap.h"

using namespace std;

class Path
{

public:
	Path(const Map);
	int GetCurrentX() const;
	int GetCurrentY() const;
	int GetLevel() const;
	void SetRemain();
	int GetDistance() const;
	void Draw();

private:
	int distance;
	Tile * open_map;
	Tile * destination;
	Tile * current;
};

class Node
{
	Node *next;
};


#endif
