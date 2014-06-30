#ifndef _H_TILEMAP
#define _H_TILEMAP

using namespace std;


class Tile
{
public:
	Tile();
	bool isPassable;
	bool isStartLocation;
	bool isEndLocation;
};

class Map
{
public:
	Map();
	~Map();
	Tile* tile;
	int ROW;
	int COL;
	void DrawMap(Map) const;

};


#endif
