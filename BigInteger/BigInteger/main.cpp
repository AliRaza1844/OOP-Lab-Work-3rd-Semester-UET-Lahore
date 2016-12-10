///////////////////////////////////////////////////////////
//  Ali Raza			16-11-2016
//  2015cs52
//  As we know that int data type in C++ can store only
//  upto five digits. And if we try store a value having 
//	more than five digits it creats garbage value. The
//	solution of this problem is BIGINT. This fuction will
//  show the basic functionality of this class...
///////////////////////////////////////////////////////////


// Header files...
#include<iostream>
#include<conio.h>
#include<ctime>
#include"BigInt.h";
using namespace std;

// main function starts from here...
int main()
{
	time_t start, end;
	BigInt Int1, Int2;
	string str;

	char again = 'y';
	while (again == 'y')
	{
		system("cls");
		int x;
		cout << "******************Welcome to the Big Integer World*******************\n\n";
		
		cout << " Please enter the first number...\n ";
		cin >> Int1;
		cout << " Now enter the second numeber...\n ";
		cin >> Int2;
		cout << " Now enter the operator you want to apply...\n ";
		cin >> str;

		if (str == "+")
			{
				start = time(0);
				BigInt sum;
				sum = Int1 + Int2;
				cout << "\n The sum of numbers is given as  :  " << Int1 << " + " << Int2 <<" = " << sum;
				end = time(0);
				cout << "\n Total time to sum  :  " << end - start << "s\n";
			}
		else if (str == "-")
			{
				start = time(0);
				BigInt sub;
				sub = Int1 - Int2;
				cout << "\n The diffrence of numbers is given as  :  " << Int1 << " - " << Int2 << " = " << sub;
				end = time(0);
				cout << "\n Total time to subtract  :  " << end - start << "s\n";
			}
		else if (str == "*")
			{
				start = time(0);
				BigInt multiply;
				multiply = Int1 * Int2;
				cout << "\n The Multiplication of numbers is given as  :  " << Int1 << " * " << Int2 << " = " << multiply;
				end = time(0);
				cout << "\n Total time to multiply  :  " << end - start << " s\n";
			}
		else if (str == "/")
			{
				start = time(0);
				BigInt devide;
				devide = Int1 / Int2;
				cout << "\n By dividing first number by second we have  :  " << Int1 << " / " << Int2 << " = " << devide;
				end = time(0);
				cout << "\n Total time to devide  :  " << end - start << " s\n";
			}
		else if (str == "%")
			{
				start = time(0);
				BigInt remainder;
				remainder = Int1 % Int2;
				cout << "\n Taking remainder of first number with the second  :  " << Int1 << " % " << Int2 << " = " << remainder;
				end = time(0);
				cout << "\n Total time to take remainder  :  " << end - start << " s\n";
			}
		else if (str == "+=")
			{
				start = time(0);
				Int1 += Int2;
				cout << "\n After applying the += operator the first number is  :  " << Int1;
				end = time(0);
				cout << "\n Total time  :  " << end - start << "s\n";
			}
		else if (str == "-=")
			{
				start = time(0);
				Int1 -= Int2;
				cout << "\n After applying the -= operator the first number is  :  " << Int1;
				end = time(0);
				cout << "\n Total time   :  " << end - start << "s\n";
			}
		else if (str == "*")
			{
				start = time(0);
				Int1 *= Int2;
				cout << "\n After applying the *= operator the first number is  :  " << Int1;
				end = time(0);
				cout << "\n Total time  :  " << end - start << " s\n";
			}
		else if (str == "/")
			{
				start = time(0);
				Int1 /= Int2;
				cout << "\n After applying the /= operator the first number is  :  " << Int1;
				end = time(0);
				cout << "\n Total time to devide  :  " << end - start << " s\n";
			}
		else if (str == "%")
			{
				start = time(0);
				Int1 % Int2;
				cout << "\n After applying the %= operator the first number is  :  " << Int1;
				end = time(0);
				cout << "\n Total time to take remainder  :  " << end - start << " s\n";
			}
		else if (str == "++")
			{
				cout << "\n Pre increment  :  " << ++Int1 << "    " << ++Int2;
				cout << "\n Post increment  :  " << Int1++ << "    " << Int2++;
				cout << "\n After post increment the numbers are  :  " << Int1 << "    " << Int2;
			}
		else if (str == "--")
			{
				cout << "\n Pre decrement  :  " << --Int1 << "    " << --Int2;
				cout << "\n Post decrement  :  " << Int1-- << "   " << Int2--;
				cout << "\n After post decrement the numbers are  :  " << Int1 << "    " << Int2;
			}
		else if (str == "!")
			{
				if (!Int1)
					cout << "\n First number is not zero";
				else
					cout << "\n First number is zero";
				if (!Int2)
					cout << "\n Second number is not zero";
				else
					cout << "\n Second number is zero";
			}
		else if (str == "=")
			{
				Int1 = Int2;
				cout << "\n After applying assignment operator the first number is  " << Int1 << " and the second number is" << Int2;
			}
		else if (str == "==")
			{
				if (Int1 == Int2)
					cout << "\n Both numbers are equal.";
				else
					cout << "\n Both numbers are not equal.";
			}
		else if (str == "!=")
			{
				if (Int1 != Int2)
					cout << "\n Both numbers are not equal.";
				else
					cout << "\n Both numbers are equal.";
			}
		else if (str == ">")
			{
				if (Int1 > Int2)
					cout << "\n First number is greater than the second number.";
				else
					cout << "\n First number is not greater than the second number.";
			}
		else if (str == "<")
			{
				if (Int1 < Int2)
					cout << "\n First number is smaller than the second number.";
				else
					cout << "\n First number is not smaller than the second number.";
			}
		else if (str == ">=")
			{
				if (Int1 >= Int2)
					cout << "\n First number is greater than or equal to the second number.";
				else
					cout << "\n First number is smaller than the second number.";
			}
		else if (str == "<=")
			{
				if (Int1 <= Int2)
					cout << "\n First number is smaller than or equal to the second number.";
				else
					cout << "\n First number is greater than the second number.";
			}
		cout << "\n\n If you want to continue enter y else enter n\n";
		cin >> again;
	}

	_getch();
}
