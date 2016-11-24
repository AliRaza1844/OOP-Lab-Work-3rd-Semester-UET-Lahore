#include "Date.h";

// Default Constructor...
Date::Date()
{
	year = month = day = 0;
}

// Overloaded Constructor...
Date::Date(int day, int month, int year)
{
	if (validate(year, month, day)==true)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
	else
	{
		cout << " You can not enter any negative or zero value.\n Please enter the date again without dashes.(d m y)\n ";
		cin >> day >> month >> year;
		this->setDate(day, month, year);
	}
}

// Fuction to validate Date...
bool Date::validate(int y, int m, int d)
{
	return (y < 1 || m < 1 || d < 1 ) ? false : true;
}

// Copy Constructor...
Date::Date(Date &d)
{
	year = d.year;
	month = d.month;
	day = d.month;
}

// Function to set Date values...
void Date::setDate(int day, int month, int year)
{
	if (validate(year, month, day)==true)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
	else
	{
		cout <<" You can not enter any negative or zero value.\n Please enter the date again without dashes.(d m y)\n ";
		cin >> day >> month >> year;
		this->setDate(day, month, year);
	}

}

// Function to print Date values...
void Date::printDate() const
{
	cout << day<<"-"<<month<<"-"<<year;
}

/////////////////////////////////////////////////////////////
//********Operator Overloading starts from here************//

// = Operator
Date& Date::operator=(const Date &d)
{
	year = d.year;
	month = d.month;
	day = d.day;
	return *this;
}

// ++ Operator (pre-increment)
Date& Date::operator++()
{
	day++;
	if (day > 30)
	{
		month++;
		day -= 30;
	}
	if (month > 12)
	{
		year++;
		month -= 12;
	}
	return *this;
}

//++ Operator (post-increment)
Date Date::operator++(int)
{
	Date temp = *this;
	day++;
	if (day > 30)
	{
		month++;
		day -= 30;
	}
	if (month > 12)
	{
		year++;
		month -= 12;
	}
	return temp;
}

// -- Operator (pre-increment)
Date& Date::operator--()
{
	day--;
	if (day < 1)
	{
		month--;
		day += 30;
	}
	if (month < 1)
	{
		year--;
		month += 12;
	}
	return *this;
}

// ++ Operator (post-increment)
Date Date::operator--(int)
{
	Date temp = *this;
	day--;
	if (day < 1)
	{
		month--;
		day += 30;
	}
	if (month < 1)
	{
		year--;
		month += 12;
	}
	return temp;
}

// + Operator 
Date Date::operator+(const Date &d) const
{
	Date temp;
	temp.year = year + d.year;
	temp.month = month + d.month;
	temp.day = day + d.day;
	if (temp.day > 30)
	{
		temp.month += temp.day / 30;
		temp.day %= 30;
	}
	if (temp.month > 12)
	{
		temp.year += temp.month / 12;
		temp.month %= 12;
	}
	return temp;
}

// - Operator
Date Date::operator-(const Date &d) const
{
	Date temp;
	if (*this<d)
	{
		temp.year = d.year - year;
		temp.month = d.month - month;
		temp.day = d.day - day;
	}
	else
	{
		temp.year = year - d.year;
		temp.month = month - d.month;
		temp.day = day - d.day;
	}
	if (temp.day < 0)
	{
		temp.month--;
		temp.day += 30;
	}
	if (temp.month < 0)
	{
		temp.year--;
		temp.month += 12;
	}
	return temp;
}

// -= Operator
void Date::operator-=(const Date &d)
{
	if (*this<d)
	{
		year = d.year - year;
		month = d.month - month;
		day = d.day - day;
	}
	else
	{
		year = year - d.year;
		month = month - d.month;
		day = day - d.day;
	}
	if (day < 0)
	{
		month--;
		day += 30;
	}
	if (month < 0)
	{
		year--;
		month += 12;
	}
}

// += Operator
void Date::operator+=(const Date &d)
{

	year = year + d.year;
	month = month + d.month;
	day = day + d.day;
	if (day > 30)
	{
		month += day / 30;
		day %= 30;
	}
	if (month > 12)
	{
		year += month / 12;
		month %= 12;
	}
}

// == Operator
bool Date::operator==(const Date &d) const
{
	return(year - d.year || month - d.month || day - d.day) ? false : true;
}

// != Operator
bool Date::operator!=(const Date &d) const
{
	return (year - d.year || month - d.month || day - d.day) ?true : false;
}

// > Operator
bool Date::operator>(const Date &d) const
{
	if (year > d.year)
		return true;
	else if (year < d.year)
		return false;
	else
	{
		if (month > d.month)
			return true;
		else if (month < d.month)
			return false;
		else
			return (day > d.day) ? true : false;
	}
}

// < Operator
bool Date::operator<(const Date &d) const
{
	if (year < d.year)
		return true;
	else if (year > d.year)
		return false;
	else
	{
		if (month < d.month)
			return true;
		else if (month > d.month)
			return false;
		else
			return (day < d.day) ? true : false;
	}
}

// >= Operator
bool Date::operator>=(const Date &d) const
{
	if (year > d.year)
		return true;
	else if (year < d.year)
		return false;
	else
	{
		if (month > d.month)
			return true;
		else if (month < d.month)
			return false;
		else
			return (day < d.day) ? false : true;
	}
}

// <= Operator
bool Date::operator<=(const Date &d) const
{
	if (year < d.year)
		return true;
	else if (year > d.year)
		return false;
	else
	{
		if (month < d.month)
			return true;
		else if (month > d.month)
			return false;
		else
			return (day > d.day) ? false : true;
	}
}

///////////////////////////////////////////////////////////