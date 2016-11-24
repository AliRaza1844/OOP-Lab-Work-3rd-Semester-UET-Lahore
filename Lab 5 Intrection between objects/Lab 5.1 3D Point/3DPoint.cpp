// 3D Point class defination...

#include"3DPoint.h";

// Constructor...
threeDPoint::threeDPoint() 
{
	x = y = z = 0.0;
}

// Dectructor...
threeDPoint::~threeDPoint()
{
	cout << "Point deleted...";
}

// To get the values of the 3D point...
void threeDPoint::setPoint(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

// To print the values of a 3D Point...
void threeDPoint::printPoint()
{
	cout << "(" << x << "," << y <<","<< z << ")";
}

// To get distance between two points...
float threeDPoint::getDistance(threeDPoint* p)
{
	float dx, dy, dz;
	dx = x - p->x;
	dy = y - p->y;
	dz = z - p->z;
	float distance = sqrt(pow(dx,2) + pow(dy,2) + pow(dz,2));
	return distance;
}

// To negate the value of a point...
void threeDPoint :: negate()
{
	x *= -1;
	y *= -1;
	z *= -1;
}