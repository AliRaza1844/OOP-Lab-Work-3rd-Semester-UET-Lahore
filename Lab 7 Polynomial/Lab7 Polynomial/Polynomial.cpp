#include "Polynomial.h"


// Default Constructor...
Polynomial::Polynomial()
{
	degree = 0;
	coeff = NULL;
}

// Overloaded Constructor...
Polynomial::Polynomial(double *c, int d)
{
	degree = d;
	coeff = new double[degree + 1];
	
	int k = degree;
	for (int i = 0; i <= degree; i++)
	{
		coeff[k] = c[i];
		k--;
	}
}

// Destructor...
Polynomial::~Polynomial()
{
	if (coeff != NULL)
		delete[] coeff;
}

// Copy Constructor...
Polynomial::Polynomial(const Polynomial &c)
{
	degree = c.degree;
	coeff = new double[degree+1];
	
	for (int i = 0; i <= degree; i++)
		coeff[i] = c.coeff[i];
}

// Function convert a double to string...
string Polynomial::doubleToString(double x)
{
	string str;
	if (x < 0)
		{
			x *= -1;
			str += " - ";
		}
	else
		str += " + ";

	if (x<10)
		{
			if (static_cast<int>(x * 10) % 10 == 0)
				str += (x + 48);
			else
			{
				str += (x + 48);
				str += ".";
				str += (static_cast<int>(x * 10) % 10 + 48);
			}
		}
	else
		{
			if (static_cast<int>(x * 10) % 10 == 0)
			{
				str += (x / 10 + 48);
				str += (static_cast<int>(x) % 10 + 48);
			}
			else
			{
				str += (x / 10 + 48);
				str += (static_cast<int>(x) % 10 + 48);
				str += ".";
				str += (static_cast<int>(x * 10) % 10 + 48);
			}
		}

	return str;
}

// Assingment operator (=) overloading...
Polynomial & Polynomial::operator=(const Polynomial &c)
{
	degree = c.degree;
	if (coeff != NULL)
		delete[] coeff;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
		coeff[i] = c.coeff[i];
	return *this;
}

// (+) operator overloading...
Polynomial Polynomial::operator+(const Polynomial &c) const
{
	Polynomial temp;
	temp.degree = (degree >= c.degree) ? degree : c.degree;
	temp.coeff = new double[temp.degree + 1];
	for (int i = 0; i < temp.degree + 1; i++)
		temp.coeff[i] = 0;
	int k = (degree <= c.degree) ? degree : c.degree;
	for (int i = 0; i <= temp.degree; i++)
	{
		if (i <= k)
			temp.coeff[i] += (coeff[i] + c.coeff[i]);
		else if (degree > c.degree)
			temp.coeff[i] = coeff[i];
		else
			temp.coeff[i] = c.coeff[i];
	}
	temp.degree = temp.getDegree();
	return temp;
}

// (*) operator overloading...
Polynomial Polynomial::operator*(const Polynomial &p) const
{
	Polynomial temp;
	temp.degree = degree + p.degree;
	temp.coeff = new double[temp.degree + 1];
	for (int i = 0; i <= temp.degree; i++)
		temp.coeff[i] = 0.0;
	for (int i = 0; i <= degree; i++)
		for (int j = 0; j <= p.degree;j++)
			temp.coeff[i + j] += (coeff[i] * p.coeff[j]);
	return temp;
}

// function to get degree of a polynomial...
int Polynomial::getDegree()
{
	for (int i = degree; i >= 0; i--)
		if (coeff[i] != 0)
			return i;
	return 0;
}

// Function to convert a polynomial into a string...
char* Polynomial::toString()
{
	string str;
	for (int i = degree; i >= 0; i--)
	{
		if (coeff[i] < 0)
		{
			if (i == 0)
				str += doubleToString(coeff[i]);
			else if (i == 1)
			{
				str += doubleToString(coeff[i]);
				str += "x";
			}
			else
			{
				str += doubleToString(coeff[i]);
				//k--;
				str += "x^";
				str += (i + 48);
			}
		}
		else
		{
			if (i == 0)
				str += doubleToString(coeff[i]);
			else if (i == 1)
			{
				str += doubleToString(coeff[i]);
				str += "x";
			}
			else
			{
				str += doubleToString(coeff[i]);
				str += "x^";
				str += (i + 48);	
			}
		}
	}
	
	int length = str.length() + 1;
	char* temp = new char[length];
	for (int i = 0; i < length; i++)
		temp[i] = str[i];

	return temp;
}

// Function to evaluate a polynomial...
double Polynomial::evaluate(double x)
{
	double value=0.0;
	for (int i = 0; i <= degree; i++)
		value += coeff[i] * pow(x, i);
	return value;
}