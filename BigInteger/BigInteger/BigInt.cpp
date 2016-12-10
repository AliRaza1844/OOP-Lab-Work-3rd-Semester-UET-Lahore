// BigInt class Implementation...

#include "BigInt.h"

/////////////////////////////////////////////////////////////
//************* Private Methods****************************//

	// Function to compare two Objects...
	bool BigInt::compare(const BigInt& Int)const
	{
		if (size > Int.size)
			return true;
		else if (size < Int.size)
			return false;
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (number[i] > Int.number[i])
					return true;
				else if (number[i] < Int.number[i])
					return false;
			}
		}
		return true;
	}
	// Function to add two Objects...
	char * BigInt::add(const BigInt& Int)const
	{
		int i = size;
		char* temp = new char[i + 2];
		int d = i - Int.size;


		int carry = 0;
		while (i > d)
		{
			temp[i] = number[i - 1] + Int.number[i - d - 1] + carry;
			if (temp[i] > 9)
			{
				carry = temp[i] / 10;
				temp[i] %= 10;
			}
			else
				carry = 0;
			i--;
		}
		while (i > 0)
		{
			temp[i] = number[i - 1] + carry;
			if (temp[i] > 9)
			{
				carry = temp[i] / 10;
				temp[i] %= 10;
			}
			else
				carry = 0;
			i--;
		}
		temp[i] = carry;
		temp[size + 1] = '\0';
		return temp;
	}
	// Function to subtract two Objects...
	char * BigInt::subtract(const BigInt& Int)const
	{

		char* temp = new char[size + 1];
		int d = size - Int.size;

		int i = size - 1;
		int borrow = 0;
		while (i >= d)
		{
			temp[i] = number[i] - Int.number[i - d] - borrow;
			if (temp[i] < 0)
			{
				borrow = 1;
				temp[i] += 10;
			}
			else
				borrow = 0;
			i--;
		}
		while (i >= 0)
		{
			temp[i] = number[i] - borrow;
			if (temp[i] < 0)
			{
				borrow = 1;
				temp[i] += 10;
			}
			else
				borrow = 0;
			i--;
		}
		temp[size] = '\0';
		return temp;
	}
	// Function to Multiply two Objects...
	BigInt BigInt::multiply(char x, int i) const
	{
		BigInt temp;
		temp.size = size + 1 + i;
		temp.number = new char[size + 2 + i];
		temp.number[size + 1 + i] = '\0';
		int j = size + i;
		while (i > 0)
		{
			temp.number[j] = 0;
			j--;
			i--;
		}
		int carry = 0;
		while (j > 0)
		{
			temp.number[j] = number[j - 1] * x + carry;
			if (temp.number[j] > 9)
			{
				carry = temp.number[j] / 10;
				temp.number[j] %= 10;
			}
			else
				carry = 0;
			j--;
		}
		temp.number[j] = carry;
		return temp;
	}
	// Function to check if the object is zero...
	BigInt& BigInt::eliminateZerosAtTheStart()
	{
		if (number != NULL)
		{
			
			int i = 0;
			while (number[i] == 0 && i<size)
				i++;
			if (i == size)
			{
				size = 1;
			}
			else if(i!=0)
			{
				char* temp = new char[size + 1];
				int k = 0;
				while (i < size)
					temp[k++] = number[i++];
				temp[k] = '\0';
				delete[] number;
				size = k;
				number = new char[k + 1];
				for (int j = 0; j <= k; j++)
					number[j] = temp[j];
				delete[]temp;
			}
		}
		return *this;
}
	// Function to validate values...
	bool BigInt::validate(char *str)
	{
		int length = strlen(str);
		for (int i = 0; i < length; i++)
			if ((str[i] < 48 || str[i]>57) && str[i] != 45)
				return false;
		return true;
	}
	// Function to validate values...
	bool BigInt::validate(string & str)
	{
		int length = str.length();
		for (int i = 0; i < length; i++)
			if ((str[i] < 48 || str[i]>57) && str[i] != 45 && str[i] != 43)
				return false;
		return true;
	}

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//******************* Public Methods ************************//

	// Default Contrustor... 
	BigInt::BigInt()
	{
		number = NULL;
		sign = true;
		size = 0;
	}
	// String Constructor...
	BigInt::BigInt(char *str)
	{
		bool b = validate(str);
		while (b != true)
		{
			cout << "Your input is not valid. Only digits are allowed. Please enter the number again.\n";
			cin >> str;
			b = validate(str);
		}
		size = strlen(str);
		number = new char[size+1];
		for (int i = 0; i < size; i++)
			number[i] = str[i]-48;
		number[size] = '\0';
		sign = true;
		this->eliminateZerosAtTheStart();
	}
	// String Constructor...
	BigInt::BigInt(char *str, bool s)
	{
		bool b = validate(str);
		while (b != true)
		{
			cout << "Your input is not valid. Only digits are allowed. Please enter the number again.\n";
			cin >> str;
			b = validate(str);
		}
		sign = s;
		size = strlen(str);
		number = new char[size + 1];
		for (int i = 0; i < size; i++)
			number[i] = str[i]-48;
		number[size] = '\0';
		this->eliminateZerosAtTheStart();
	}
	// Integer Constructor...
	BigInt::BigInt(int x)
	{
		// Checking the sign of the integer...
			if (x < 0)
				{
					sign = false;
					x *= -1;
				}
			else
				sign = true;

		// Finding the length of the integer...
			int n = sizeof(x)/4;
			size = n;

		// Converting an integer to a charator array...
			number = new char[size+1];
			for (int i = size - 1; i >= 0; i--)
			{
				number[i] = x % 10;
				x /= 10;
			}
			number[size] = '\0';
		this->eliminateZerosAtTheStart();
	}
	// Copy Constructor...
	BigInt::BigInt(const BigInt &I)
	{
		size = I.size;
		sign = I.sign;
		number = new char[size + 1];
		for (int i = 0; i <= size; i++)
			number[i] = I.number[i];
	}
	// Destructor...
	BigInt::~BigInt()
	{
		if (number != NULL)
			delete[]number;
	}
	// Function to get number...
	const char * BigInt::getNumber() const
	{
			char* temp = new char[size + 1];
			int i = 0;
			
			// Loop to convert Number string into a character string...
			while (i < size)
				temp[i++] = number[i] + 48;
			temp[size] = '\0'; // Terminating the string...
			return temp;
	}
	// Function to get sign...
	const bool & BigInt::getSign() const
	{
		return sign;
	}
	// Function to set Number...
	void BigInt::setNumber(char *number)
	{
		// Checking if the number is NULL...
		if (this->number != NULL)
			delete[]this->number;

		size = strlen(number);
		this->number = new char[size + 1];
		for (int i = 0; i <= size; i++)
			this->number[i] = number[i]-48;
		this->eliminateZerosAtTheStart();
	}
	// Function to set sign...
	void BigInt::setSign(bool sign)
	{
		this->sign = sign;
	}
	// Function to get absolute value of a number...
	BigInt BigInt::absolute()
	{ 
		BigInt temp;
		temp = *this;
		if (temp.sign == false)temp.sign = true;
		return temp;
	}
	// Function to Print a number...
	void BigInt::printNumber()
	{
		if (sign == true)
			cout << this->getNumber();
		else
			cout << "-" << this->getNumber();
	}

