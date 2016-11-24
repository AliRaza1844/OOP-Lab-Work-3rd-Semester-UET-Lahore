// Complex number class interface...

#include<iostream>
#include<cmath>
using namespace std;
class ComplexNo
{
private:
	float real, imaginary;
public:
	ComplexNo();
	~ComplexNo();
	void setNo(float,float);
	void printNo();
	ComplexNo* add(ComplexNo*);
	ComplexNo* subtract(ComplexNo*);
	ComplexNo* multiply(ComplexNo*);
	ComplexNo* divide(ComplexNo*);
	void conjugate();
};

