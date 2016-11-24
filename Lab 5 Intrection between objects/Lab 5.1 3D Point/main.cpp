//  Name  :  Ali Raza					06-10-2016
//  Reg#  :  2015cs52
//  This function will perform some simple operations on 3D Points...

#include<iostream>
#include<conio.h>

#include"3DPoint.h";
using namespace std;

int main()
{
	threeDPoint* p1,* p2;
	p1 = new threeDPoint;
	p2 = new threeDPoint;
	char ch = 'y';
	int x;
	cout << "\t\t\t---Welcome to the 3D Point function---\n";
	while (ch == 'y')
	{
		cout << "\n Which of the following function you want to perform?\n "
			<< "1- Set Point\n 2- Print Point\n 3- Get Distance between points\n 4- Negate a point\n ";
		cin >> x;

		switch (x)
		{
		case 1:
		{
			float x, y, z;
			cout << "\n Please enter the x, y and z co-ordinates of the point...\n ";
			cin >> x >> y >> z;
			p1->setPoint(x,y,z);
			break;
		}
		case 2:
		{
			cout << "\n The co-ordinates of the point are given as : ";
			p1->printPoint();
			cout << endl;
			break;
		}
		case 3:
		{
			float x, y, z;
			cout << "\n Enter the co-ordinates of first point...\n ";
			cin >> x >> y >> z;
			p1->setPoint(x, y, z);

			cout << "\n Now enter the co-ordinates of second point...\n ";
			cin >> x >> y >> z;
			p2->setPoint(x, y, z);

			float distance = p1->getDistance(p2);
			cout << "\n The distance between point p1";
			p1->printPoint();
			cout << " and p2";
			p2->printPoint();
			cout << " is given as  :  " << distance<<endl;
			break;
		}

		case 4:
		{
			float x, y, z;
			cout << "\n Enter the point you want to negate...\n ";
			cin >> x >> y >> z;
			p1->setPoint(x, y, z);
			p1->negate();
			cout << "\n The co-ordinates of the point after negation are given as  :  ";
			p1->printPoint();
			break;
		}
		default:
		{
			cout << "\n Your input is not valid.";
			break;
		}
		}
		cout << "\n Enter y to continue and n to exit.\n ";
		cin >> ch;
	}

	delete p1;
	delete p2;
	_getch();
	return 0;
}
