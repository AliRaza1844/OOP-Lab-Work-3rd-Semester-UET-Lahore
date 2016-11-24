#include "RationalNum.h"


// Constructer
RationalNum::RationalNum()
{
	numerator = denominator = 0;
}

// Destructer
RationalNum::~RationalNum()
{
	cout << "Number deleted...";
}

// Setting a rational number...
void RationalNum::setRationlNum(int num, int denom)
{
	numerator = num;
	denominator = denom;
}

// Printing a rational number...
void RationalNum::printRationalNum()
{
	cout << numerator << "/" << denominator;
}

// Writing a rational in a output file...
void RationalNum::writeRationlNum()
{
	ofstream output;
	output.open("output.txt", ios::app);
	output << numerator << "/" << denominator<<endl;
	output.close();
}

// + operator overloading...
RationalNum RationalNum::operator+(RationalNum r)
{
	RationalNum temp;
	temp.numerator = numerator*r.denominator + denominator*r.numerator;
	temp.denominator = denominator*r.denominator;
	return temp;
}

// - operator overloading...
RationalNum RationalNum::operator-(RationalNum r)
{
	RationalNum temp;
	temp.numerator = numerator*r.denominator - denominator*r.numerator;
	temp.denominator = denominator*r.denominator;
	return temp;
}

// * operator overloading...
RationalNum RationalNum::operator*(RationalNum r)
{
	RationalNum temp;
	temp.numerator = numerator*r.numerator;
	temp.denominator = denominator*r.denominator;
	return temp;
}

// / operator overloading...
RationalNum RationalNum::operator/(RationalNum r)
{
	RationalNum temp;
	temp.numerator = numerator*r.denominator;
	temp.denominator = denominator*r.numerator;
	return temp;
}

// Simplifying a Rational number...
void RationalNum::simplifyNum()
{
	int i = numerator < denominator ? numerator : denominator;
	while (i > 1)
	{
		if (numerator%i == 0 && denominator%i == 0)
		{
			numerator /= i;
			denominator /= i;
		}
		i--;
	}
}