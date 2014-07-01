#ifndef _H_PATHFIND
#define _H_PATHFIND
#include "tilemap.h"

using namespace std;

class Path
{

public:
	void loadMap(const Map&);

	void search(int, int, int);
	int getCurrentX() const;
	int getCurrentY() const;
	int getLevel() const;
	void setDirection();
	void setDistance();
	int getDistance() const;
	void draw();
	void pathSearch(int&, int&, int&);
	void drawGrid() const; // debug purposes

private:
	int distance;
	Map map;
	vector <vector<int> > mapGrid;
};

class Node
{
	Node *next;
};


#endif
