// Interface of Hockey Game class...

#include<iostream>
using namespace std;
class HockeyGame
{
private:
	int position, height, weight, noOfGoals, salary;
public:
	HockeyGame();
	~HockeyGame();
	void setPlayer(int,int,int,int,int);
};