
#include "Time.h";

// Static variable defination...
int Time::count = 0;

// Function to validate the time values...
bool Time::validate(int h, int m, int s)
{
	if (h < 0 || m < 0 || s < 0)
		return false;
	else
		return true;
}

// constructer...
Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
	count++;
}

// Overloaded Constructor...
Time::Time(int a, int b, int c)
{
	if (validate(a, b, c))
	{
		hour = a;
		min = b;
		sec = c;
		while (sec >= 60)
		{
			min++;
			sec -= 60;
		}

		while (min >= 60)
		{
			hour++;
			min -= 60;
		}

		while (hour > 24)
			hour -= 24;
	}
	else
	{
		cout << "\n You can not enter  a negative value.\n Please enter the values again.\n";
		cin >> a >> b >> c;
		this->setTime(a, b, c);
	}
	count++;
}

// Copy Constructer...
Time::Time(Time &t)
{
	//cout << "Copy Constructer called...\n";
	hour = t.hour;
	min = t.min;
	sec = t.sec;
	count++;
}

// Function to find total number of objects created...
int Time::getNoOfObjects()
{
	return count;
}

// Member function for setting the time...
void Time::setTime(int h, int m, int s)
{
	if (validate(h, m, s))
	{
		hour = h;
		min = m;
		sec = s;
		while (sec >= 60)
		{
			min++;
			sec -= 60;
		}

		while (min >= 60)
		{
			hour++;
			min -= 60;
		}

		while (hour > 24)
			hour -= 24;
	}
	else
	{
		cout << "\n You can not enter  a negative value.\n Please enter the values again.\n";
		cin >> h >> m >> s;
		this->setTime(h, m, s);
	}

}

// Member function for printing the time...
void Time::printTime() const
{
	cout << "\n The time is given as  :   " << hour << ":" << min << ":" << sec << endl;
	//cout << endl << count;
}

// Function for changing the time...
void Time::nextTime(int secs)
{
	sec += secs;
	while (sec >= 60)
	{
		min++;
		sec -= 60;
	}

	while (min >= 60)
	{
		hour++;
		min -= 60;
	}

	while (hour > 24)
		hour -= 24;
}

/////////////////////////////////////////////////////////////
//********Operator Overloading starts from here************//

// assignment operator (=)
Time& Time::operator=(const Time &t)
{
	hour = t.hour;
	min = t.min;
	sec = t.sec;
	return *this;
}

// - operator
Time Time::operator-(const Time& t)const
{
	Time temp;
	temp.hour = hour - t.hour;
	temp.min = min - t.min;
	temp.sec = sec - t.min;
	if (temp.sec < 0)
	{
		temp.sec += 60;
		temp.min--;
	}
	if (temp.min < 0)
	{
		temp.min += 60;
		temp.hour--;
	}
	return temp;
}

// -= operator
void Time::operator-=(const Time &t)
{
	hour -= t.hour;
	min -= t.min;
	sec -= t.sec;
	if (sec < 0)
	{
		sec += 60;
		min--;
	}
	if (min < 0)
	{
		min += 60;
		hour--;
	}
}

// + operator
Time Time::operator+(const Time& t)const
{
	Time temp;
	temp.hour = hour + t.hour;
	temp.min = min + t.min;
	temp.sec = sec + t.min;
	if (temp.sec > 60)
	{
		temp.min += temp.sec / 60;
		temp.sec %= 60;
	}
	if (temp.min > 60)
	{
		temp.hour += temp.min / 60;
		temp.min %= 60;
	}
	if (hour > 24)
		temp.min %= 24;
	return temp;
}

// += operator
void Time::operator+=(const Time & t)
{
	hour += t.hour;
	min += t.min;
	sec += t.sec;
	if (sec > 60)
	{
		min += sec / 60;
		sec %= 60;
	}
	if (min > 60)
	{
		hour += min / 60;
		min %= 60;
	}
}

// ++ Operator (pre-increment)
Time& Time::operator++()
{
	hour++;
	min++;
	sec++;
	if (sec > 60)
	{
		sec -= 60;
		min++;
	}
	if (min > 60)
	{
		min -= 60;
		hour++;
	}
	return *this;
}

// -- Operator (pre-increment)
Time& Time::operator--()
{
	hour--;
	min--;
	sec--;
	if (sec < 0 )
	{
		sec += 60;
		min--;
	}
	if (min < 0 )
	{
		min -= 60;
		hour++;
	}
	if (hour < 0)
		hour += 24;
	return *this;
}

// ++ Operator (post-increment)
Time Time::operator++(int)
{
	Time temp = *this;
	hour++;
	min++;
	sec++;
	if (sec > 60)
	{
		sec -= 60;
		min++;
	}
	if (min > 60)
	{
		min -= 60;
		hour++;
	}
	return temp;
}

// -- Operator (post-increment)
Time Time::operator--(int)
{
	Time temp = *this;
	hour--;
	min--;
	sec--;
	if (sec < 0)
	{
		sec += 60;
		min--;
	}
	if (min < 0)
	{
		min -= 60;
		hour++;
	}
	if (hour < 0)
		hour += 24;
	return temp;
}

// == operator
bool Time::operator==(const Time& t) const
{
	return (hour - t.hour || min - t.min || sec - t.sec) ? false : true;
}

// != operator
bool Time::operator!=(const Time& t) const
{
	return (hour - t.hour || min - t.min || sec - t.sec) ? true : false;
}

/*bool Time::operator>(const Time &t) const
{
if (hour > t.hour)
return true;
else if (hour < t.hour)
return false;
else
{
if (min > t.min)
return true;
else if (min < t.min)
return false;
else
{
if (sec > t.sec)
return true;
}
}
return false;
}*/

// > operator
bool Time::operator>(const Time &t) const
{
	if (hour > t.hour)
		return true;
	else if (hour < t.hour)
		return false;
	else
	{
		if (min > t.min)
			return true;
		else if (min < t.min)
			return false;
		else
			return (sec > t.sec) ? true : false;
	}
}

// >= operator
bool Time::operator>=(const Time &t) const
{
	if (hour > t.hour)
		return true;
	else if (hour < t.hour)
		return false;
	else
	{
		if (min > t.min)
			return true;
		else if (min < t.min)
			return false;
		else
			return (sec < t.sec) ? false : true;
	}

}

// < operator
bool Time::operator<(const Time &t) const
{
	if (hour < t.hour)
		return true;
	else if (hour > t.hour)
		return false;
	else
	{
		if (min < t.min)
			return true;
		else if (min > t.min)
			return false;
		else
			return (sec < t.sec)?true: false;
	}

}

// <= operator
bool Time::operator<=(const Time &t) const
{
	if (hour < t.hour)
		return true;
	else if (hour > t.hour)
		return false;
	else
	{
		if (min < t.min)
			return true;
		else if (min > t.min)
			return false;
		else
			return (sec > t.sec) ? false : true;
	}
}

//////////////////////////////////////////////////////////////