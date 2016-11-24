#include "ComplexNo.h"

// Constructor...
ComplexNo::ComplexNo()
{
	real = imaginary = 0.0;
}

// Destructor...
ComplexNo::~ComplexNo()
{
	cout << "\n Number deleted";
}

// To set the values...
void ComplexNo::setNo(float real, float imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

// To print the values...
void ComplexNo::printNo()
{
	if (imaginary < 0)
		cout << real << imaginary << "i";
	else
		cout << real << "+" << imaginary << "i";
}

// Adding complex numbers...
ComplexNo* ComplexNo::add(ComplexNo* c)
{
	ComplexNo* temp = new ComplexNo;
	temp->real = real + c->real;
	temp->imaginary = imaginary + c->imaginary;
	return temp;
}

// Subtracting complex numbers...
ComplexNo* ComplexNo::subtract(ComplexNo* c)
{
	ComplexNo* temp = new ComplexNo;
	temp->real = real - c->real;
	temp->imaginary = imaginary - c->imaginary;
	return temp;
}

// Multiplying complex numbers...
ComplexNo* ComplexNo::multiply(ComplexNo* c)
{
	ComplexNo* temp = new ComplexNo;
	temp->real = ((real * c->real) - (imaginary*c->imaginary));
	temp->imaginary = (real*c->imaginary)+(imaginary*c->real);
	return temp;

}

// Dividing complex numbers...
ComplexNo* ComplexNo::divide(ComplexNo* c)
{
	ComplexNo* temp = new ComplexNo;
	float denomirator = pow(c->real, 2) + pow(c->imaginary, 2);
	temp->real = ((real * c->real) + (imaginary*c->imaginary)) / denomirator;
	floor(temp->real);
	temp->imaginary = ((imaginary*c->real) - (real*c->imaginary)) / denomirator;
	return temp;
}

// Conjugate of a complex number...
void ComplexNo::conjugate()
{
	imaginary *= -1;
}