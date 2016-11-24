#include "Matrix.h"



Matrix::Matrix()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = 0;
}

Matrix::Matrix(Matrix &m)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = m.a[i][j];
}

void Matrix::setValue()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
}

void Matrix::print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << "   " << a[i][j];
		cout << endl;
	}
}

Matrix Matrix::transpose()
{
	Matrix temp;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp.a[i][j] = a[j][i];
	return temp;
}

/////////////////////////////////////////////////////////////
//********Operator Overloading starts from here************//

// (=) assingment operator overloading...
Matrix& Matrix::operator=(const Matrix &m)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] = m.a[i][j];
	return *this;
}

// + operator overloading
Matrix Matrix::operator+(const Matrix &m) const
{
	Matrix temp;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp.a[i][j] = a[i][j] + m.a[i][j];
	return temp;
}

// - operator overloading
Matrix Matrix::operator-(const Matrix &m) const
{
	Matrix temp;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp.a[i][j] = a[i][j] - m.a[i][j];
	return temp;
}

// * operator overloading
Matrix Matrix::operator*(const Matrix &m) const
{
	Matrix temp;
	// Matrix multiplication algorithm
	for (int i = 0; i<3; i++) 
		for (int k = 0; k<3; k++) 
			for (int j = 0; j<3; j++) 
				temp.a[i][k] += a[i][j] * m.a[j][k];
			
	return temp;
}

// == operator overloading
bool Matrix::operator==(const Matrix &m) const
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[i][j] != m.a[i][j])
				return false;
	return true;
}

// != operator overloading
bool Matrix::operator!=(const Matrix &m) const
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[i][j] != m.a[i][j])
				return true;
	return false;
}

// ! operator overloading
bool Matrix::operator!()
{
	int k=0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == j&&a[i][j] == 1)
				k++;
			if (i != j&&a[i][j] != 0)
				return false;
		}
	if (k == 3)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////