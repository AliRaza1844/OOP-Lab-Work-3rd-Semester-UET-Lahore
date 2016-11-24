//  Name  :  Ali Raza					06-10-2016
//  Reg#  :  2015cs52
//  This function will perform some mathematical operations on complex numbers...

#include<iostream>
#include<conio.h>
#include"ComplexNo.h";
using namespace std;

int main()
{
	ComplexNo* c1, *c2;
	c1 = new ComplexNo;
	c2 = new ComplexNo;
	char ch = 'y';
	int op;
	cout << "\t\t\t---Welcome to the Complex Number Calculater---\n";
	float real, img;
	cout << "\n Enter the real and imaginary part of first number.\n ";
	cin >> real >> img;
	c1->setNo(real, img);
	cout << "\n Now enter the real and imaginary part of second number.\n ";
	cin >> real >> img;
	c2->setNo(real, img);

	while (ch == 'y')
	{
		cout << "\n Now which of the followong operation you to perform on the numbers ";
		c1->printNo();
		cout << " and ";
		c2->printNo();
		cout<<"?\n ";
		cout << "1- Add\n 2- Subtract\n 3- Multiply\n 4- Devide\n 5- Conjugate\n";
		cin >> op;
		switch (op)
		{
		case 1:
		{
			ComplexNo* sum = c1->add(c2);
			cout << "\n The sum of the numbers is given as  :    ";
			c1->printNo();
			cout << " + ";
			c2->printNo();
			cout << "  =  ";
			sum->printNo();
			cout << endl;
			delete sum;
			break;
		}
		case 2:
		{
			ComplexNo* sub = c1->subtract(c2);
			cout << "\n The subtraction of first number from second is given as  :    ";
			c1->printNo();
			cout << " - ";
			c2->printNo();
			cout << "  =  ";
			sub->printNo();
			cout << endl;
			delete sub;
			break;
		}
		case 3:
		{
			ComplexNo* multi = c1->multiply(c2);
			cout << "\n Multiplication of the numbers is given as  :    ";
			c1->printNo();
			cout << " * ";
			c2->printNo();
			cout << "  =  ";
			multi->printNo();
			cout << endl;
			delete multi;
			break;
		}

		case 4:
		{
			ComplexNo* div = c1->divide(c2);
			cout << "\n The division of the numbers is given  :    ";
			c1->printNo();
			cout << " / ";
			c2->printNo();
			cout << "  =  ";
			div->printNo();
			cout << endl;
			delete div;
			break;
		}

		case 5:
		{
			c1->conjugate();
			c2->conjugate();
			cout << "\n The conjugate of numbers is given as  :  ";
			c1->printNo();
			cout << "   ";
			c2->printNo();
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
		if (ch == 'y')
		{
			char ch='n';
			cout << "  Now do you want to change the numbers or continue without changing.(y or n)\n ";
			cin >> ch;
			if (ch == 'y')
			{
				cout << "\n Enter the real and imaginary part of first number.\n ";
				cin >> real >> img;
				c1->setNo(real, img);
				cout << "\n Now enter the real and imaginary part of second number.\n ";
				cin >> real >> img;
				c2->setNo(real, img);
			}
		}
	}

	delete c1;
	delete c2;
	_getch();
	return 0;
}
