/////////////////////////////////////////////////
//  Ali Raza				14-11-2016
//  2015cs52
//  This program is about polynomial class.
/////////////////////////////////////////////////

#include<iostream>
#include"Polynomial.h";
#include<conio.h>
using namespace std;

Polynomial getValues(int degree)
{
	double* temp = new double[degree + 1];
	for (int i = 0; i <= degree; i++)
		cin >> temp[i];
	Polynomial p(temp, degree);
	delete[] temp;
	return p;
}

int main()
{
	char again = 'y';
	while (again == 'y')
	{
		system("cls");
		int x;
		cout << "*************Welcome to the polynomial class function***************\n\n";
		cout << " What you want to do.\n   1-Add two polynomails\n   2-Multiply two ploynomials\n   3-Print a polynomial"
			<<"\n   4-Evaluate a polynomial\n ";
		Select:
		cin >> x;
		switch (x)
		{
			// Adding two polynomials...
			case 1:						
				{
					int degree;
				
					cout << "\n Enter the degree of first polynomial\n ";
					cin >> degree;
					cout << "\n Now enter the coefficients of the polynomial.\n ";
					Polynomial p1=getValues(degree);
				
					cout << "\n Enter the degree of second polynomial\n ";
					cin >> degree;
					cout << "\n Now enter the coefficients of the polynomial.\n ";
					Polynomial p2 = getValues(degree);
				
					Polynomial sum = p1 + p2;
					char *t1=p1.toString(), *t2= p2.toString(), *t3= sum.toString();
					cout << "\n The sum of the polynomial p1 = " << t1 << " and p2 = " << t2
						<< " is given as\n p1 + p2 = " << t3;
					cout << "\n And its degree is  :  " << sum.getDegree();
					delete[]t1;
					delete[]t2;
					delete[]t3;
					break;
				}

			// Multiply two polynomial...
			case 2:
				{
					int degree;

					cout << "\n Enter the degree of first polynomial.\n ";
					cin >> degree;
					cout << "\n Now enter the coefficients of the polynomial.\n ";
					Polynomial p1 = getValues(degree);

					cout << "\n Enter the degree of second polynomial\n ";
					cin >> degree;
					cout << "\n Now enter the coefficients of the polynomial.\n ";
					Polynomial p2 = getValues(degree);

					Polynomial mult = p1 * p2;
					char *t1 = p1.toString(), *t2 = p2.toString(), *t3 = mult.toString();
					cout << "\n The multiplication of the polynomial p1 = " << t1 << " and p2 = " << t2
						<< " is given as\n p1 * p2 = " << t3;
					cout << "\n And its degree is  :  " << mult.getDegree();
					delete[]t1;
					delete[]t2;
					delete[]t3;

					break;
				}

			// Printing a polynomial...
			case 3:
				{
					int x, degree;

					cout << "\n Enter the degree of polynomial\n ";
					cin >> degree;
					cout << "\n Now enter the coefficients of the polynomial.\n ";
					Polynomial p = getValues(degree);
					cout << "\n The polynomial is given as  :   "<<p.toString();
					break;
				}

			// Evaluating a polynomial...
			case 4:
			{
				int x, degree;

				cout << "\n Enter the degree of polynomial\n ";
				cin >> degree;
				cout << "\n Now enter the coefficients of the polynomial.\n ";
				Polynomial p = getValues(degree);
				cout << "\n Now enter the value of x \n ";
				cin >> x;
				cout << "\n The value of this polynomial is given as   :   "<<p.evaluate(x);

				break;
			}
			default:
			{
				cout << " \nYour input is not correct. Please enter a valid input.\n";
				goto Select;
			}
		}
		cout << "\n\n Press y to continue and n to exit.\n";
		cin >> again;
	}

}