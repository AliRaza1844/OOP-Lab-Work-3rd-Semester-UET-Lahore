#include "String.h"

// Default constructor...
String::String()
{
	a = nullptr;
	size = 0;
}

// Destructor...
String::~String()
{
	if (a != nullptr)
		delete[]a;
}

// Overloaded Constructor...
String::String(char *s)
{
	size = strlen(s)+1;
	a = new char[size];
	strcpy(a, s);
}

// Copy Constructor...
String::String(const String &str)
{
	size = str.size;
	a = new char[size];
	strcpy(a, str.a);
}

// Fuction to print the string...
void String::print()
{
	cout << a;
}

/////////////////////////////////////////////////////////////
//********Operator Overloading starts from here************//

// (=) assignment operator when assinging an object to the other object...
String& String::operator=(const String &str)
{
	size = str.size;
	if (a != nullptr)
		delete[]a;
	a = new char[size];
	strcpy(a, str.a);
	return *this;
}

// (=) assingment operator for assigning an charactor string to String object...
String & String::operator=(char *s)
{
	size = strlen(s) + 1;
	if (a != nullptr)
		delete[]a;
	a = new char[size];
	strcpy(a, s);
	return *this;
}

// + operator
String String::operator+(const String &s)const
{
	String temp;
	int x = strlen(this->a);
	int y = strlen(s.a);
	int j = 0, i = 0;
	if (s.a == NULL)						// Checking source string...
		return *this;
	else
	{
		if (this->a == NULL)					// Checking that Destination string is Null or not...
		{
			temp.size = strlen(s.a) + 1;
			temp.a = new char[temp.size];
			strcpy(temp.a , s.a);
		}
		else
		{
			temp.size = x + y + 2;
			 temp.a = new char[temp.size];
			for (; i < x + y + 1; i++)
			{
				if (i < x)
					temp.a[i] = a[i];
				else if (i == x)
					temp.a[i] = ' ';
				else
				{
					temp.a[i] = s.a[j];
					j++;
				}
			}
			temp.a[i] = '\0';
		}
	}
	return temp;
}

// == operator
bool String::operator==(const String & str) const
{
	if (a == NULL || str.a == NULL || strlen(a) != strlen(str.a))
		return false;
	else
	{
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] != str.a[i])
				return false;
		}
	}
	return true;
}

// != operator
bool String::operator!=(const String &str) const
{
	if (a == NULL || str.a == NULL || strlen(a) != strlen(str.a))
		return true;
	else
	{
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] != str.a[i])
				return true;
		}
	}
	return false;
}

// ! operator
bool String::operator!()
{
	return (a == NULL) ? true : false;
}

// < operator
bool String::operator<(const String &str) const
{
	int length = (strlen(a) < strlen(str.a)) ? strlen(str.a) + 1 : strlen(a);
	for (int i = 0; i < length; i++)
	{
		if (a[i] < str.a[i])
			return true;
		else if (a[i] > str.a[i])
			return false;
	}
	return false;
}

// > operator
bool String::operator>(const String &str) const
{
	int length = (strlen(a) < strlen(str.a)) ? strlen(str.a) + 1 : strlen(a);
	for (int i = 0; i < length; i++)
	{
		if (a[i] > str.a[i])
			return true;
		else if (a[i] < str.a[i])
			return false;
	}
	return false;
}

// >= operator
bool String::operator>=(const String &str) const
{
	int length = (strlen(a) < strlen(str.a)) ? strlen(str.a) : strlen(a);
	for (int i = 0; i < length; i++)
	{
		if (a[i] > str.a[i])
			return true;
		else if (a[i] < str.a[i])
			return false;
	}
	return true;
}

// <= operator
bool String::operator<=(const String &str) const
{
	int length = (strlen(a) < strlen(str.a)) ? strlen(str.a) + 1 : strlen(a);
	for (int i = 0; i < length; i++)
	{
		if (a[i] < str.a[i])
			return true;
		else if (a[i] > str.a[i])
			return false;
	}
	return true;
}

// [] operator
char String::operator[](unsigned int index)const
{
	if (index<0 || index>size - 1)
		return 0;
	else
		return a[index];
}

/////////////////////////////////////////////////////////////////