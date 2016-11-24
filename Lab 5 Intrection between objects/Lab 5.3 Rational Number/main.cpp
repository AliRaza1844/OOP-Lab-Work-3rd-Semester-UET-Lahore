//  Name  :  Ali Raza					08-10-2016
//  Reg#  :  2015cs52
//  This function will read a sequence of rational numbers and operations to perform on them 
//  from a input.txt file and will store the results in output.txt file...

#include<iostream>
#include<conio.h>
#include<fstream>
#include"RationalNum.h";
using namespace std;

int main()
{
	int num, denom;
	char ch;
	RationalNum r1, r2;
	ifstream input;
	ofstream output;
	output.open("output.txt");
	output.clear();
	output.close();
	input.open("input.txt");
		if (input)
		{
			while (!input.eof())
			{
				input >> num;
				input.ignore();
				input >> denom;
				input >> ch;
				r1.setRationlNum(num,denom);
				input >> num;
				input.ignore();
				input >> denom;
				r2.setRationlNum(num, denom);
				if (ch == '+')
				{
					RationalNum sum;
					sum = r1 + r2;
					sum.simplifyNum();
					sum.writeRationlNum();
				}
				else if (ch == '-')
				{
					RationalNum sub;
					sub = r1 - r2;
					sub.simplifyNum();
					sub.writeRationlNum();
				}
				else if (ch == '*')
				{
					RationalNum multi;
					multi = r1 * r2;
					multi.simplifyNum();
					multi.writeRationlNum();
				}
				else if (ch == '/')
				{
					RationalNum div;
					div = r1 / r2;
					div.simplifyNum();
					div.writeRationlNum();
				}
			}
		}

	input.close();
	_getch();
}