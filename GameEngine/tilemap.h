#ifndef _H_TILEMAP
#define _H_TILEMAP

using namespace std;


class Tile
{
public:
	Tile();
	bool isPassable;
	char symbol;
	unsigned int arrPos;
	short unsigned int posX;
	short unsigned int posY;

};

class Map
{
public:
	Map();
	~Map();
	void SetEnd(int, int);
	void SetStart(int, int);
	void UpdateMap(int, char);
	void Draw() const;
	int GetXMax() const;
	int GetYMax() const;
	Tile GetTile(int) const;
	Tile* GetStart() const;
	Tile* GetMap() const;
	Tile* GetEnd() const;

private:
	Tile* tile;
	Tile* start;
	Tile* end;
	int ROW;
	int COL;

};


#endif
