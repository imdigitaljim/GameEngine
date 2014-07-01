#include <iostream>
#include <string>
#include "tilemap.h"
#include "pathfind.h"

using namespace std;

int main()
{
	Map map;
	Path path;
	int x, y;
	map.draw();
	cout << "Enter Start Location 'X,Y'" << endl;
	cin >> x;
	cin.ignore();
	cin >> y;
	while (x < 0 || x > map.getXMax()
		|| y < 0 || y > map.getYMax()
		|| map.getTile(x, y).symbol == 'X')
	{
		cout << "Out of bounds: Try again:" << endl << "X,Y:";
		cin >> x;
		cin.ignore();
		cin >> y;
	}
	map.setStart(x, y);
	cout << "Enter End Location 'X,Y'" << endl;
	cin >> x;
	cin.ignore();
	cin >> y;
	while (x < 0 || x > map.getXMax()
		|| y < 0 || y > map.getYMax()
		|| map.getTile(x, y).symbol == 'X')
	{
		cout << "Out of bounds: Try again:" << endl << "X,Y:";
		cin >> x;
		cin.ignore();
		cin >> y;
	}
	map.setEnd(x, y);
	path.loadMap(map);
	map.draw();

	cout << "Distance Left:" << to_string(path.getDistance()) << endl;

	path.draw();
	return 0;
}

