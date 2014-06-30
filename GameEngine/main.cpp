#include <iostream>
#include <string>
#include "tilemap.h"

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
	map.SetStart(x, y);
	cout << "Enter End Location 'X,Y'" << endl;
	cin >> x;
	cin.ignore();
	cin >> y;
	map.SetEnd(x, y);
	map.Draw();

	return 0;
}