#ifndef _H_TILEMAP
#define _H_TILEMAP
#include <vector>
using namespace std;


class Tile
{
public:
	Tile();
	bool isPassable;
	char symbol;
	short unsigned int posX;
	short unsigned int posY;
	short unsigned int arrayPos;

};

class Map
{
public:
	Map();
	void setEnd(int, int);
	void setStart(int, int);
	void updateMap(int, char);
	void draw() const;
	int getXMax() const;
	int getYMax() const;
	bool isGood(int, int) const;
	Tile getTile(int) const; // by index
	Tile getTile(int, int) const; // by coordinate

	Tile* getStart() const;
	vector<Tile> getMap() const;
	Tile* getEnd() const;

private:
	vector<Tile> tile;
	Tile* start;
	Tile* end;
	int ROW;
	int COL;

};


#endif
