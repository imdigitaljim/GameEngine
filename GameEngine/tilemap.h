#ifndef _H_TILEMAP
#define _H_TILEMAP

using namespace std;


class Tile
{
public:
	Tile();
	bool isPassable;
	char symbol;
};

class Map
{
public:
	Map();
	~Map();
	void SetEnd(int, int);
	void SetStart(int, int);
	void Draw() const;



private:
	Tile* tile;
	unsigned int StartLocation;
	unsigned int EndLocation;
	int ROW;
	int COL;

};


#endif
