// Interface of RationalNum class...

#include<iostream>
#include<fstream>
using namespace std;
class RationalNum
{
private:
	int  numerator, denominator;
public:
	RationalNum();
	~RationalNum();
	void setRationlNum(int,int);
	void printRationalNum();
	void writeRationlNum();
	void simplifyNum();
	RationalNum operator+(RationalNum);
	RationalNum operator-(RationalNum);
	RationalNum operator*(RationalNum);
	RationalNum operator/(RationalNum);
};

