
#include<iostream>
using namespace std;

// Interface of Date class...
class Date
{
	// Private members...
private:
	int year, month, day;
	bool validate(int, int, int);

	// Public members...
public:
	Date();
	Date(int, int, int);
	Date(Date&);
	void setDate(int, int, int);
	void printDate()const;
	Date& operator=(const Date&);		// assignment operator (=) overloading
	Date& operator++();					// ++ operator overloading (pre-increment)...
	Date operator++(int);				// ++ operator overloading (post-increment)...
	Date& operator--();					// -- operator overloading (pre-decrement)...
	Date operator--(int);				// -- operator overloading (post-decrement)...
	Date operator-(const Date&)const;	// - operator overloading
	Date operator+(const Date&)const;	// + operator overloading
	void operator+=(const Date&);		// += operator overloadong
	void operator-=(const Date&);		// -= operator overloading
	bool operator==(const Date&)const;	// == operator overloading
	bool operator!=(const Date&)const;	// != operator overloading
	bool operator>(const Date&)const;	// > operator overloading
	bool operator<(const Date&)const;	// < operator overloading
	bool operator>=(const Date&)const;	// >= operator overloading
	bool operator<=(const Date&)const;	// <= operator overloading
};

