#ifndef _H_TILEMAP
#define _H_TILEMAP

using namespace std;


class Tile
{
public:
	bool isPassable;
};

class Map
{
public:
	Map();
	~Map();
	Tile** tile;
	int ROW;
	int COL;

};


#endif
