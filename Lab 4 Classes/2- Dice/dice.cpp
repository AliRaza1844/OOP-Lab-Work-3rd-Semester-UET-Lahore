//  Name   :   Ali Raza				29-9-2016
//  Registration No:  2015-cs-52
//  Objects and classes in C++

#include<iostream>
#include<conio.h>
#include<time.h>
#include<math.h>
using namespace std;

// Defination of class Dice.
class Dice
{
private:
	int facevalue;
public:
	
	// Constructer
	Dice()
	{
		srand(time(NULL));
		facevalue = 0;
	}

	// Function for rolling the dice...
	int roll()
	{
		
		facevalue = rand() % 6 + 1;
		return facevalue;
	}

	// Function for getting the face value...
	void getFacevalue()
	{
		cout << facevalue<<endl;
	}
};


int main()
{
	Dice d1, d2;
	char ch = 'y';
	int x;

	while (ch == 'y')
	{
		cout << "\n Which of the following function you want to perform?\n "
			<< "1- Roll the Dices\n 2- Get the face value of a dice\n  ";
		cin >> x;

		switch (x)
		{
			case 1:										// Roll the dices...
			{
				int f1, f2;
				f1 = d1.roll();
				f2 = d2.roll();
				int sum = f1 + f2;
				cout << "\n The face value of dice 1 is  :   " << f1
					<<"\n The face vaue of dice 2 is  :   "<<f2
					<<"\n And their sum is     :   "<<sum;
				if (sum > 7)								// Win Condition...
					cout << "\n\t\tHurrah! You win...\n";
				else
					cout << "\n\t\tOh! you lose...\n";
				break;
			}
			case 2:										// Get value of dices...
			{
				cout << "\n The face value of dice 1 is  :   ";
				d1.getFacevalue();
				cout << "\n The face value of dice 2 is  :   ";
				d2.getFacevalue();
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
	cout << "\n Thank you for coming. See you again.";
	_getch();
	return 0;
}