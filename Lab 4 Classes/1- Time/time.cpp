//  Name   :   Ali Raza				29-9-2016
//  Registration No:  2015-cs-52
//  Objects and classes in C++

#include<iostream>
#include<conio.h>
using namespace std;

// Defination of class Time.
class Time 
{
private:
	// Data members of the function...
	int hour;
	int min;
	int sec;
public:
	// constructer Function...
	Time()
	{
		hour = 0;
		min = 0;
		sec = 0;
	}

	// Member function for setting the time...
	void setTime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	// Member function for printing the time...
	void printTime()
	{
		cout << "\n The time is given as  :   " << hour << ":" << min << ":" << sec << endl;
	}

	// Function function for changing the time...
	void nextTime(int secs)
	{
		sec += secs;
		while (sec >= 60)
		{
			min++;
			sec -= 60;
		}

		while (min >= 60)
		{
			hour++;
			min -= 60;
		}

		while (hour > 24)
			hour -= 24;
	}
};

int main()
{
	Time t;
	char ch='y';
	int x;
	
	while (ch == 'y')
	{
		cout << "\n Which of the following function you want to perform?\n "
			<< "1- Set Time\n 2- Print Time\n 3- Reset Time\n ";
		cin >> x;

		switch (x)
		{
			case 1:
			{
				int hours, mins, secs;
				cout << "\n Please enter the time without colons.\n ";
				cin >> hours >> mins >> secs;
				t.setTime(hours, mins, secs);
				break;
			}
			case 2:
			{
				t.printTime();
				break;
			}
			case 3:
			{
				int sec;
				cout << "\n Enter the seconds you want to add.";
				cin >> sec;
				t.nextTime(sec);
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
	
	_getch();
	return 0;
}