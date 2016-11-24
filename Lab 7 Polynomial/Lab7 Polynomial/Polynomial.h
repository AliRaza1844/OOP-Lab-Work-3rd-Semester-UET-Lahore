#pragma once
#include<iostream>
using namespace std;

class Polynomial
{
private:
	double *coeff;
	//int noOfCoeff;
	int degree;
	string doubleToString(double);
public:
	// Constructors...
	Polynomial();
	Polynomial(double*,int);
	
	// Copy Constructor...
	Polynomial(const Polynomial&);
	
	// Destructor...
	~Polynomial();

	// operator overloading...
	Polynomial& operator=(const Polynomial&);
	Polynomial operator+(const Polynomial&)const;
	Polynomial operator*(const Polynomial&)const;

	// Methods...
	int getDegree();
	char* toString();
	double evaluate(double x);
};

