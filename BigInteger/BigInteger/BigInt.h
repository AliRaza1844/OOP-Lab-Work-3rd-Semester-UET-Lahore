// BigInt Class Interface...

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class BigInt
{
private:
	// Private data members...
		char* number;
		int size;
		bool sign;
	// Private methods...
		bool compare(const BigInt&)const;
		char* add(const BigInt&)const;
		char* subtract(const BigInt&)const;
		BigInt multiply(char, int) const;
		BigInt& eliminateZerosAtTheStart();
		bool validate(char*);
		bool validate(string&);

public:
	// Constructor Overloading...
		BigInt();
		BigInt(char*);
		BigInt(char*, bool);
		BigInt(int);

	// Copy Constructor...
		BigInt(const BigInt&);

	// Destructor...
		~BigInt();

	// Methods (Getters and setters)...
		void setNumber(char*);
		const char* getNumber()const;
		void setSign(bool);
		const bool& getSign()const;

	// Utility Methods...
		BigInt absolute();
		void printNumber();
		
	//************Operator overloading************//

		// Assignment Operator
			BigInt& operator=(const BigInt&);

		// Comparison Operators...
			bool operator==(const BigInt&)const;
			bool operator!=(const BigInt&)const;
			bool operator>(const BigInt&)const;
			bool operator<(const BigInt&)const;
			bool operator>=(const BigInt&)const;
			bool operator<=(const BigInt&)const;

		// Unary Operators...
			BigInt& operator++();	// pre increment...
			BigInt operator++(int);	// post increment...
			BigInt& operator--();	// pre increment...
			BigInt operator--(int);	// post increment...
			bool operator!();

		// Binary Operators...
			BigInt operator+(const BigInt&)const;
			BigInt operator-(const BigInt&)const;
			BigInt operator*(const BigInt&)const;
			BigInt operator/(const BigInt&)const;
			BigInt operator%(const BigInt&)const;
			BigInt& operator+=(const BigInt&);
			BigInt& operator-=(const BigInt&);
			BigInt& operator*=(const BigInt&);
			BigInt& operator/=(const BigInt&);
			BigInt& operator%=(const BigInt&);

		// Operator Overloading by friend functions
			friend istream& operator >> (istream&, BigInt&);		// Extraction operator...
			friend ostream& operator << (ostream&, BigInt&);		// Insertion operator...	
			friend BigInt operator-(BigInt&);						// Negative of a Number...
};