/////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////
//********************Operator Overloading*********************//

	// Assingment operator (=)...
	BigInt & BigInt::operator=(const BigInt& Int)
	{
		this->eliminateZerosAtTheStart();
		this->sign = Int.sign;
		this->size = Int.size;
		if (this->number != NULL)
			delete[]this->number;
		this->number = new char[size + 1];
		for (int i = 0; i <= Int.size; i++)
			this->number[i] = Int.number[i];
		return *this;
	}
	// Checking equality of two number...
	bool BigInt::operator==(const BigInt& Int) const
	{
		if (this->size != Int.size || this->sign != Int.sign)
			return false;
		else
		{
			for (int i = 0; i < this->size; i++)
				if (this->number[i] != Int.number[i])
					return false;
		}
		return true;
	}
	// Unequality checking...
	bool BigInt::operator!=(const BigInt& Int) const
	{
		if (*this == Int)
			return false;
		else
			return true;
	}
	// (>) Greater than operator overloading....
	bool BigInt::operator>(const BigInt& Int) const
	{
		
		if (sign == true && Int.sign == false)
			return true;
		else if (sign == false && Int.sign == true)
			return false;
		else if ((sign == true && this->compare(Int) && (*this != Int)) || (sign == false && !(this->compare(Int))))
			return true;
		else
			return false;

	}
	// (<) Less than operator overloading...
	bool BigInt::operator<(const BigInt& Int) const
	{
		if (*this == Int || *this > Int)
			return false;
		else
			return true;
	}
	// (>=) Greater than or equal to operator overloading...
	bool BigInt::operator>=(const BigInt& Int) const
	{
		if (*this < Int)
			return false;
		else
			return true;
	}
	// (<=) Less than or equal to operator overloading...
	bool BigInt::operator<=(const BigInt& Int) const
	{
		if (*this > Int)
			return false;
		else
			return true;
	}
	// (++) pre increment operator overloading...
	BigInt & BigInt::operator++()
	{
		BigInt temp("1");
		*this += temp;
		//this->eliminateZerosAtTheStart();
		return *this;
	}
	// (++) post increment operator overloading...
	BigInt BigInt::operator++(int)
	{
		BigInt temp = *this;
		++(*this);
		//this->eliminateZerosAtTheStart();
		return temp;
	}
	// (--) pre decrement operator overloading...
	BigInt & BigInt::operator--()
	{
		BigInt temp(1);
		*this -= temp;
		//this->eliminateZerosAtTheStart();
		return *this;
	}
	// (--) post decrement operator overloading...
	BigInt BigInt::operator--(int)
	{
		BigInt temp = *this;
		--(*this);
		//this->eliminateZerosAtTheStart();
		return temp;
	}
	// (!) Not operator checks if the object is zero or not...
	bool BigInt::operator!()
	{
		if (*this == BigInt(0))
			return false;
		else
			return true;
	}
	// (+) Addition of two numbers...
	BigInt BigInt::operator+(const BigInt& Int)const
	{
		BigInt temp;
		// If Both the numbers have same signs...
		if (sign == Int.sign)
		{
			temp.sign = sign;
			if (size >= Int.size)
			{
				temp.size = size + 1;
				temp.number = this->add(Int);
			}
			else
			{
				temp.number = Int.add(*this);
				temp.size = Int.size + 1;
			}
		}
		// If both numbers have differnt signs...
		else
		{
			bool s;
			s = this->compare(Int);

			if (s == true)
			{
				temp.number = this->subtract(Int);
				temp.sign = sign;
				temp.size = size;
			}
			else
			{
				temp.size = Int.size;
				temp.sign = Int.sign;
				temp.number = Int.subtract(*this);
			}
		}
		temp.eliminateZerosAtTheStart();
		return temp;
	}
	// (-) Subtraction of two numbers...
	BigInt BigInt::operator-(const BigInt &Int) const
	{
		BigInt temp;
		// if signs are different...
		if (sign != Int.sign)
		{
			temp.sign = sign;
			if (size >= Int.size)
			{
				temp.size = size + 1;
				temp.number = this->add(Int);
			}
			else
			{
				temp.number = Int.add(*this);
				temp.size = Int.size + 1;
			}
		}
		// if signs are same...
		else
		{
			bool s;
			s = this->compare(Int);

			if (s == true)
			{
				temp.number = this->subtract(Int);
				temp.sign = sign;
				temp.size = size;
			}
			else
			{
				temp.size = Int.size;
				temp.sign = (Int.sign == true) ? false : true;
				temp.number = Int.subtract(*this);
			}
		}
		temp.eliminateZerosAtTheStart();
		return temp;
	}
	// (*) Multiplication operator...
	BigInt BigInt::operator*(const BigInt &Int) const
	{
		BigInt temp,check(0);
		// If any of the numbers or both are zero the result is zero...
		if (*this == check || Int == check)
			return check;
		if (sign != Int.sign)
			temp.sign = false;
		else temp.sign = true;

		if (size >= Int.size)
		{
			for (int i = 0; i < Int.size; i++)
				temp += (this->multiply(Int.number[Int.size - i - 1], i));
		}
		if (size < Int.size)
		{
			for (int i = 0; i < size; i++)
				temp += (Int.multiply(this->number[size - i - 1], i));
		}
		return temp;
	}
	// (/) Devision operator...
	BigInt BigInt::operator/(const BigInt &Int) const
	{
		// If the second object is zero the result is undefined...
		if (Int == BigInt(0))
			return BigInt(" \aEven Einstien was unable to divide any number by zero.");
		// If First object is smaller than second or zero...
		else if (!(this->compare(Int)) || *this== BigInt(0))
			return BigInt(0);
		// If both objects are equal the result is 1...
		else if (*this == Int)
			return BigInt(1);
		else if(size==Int.size)			// if devisor and devident have same sizes...
			{
				int i = 1;
				BigInt temp;
				temp = Int.multiply(i + 1, 0);
				temp.eliminateZerosAtTheStart();
				while (temp <= *this)
				{
					i++;
					temp += Int;
					temp.eliminateZerosAtTheStart();
				}
				if (sign == Int.sign)
					return BigInt(i);
				else
					return BigInt(-i);
			}
		else
			{
				

				BigInt result, temp, devisor, remainder(0), DND;
				result.number = new char[size + 1];
				DND.number = new char[Int.size + 2];
				temp=(*this);
				devisor = Int;
				temp.sign = devisor.sign = true;
				
				if (sign == Int.sign)
					result.sign = true;
				else
					result.sign = false;

				int k = 0,count=0;

				while (temp.compare(devisor))
				{
					DND.number[0] = '\0';
					DND.size = 0;
					int i=0;
					if (k == 0)
					{
						DND.size = devisor.size;
						for (; i < devisor.size; i++)
						{
							DND.number[i] = temp.number[0];
							DND.number[i + 1] = '\0';
							temp.number++;
							count++;
							temp.size--;
						}
					}
					else if (remainder != BigInt(0))
					{
						DND.size = remainder.size;
						for (; i < remainder.size; i++)
						{
							DND.number[i] = temp.number[0];
							DND.number[i + 1] = '\0';
							temp.number++;
							count++;
							temp.size--;
						}
					}
					if (DND < devisor)
					{
						DND.number[i] = temp.number[0];
						DND.number[i + 1] = '\0';
						DND.size++;
						temp.number++;
						count++;
						temp.size--;
						i++;
					}
					while (DND < devisor)
					{
						DND.number[i] = temp.number[0];
						DND.number[i + 1] = '\0';
						DND.size++;
						temp.number++;
						count++;
						temp.size--;
						result.number[k++] = 0;
						i++;
					}
					int j = 1;
					while ((devisor.multiply(j + 1, 0)).eliminateZerosAtTheStart() <= DND)
						j++;

					result.number[k++] = j;
					remainder = DND - (devisor.multiply(j, 0)).eliminateZerosAtTheStart();
					remainder.eliminateZerosAtTheStart();
					if (remainder == BigInt(0) && temp < devisor)
					{
						for (int i = 0; i < temp.size; i++)
							result.number[k++] = 0;
					}
					if (remainder != BigInt(0))
					{
						for (int n = remainder.size - 1; n >= 0; n--)
						{
							temp.number--;
							count--;
							temp.size++;
							temp.number[0] = remainder.number[n];
						}
						if (temp < devisor&&remainder != temp)
							result.number[k++] = 0;
					}
					//cout << result.number[k - 1]+48;
				}
				temp.number -= count;
				result.size = k;
				result.number[k] = '\0';
				
				return result;
			}
	}
	// (%) Remainder Operator...
	BigInt BigInt::operator%(const BigInt & Int) const
	{
		BigInt zero(0);
		// If the second object is zero the result is undefined...
		if (Int == zero)
			return BigInt(" \aEven Newton was unable to find remainder of any number with zero.");
		// if both objects are equal or the first object is zero the remainder is zero...
		else if (*this == zero || *this == Int)
			return zero;
		// if first number is smaller than second number the remainder is the first number...
		else if (!(this->compare(Int)))
			return *this;
		else if (size == Int.size)			// if devisor and devident have same sizes...
		{
			int i = 1;
			BigInt temp,remainder;
			temp = Int.multiply(i + 1, 0);
			temp.eliminateZerosAtTheStart();
			while (temp <= *this)
			{
				i++;
				temp += Int;
				temp.eliminateZerosAtTheStart();
			}
			remainder = *this - temp;
			return remainder;
		}
		else
		{
			BigInt temp, remainder(0), DND;
			//result.number = new char[size + 1];
			temp = (*this);
			DND.number = new char[Int.size + 2];

			int k = 0, count = 0;

			while (temp >= Int)
			{
				DND.number[0] = '\0';
				DND.size = 0;
				int i = 0;
				if (k == 0)
				{
					DND.size = Int.size;
					for (; i < Int.size; i++)
					{
						DND.number[i] = temp.number[0];
						DND.number[i + 1] = '\0';
						temp.number++;
						count++;
						temp.size--;
					}
				}
				else if (remainder != zero)
				{
					DND.size = remainder.size;
					for (; i < remainder.size; i++)
					{
						DND.number[i] = temp.number[0];
						DND.number[i + 1] = '\0';
						temp.number++;
						count++;
						temp.size--;
					}
				}
				if (DND < Int)
				{
					DND.number[i] = temp.number[0];
					DND.number[i + 1] = '\0';
					DND.size++;
					temp.number++;
					count++;
					temp.size--;
					i++;
				}
				while (DND < Int)
				{
					DND.number[i] = temp.number[0];
					DND.number[i + 1] = '\0';
					DND.size++;
					temp.number++;
					count++;
					temp.size--;
					//result.number[k++] = 0;
					i++;
				}
				int j = 1;
				while ((Int.multiply(j + 1, 0)).eliminateZerosAtTheStart() <= DND)
					j++;

				//result.number[k++] = j;
				remainder = DND - (Int.multiply(j, 0)).eliminateZerosAtTheStart();
				remainder.eliminateZerosAtTheStart();
				if (remainder == zero && temp < Int)
				{
					if (remainder != NULL)
						delete[]remainder.number;
					remainder.number = new char[temp.size + 1];
					remainder.size = temp.size;
					
					for (int i = 0; i < temp.size; i++)
					{
						//result.number[k++] = 0;
						remainder.number[i] = temp.number[i];
					}
					remainder.number[temp.size] = '\0';
				}
				if (remainder != zero)
				{
					for (int n = remainder.size - 1; n >= 0; n--)
					{
						temp.number--;
						count--;
						temp.size++;
						temp.number[0] = remainder.number[n];
					}
					if (temp < Int)
					{
						remainder.size = temp.size;
						for (int i = 0; i < temp.size; i++)
						{
							remainder.number[i] = temp.number[i];
						}
						remainder.number[temp.size] = '\0';
						//remainder = temp;
					}
				}
			}
			temp.number -= count;
			//result.size = k;
			//result.number[k] = '\0';
			remainder.sign = sign;
			return remainder;
		}
	}
	// (+=) Addition plus Assignment operator...
	BigInt & BigInt::operator+=(const BigInt & Int)
	{
		*this = *this + Int;
		return *this;
	}
	// (-=) Subtraction plus Assignment operator...
	BigInt & BigInt::operator-=(const BigInt & Int)
	{
		*this = *this - Int;
		return *this;
	}
	// (*=) Multiplication plus Assignment operator...
	BigInt & BigInt::operator*=(const BigInt & Int)
	{
		*this = *this * Int;
		return *this;
	}
	// (/=) Devision plus Assignment operator...
	BigInt & BigInt::operator/=(const BigInt & Int)
	{
		*this = *this / Int;
		return *this;
	}
	// (%=) Remainder plus Assignment operator...
	BigInt & BigInt::operator%=(const BigInt & Int)
	{
		*this = *this % Int;
		return *this;
	}

