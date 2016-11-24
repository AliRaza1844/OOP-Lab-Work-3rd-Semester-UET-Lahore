///////////////////////////////////////////////////////////
//  Name : Ali Raza							31-10-2016
//  Registration No. : 2015cs52
//  This function will overload various build in operators
//  for user defined data types...
///////////////////////////////////////////////////////////

// Header Files
#include<iostream>
#include<conio.h>
#include "Time.h";
#include"Date.h";
#include"String.h";
#include"Matrix.h";
using namespace std;

///////////////////////////////////////////////////////////
//********************main function**********************//

int main()
{
	cout << "***************Welcome to Operator Overloading function******************";
	int op;
	char again = 'y';
	while (again == 'y')
	{
		cout << "\n\n Please select one from the following Classes.\n   1-Date Class\n   2-Time Class\n   3-String Class\n   4-Matrix Class\n   ";
		select:
		cin >> op;
		switch (op)
		{
			case 1:						// Date Class operator overloading...
			{
				int x;
				char a='y';
				while (a == 'y')
				{
					cout << "\n Which of the following function you want to perform.";
					cout << "\n   1-Increment\n   2-Decrement\n   3-Add two Dates\n   4-Find the diffrence between two Dates\n   5-Check Equality of two dates"
						<< "\n   6-Find the greater or smaller from two dates\n   ";
					select_d:
					cin >> x;
					switch (x)
					{
						case 1:					// Increment a Date Object...
						{
							Date d;
							int day, month, year;
							cout << "\n Enter the date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d.setDate(day, month, year);
							cout << "\n The date you entered is  :  ";
							d.printDate();
							d++;
							cout << "\n Date after increment is  :  ";
							d.printDate();
							break;
						}
						case 2:					// Decrement a Date Object...
						{
							Date d;
							int day, month, year;
							cout << "\n Enter the date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d.setDate(day, month, year);
							cout << "\n The date you entered is  :  ";
							d.printDate();
							d--;
							cout << "\n Date after decrement is  :  ";
							d.printDate();
							break;
						}
						case 3:					// Adding two Date Objects...
						{
							Date d1,d2,sum;
							int day, month, year;
							cout << "\n Enter first date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d1.setDate(day, month, year);
							cout << "\n Enter second date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d2.setDate(day, month, year);
							sum = d1 + d2;
							cout << "\n Addition of dates ";
							d1.printDate();
							cout << " and ";
							d2.printDate();
							cout << " is given as  :  ";
							sum.printDate();
							break;
						}
						case 4:					// Subtract one Date object from the other...
						{
							Date d1, d2, dif;
							int day, month, year;
							cout << "\n Enter first date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d1.setDate(day, month, year);
							cout << "\n Enter second date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d2.setDate(day, month, year);
							dif = d1 - d2;
							cout << "\n diffrence of dates ";
							d1.printDate();
							cout << " and ";
							d2.printDate();
							cout << " is given as  :  ";
							dif.printDate();
							break;
						}
						case 5:					// Checking equality of two objects...
						{
							Date d1, d2;
							int day, month, year;
							cout << "\n Enter first date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d1.setDate(day, month, year);
							cout << "\n Enter second date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d2.setDate(day, month, year);
							if (d1 == d2)
								cout << "\n Both dates are equal.";
							else if (d1 != d2)
								cout << "\n Dates are not equal.";
							break;
						}
						case 6:					// Finding greater or smaller from two objects...
						{
							Date d1, d2;
							int day, month, year;
							cout << "\n Enter first date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d1.setDate(day, month, year);
							cout << "\n Enter second date without dashes. (dd mm yyyy)\n ";
							cin >> day >> month >> year;
							d2.setDate(day, month, year);
							if (d1 > d2)
								cout << "\n First date is greater than the second date.";
							else if (d1 < d2)
								cout << "\n First date is less than the second date.";
							break;
						}
						default:				// if user enters an invalid value default case is called...
						{
							cout << "\n Your input is not correct enter value again\n   ";
							goto select_d;
						}
					}
					cout << "\n\n Enter y to continue with the same class or n to not.\n ";
					cin >> a;
				}
				break;
			}
			case 2:						// Time Class operator overloading...
			{
				int x;
				char a = 'y';
				while (a == 'y')
				{
					cout << "\n Which of the following function you want to perform.";
					cout << "\n   1-Increment\n   2-Decrement\n   3-Add two Times\n   4-Find the diffrence between two times\n   5-Check Equality of two times"
						<< "\n   6-Find the greater or smaller from two times\n   ";
				select_t:
					cin >> x;
					switch (x)
					{
					case 1:					// Increment a Time Object...
					{
						Time t;
						int sec, min, hour;
						cout << "\n Enter the time without colons. (hh mm ss)\n ";
						cin >> hour >> min >> sec;
						t.setTime(hour, min, sec);
						cout << "\n The time you entered is  :  ";
						t.printTime();
						t++;
						cout << "\n Time after increment is  :  ";
						t.printTime();
						break;
					}
					case 2:					// Decrement a Time Object...
					{
						Time t;
						int sec, min, hour;
						cout << "\n Enter the time without colons. (hh mm ss)\n ";
						cin >> hour >> min >> sec;
						t.setTime(hour, min, sec);
						cout << "\n The time you entered is  :  ";
						t.printTime();
						t--;
						cout << "\n Time after decrement is  :  ";
						t.printTime();
						break;
					}
					case 3:					// Adding two Time Objects...
					{
						Time t1, t2, sum;
						int sec, min, hour;
						cout << "\n Enter the first time without colons. (hh mm ss)\n ";
						cin >> hour >> min >> sec;
						t1.setTime(hour, min, sec);
						cout << "\n Enter the second time without colons. (hh mm ss)\n ";
						cin >> hour >> min >> sec;
						t2.setTime(hour, min, sec);
						sum = t1 + t2;
						cout << "\n Addition of Times ";
						t1.printTime();
						cout << " and ";
						t2.printTime();
						cout << " is given as  :  ";
						sum.printTime();
						break;
					}
					case 4:					// Subtract one Time object from the other...
					{
						Time t1, t2, sub;
						int sec, min, hour;
						cout << "\n Enter the first time without colons. (hh mm ss)\n ";
						cin >> hour >> min >> sec;
						t1.setTime(hour, min, sec);
						cout << "\n Enter the second time without colons. (ss mm hh)\n ";
						cin >> hour >> min >> sec;
						t2.setTime(hour, min, sec);
						sub = t1 + t2;
						cout << "\n Subtraction of ";
						t1.printTime();
						cout << " from ";
						t2.printTime();
						cout << " is given as  :  ";
						sub.printTime();
						break;
					}
					case 5:					// Checking equality of two objects...
					{
						Time t1, t2;
						int sec, min, hour;
						cout << "\n Enter the first time without colons. (hh mm ss)\n ";
						cin >> hour >> min >> sec;
						t1.setTime(hour, min, sec);
						cout << "\n Enter the second time without colons. (hh mm ss)\n ";
						cin >> hour >> min >> sec;
						t2.setTime(hour, min, sec);
						if (t1 == t2)
							cout << "\n Both times are equal.";
						else if (t1 != t2)
							cout << "\n Times are not equal.";
						break;
					}
					case 6:					// Finding greater or smaller from two objects...
					{
						Time t1, t2;
						int sec, min, hour;
						cout << "\n Enter the first time without colons. (hh mm ss)\n ";
						cin >> hour >> min >> sec;
						t1.setTime(hour, min, sec);
						cout << "\n Enter the second time without colons. (hh mm ss)\n ";
						cin >> hour >> min >> sec;
						t2.setTime(hour, min, sec);
						if (t1 > t2)
							cout << "\n First time is greater than the second date.";
						else if (t1 < t2)
							cout << "\n First time is less than the second date.";
						break;
					}
					default:				// if user enters an invalid value default case is called...
					{
						cout << "\n Your input is not correct enter value again\n   ";
						goto select_t;
					}
					}

					cout << "\n\n Enter y to continue with the same class or n to not.\n ";
					cin >> a;
				}
				break;
			}
			case 3:						// String Class operator overloading...
			{
				int x;
				char a = 'y';
				while (a == 'y')
				{
					cout << "\n Which of the following function you want to perform.";
					cout << "\n   1-Adding two String objects\n   2-Check Equality of two Strings"
						<< "\n   3-Find the greater or smaller from two Strings\n   4-Find if a String is null"
						<<"\n   5-Get value of specific index\n  ";
				select_s:
					cin >> x;
					switch (x)
					{
					case 1:					// Adding two String objects...
					{
						String s1, s2, sum;
						char* temp = new char[20];
						cout << "\n Enter the first string.\n ";
						cin >> temp;
						s1 = temp;
						delete[]temp;
						temp = new char[20];
						cout << "\n Enter the second string.\n ";
						cin >> temp;
						s2 = temp;
						delete[]temp;
						sum = s1 + s2;
						cout << "\n Adttion of strings '";
						s1.print();
						cout << "' and '";
						s2.print();
						cout << "' is given as  :  ";
						sum.print();
						break;
					}
					case 2:					// Check equality of two strings...
					{
						String s1, s2;
						char* temp = new char[20];
						cout << "\n Enter the first string.\n ";
						cin >> temp;
						s1 = temp;
						delete[]temp;
						temp = new char[20];
						cout << "\n Enter the second string.\n ";
						cin >> temp;
						s2 = temp;
						delete[]temp;

						if (s1 == s2)
							cout << "\n Both the strings are equal.";
						else if (s1 != s2)
							cout << "\n Strings are not equal.";

						break;
					}
					case 3:					// Find the greater or smaller from two Strings...
					{
						String s1, s2;
						char* temp = new char[20];
						cout << "\n Enter the first string.\n ";
						cin >> temp;
						s1 = temp;
						delete[]temp;
						temp = new char[20];
						cout << "\n Enter the second string.\n ";
						cin >> temp;
						s2 = temp;
						delete[]temp;

						if (s1 > s2)
							cout << "\n First string is greater than the second.";
						else if (s1 < s2)
							cout << "\n First string is smaller than the second";

						break;
					}
					case 4:					// Find if a String is null...
					{
						String s;
						char* temp = new char[20];
						cout << "\n Enter the string.\n ";
						cin >> temp;
						s = temp;
						delete[]temp;

						if (!s)
							cout << "\n String is null.";
						else
							cout << "\n String is not null";

						break;
					}
					case 5:					// Get value of specific index...
					{
						String s;
						int index, size;
						char* temp = new char[20];
						cout << "\n Enter the string.\n ";
						cin >> temp;
						s = temp;
						size = strlen(temp);
						delete[]temp;

						cout << "\n Enter the index from 0 to " << size-1 << "\n ";
						cin >> index;
						if (s[index])
							cout << s[index];
						else
							cout << "\n The index you entered is not correct";

						break;
					}
					default:				// if user enters an invalid value default case is called...
					{
						cout << "\n Your input is not correct enter value again\n   ";
						goto select_s;
					}
					}

					cout << "\n\n Enter y to continue with the same class or n to not.\n ";
					cin >> a;
				}
				break;
			}
			case 4:						// Matrix Class operatoroverloading...
			{
				int x;
				char a = 'y';
				while (a == 'y')
				{
					cout << "\n Which of the following function you want to perform.";
					cout << "\n   1-Adding two Matrices\n   2-Subtracting a matrix from the other"
						<< "\n   3-Multiply two matrices\n   4-Checking equality of two matrices"
						<< "\n   5-Find if a matrix is identity\n  ";
				select_m:
					cin >> x;
					switch (x)
					{
					case 1:					// Adding two Matrix objects...
					{
						Matrix m1, m2, sum;
						cout << "\n Enter the entries of first matrix.\n";
						m1.setValue();
						cout << "\n Enter the entries of second matrix.\n";
						m2.setValue();
						sum = m1 + m2;
						cout << "\n The sum of the two given matrices is given as  :  \n";
						sum.print();
						break;
					}
					case 2:					// Subtracting a matrix from the other...
					{
						Matrix m1, m2, sub;
						cout << "\n Enter the entries of first matrix.\n";
						m1.setValue();
						cout << "\n Enter the entries of second matrix.\n";
						m2.setValue();
						sub = m1 - m2;
						cout << "\n The subtraction of second matrix from the first is given as  :  \n";
						sub.print();
						break;
					}
					case 3:					// Multiply two matrices...
					{
						Matrix m1, m2, multiply;
						cout << "\n Enter the entries of first matrix.\n";
						m1.setValue();
						cout << "\n Enter the entries of second matrix.\n";
						m2.setValue();
						multiply = m1 * m2;
						cout << "\n The Multiplication of the matrices is given as  :  \n";
						multiply.print();
						break;
					}
					case 4:					// Checking equality of two matrices...
					{
						Matrix m1, m2;
						cout << "\n Enter the entries of first matrix.\n";
						m1.setValue();
						cout << "\n Enter the entries of second matrix.\n";
						m2.setValue();

						if (m1 == m2)
							cout << "\n Both the matrices are equal.";
						else if (m1 != m2)
							cout << "\n Matrices are not equal.";

						break;
					}
					case 5:					// Find if a matrix is identity...
					{
						Matrix m1;
						cout << "\n Enter the entries of the matrix.\n";
						m1.setValue();

						if (!m1)
							cout << "\n This Matrix is an identity.\n";
						else
							cout << "\n This matrix is not an identity.\n";
						break;
					}
					default:				// if user enters an invalid value default case is called...
					{
						cout << "\n Your input is not correct enter value again\n   ";
						goto select_m;
					}
					}

					cout << "\n\n Enter y to continue with the same class or n to not.\n ";
					cin >> a;
				}
				break;
			}
			default:
			{
				cout << "\n Your input is not correct enter value again\n   ";
				goto select;
			}
		}
		// Asking if the user want to continue or not...
		cout << "\n\n Know tell do you want to continue the program or exit (y or n).\n ";
		cin >> again;
	}

	_getch();
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////