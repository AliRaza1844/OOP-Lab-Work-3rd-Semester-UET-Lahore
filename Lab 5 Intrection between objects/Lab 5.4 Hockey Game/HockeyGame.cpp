#include "HockeyGame.h"



HockeyGame::HockeyGame()
{
	position = 0;
	height = 5;
	weight = 50;
	noOfGoals = 0;
	salary = 0;
}


HockeyGame::~HockeyGame()
{
	cout << "Object deleted.";
}

void HockeyGame::setPlayer(int p, int h, int w, int g, int s)
{
	position = p;
	height = h;
	weight = w;
	noOfGoals = g;
	salary = s;
}
