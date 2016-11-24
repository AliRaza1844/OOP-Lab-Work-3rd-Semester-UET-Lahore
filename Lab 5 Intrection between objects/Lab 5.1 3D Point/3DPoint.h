#pragma once
// 3D Point class interface

#include<iostream>
#include<cmath>
using namespace std;
class threeDPoint
{
private:
	float x, y, z;
public:
	threeDPoint();
	~threeDPoint();
	void setPoint(float, float, float);
	void printPoint();
	float getDistance(threeDPoint*);
	void negate();
};