/////////////////////////////////////////////////////////////////

// Friend Functions
	// String extraction operator...
	istream & operator >> (istream & input, BigInt & Int)
	{
		string str;
		input >> str;
		bool b = Int.validate(str);
		// Checking that the string contains only digits and signs...
		while (b != true)	// Loop continues untill the user enters a valid value...
		{
			cout << "Your input is not valid. Only digits are allowed. Please enter the number again.\n";
			cin >> str;
			b = Int.validate(str);
		}
		// Finding the size of the string...
		int size = str.length();
		// Checking if the Int.number is NULL or not...
		if (Int.number != NULL)
			delete[] Int.number;

		// Reading values from string to the object...
		int i = 0;
		if (str[i] == 45)
		{
			Int.sign = false;
			Int.size = size-1;
			Int.number = new char[size];
			i++;
			for (; i < size; i++)
				Int.number[i-1] = str[i] - 48;
		}
		else
		{
			Int.size = size;
			Int.sign = true;
			Int.number = new char[size+1];

			for (; i < size; i++)
				Int.number[i] = str[i] - 48;
		}
		// Terminating the string by adding \0 at the end...
		Int.number[Int.size] = '\0';
		// Eliminating Zeroes from the start if any...
		Int.eliminateZerosAtTheStart();
		
		return input;
	}
	// String insertion opearator...
	ostream & operator<<(ostream & out, BigInt & Int)
	{
		if (Int.sign == true)
			cout << Int.getNumber();
		else
			cout << "-" << Int.getNumber();
		return out;
	}
	// Negative Of a number...
	BigInt operator-(BigInt & Int)
	{
		BigInt temp(Int);
		if (Int.sign == false)
			temp.sign = true;
		else
			temp.sign = false;
		return temp;
	}