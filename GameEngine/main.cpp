#include <iostream>
#include <string>
#include "tilemap.h"

using namespace std;


int main()
{
	Map map;
	string input;
	int x;
	int y;
	cout << "Enter Start Location 'X,Y'" << endl;
	cin >> x;
	cin.ignore();
	cin >> y;
	map.tile[x + y * map.COL].isStartLocation = true;

	cout << "Enter End Location 'X,Y'" << endl;
	cin >> x;
	cin.ignore();
	cin >> y;
	map.tile[x + y * map.COL].isEndLocation = true;
	map.DrawMap(map);

	return 0;
}