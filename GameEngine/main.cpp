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
	cout << "Here's the selected maze of size: " << map.getXMax() << ", " << map.getYMax();
	cout << endl << endl;
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
	cout << endl;
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
	cout << endl;
	map.setEnd(x, y);
	path.loadMap(map);

	//cout << "The start and end points have been added." << endl << endl;
	//map.draw();
	cout << "Here's the path found for your maze: " << endl << endl;
	path.draw();
	cout << endl << "Distance Traveled:" << to_string(path.getDistance()) << endl;

	return 0;
}

