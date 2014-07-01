#ifndef _H_PATHFIND
#define _H_PATHFIND
#include "tilemap.h"

class Path
{

public:
	Path(const Map);
	int GetCurrentX() const;
	int GetCurrentY() const;
	int GetLevel() const;
	int GetRemain();
	int GetDistance() const;
	void Draw();

private:
	int level; // units traveled;
	int distance;
	Tile * destination;
	Tile * current;
};




#endif
