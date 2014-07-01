#include <iostream>
#include <string>
#include "tilemap.h"
#include "pathfind.h"

using namespace std;

int main()
{
	Map map;
	int x, y;
	map.Draw();
	cout << "Enter Start Location 'X,Y'" << endl;
	cin >> x;
	cin.ignore();
	cin >> y;
	while (x < 0 || x > map.GetXMax() 
		|| y < 0 || y > map.GetYMax() 
		|| map.GetTile(x + y * map.GetXMax()).symbol == 'X')
	{
		cout << "Out of bounds: Try again:" << endl << "X,Y:";
		cin >> x;
		cin.ignore();
		cin >> y;
	}
	map.SetStart(x, y);
	cout << "Enter End Location 'X,Y'" << endl;
	cin >> x;
	cin.ignore();
	cin >> y;
	while (x < 0 || x > map.GetXMax()
		|| y < 0 || y > map.GetYMax()
		|| map.GetTile(x + y * map.GetXMax()).symbol == 'X')
	{
		cout << "Out of bounds: Try again:" << endl << "X,Y:";
		cin >> x;
		cin.ignore();
		cin >> y;
	}
	map.SetEnd(x, y);
	map.Draw();
	Path path(map);

	cout << "Distance Left:" << to_string(path.GetDistance()) << endl;


	return 0;
}

