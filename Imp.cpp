#include "Date.h"

//Default constructor
Date::Date()
{
	month = 1;
	day = 1;
	year = 2000;
}

//Utility function checks that the class does not pass the limit for its variables
bool Date::limcheck(int m, int d, int y)
{
	if (m < 13 && m > 0 && d > 0 && d < 31 && y > 999 && y < 10000)
		return 0;
	else return 1;
}

//Overloaded Constructor
Date::Date(int m, int d, int y)
{
	if (limcheck(m, d, y) == 0)
	{
		month = m;
		day = d;
		year = y;
	}
	//Resets to Default Constructor Values
	else
	{
		month = 1;
		day = 1;
		year = 2000;
	}
}

//Overload Operator== checking two classes
bool Date::operator==(Date&d1)
{
	if (month == d1.month&&day == d1.day&&year == d1.year)
	{
		return 1;
	}
	return 0;
}

//Overload Operator+ adding to day
Date Date::operator+(int i)
{
	day = day + i;
	if (day > 30)
	{
		month = month + day / 30;
		day = day%30;
		if (month > 12)
		{
			year = year + month / 12;
			month = month % 12;
		}
	}
	return *this;
}

//Overload Operator= storing in day
void Date::operator=(Date&d1)
{
	day = d1.day;
	month = d1.month;
	year = d1.year;
}

//Overload Operator Postfix--
Date& Date::operator--()
{
	day = day - 1;
	if (day < 1)
	{
		day = 30;
		month = month - 1;
		if (month < 1)
		{
			month = 12;
			year = year - 1;
		}
	}
	return *this;
}

//Overload Operator --Prefix
Date Date::operator--(int)
{
	Date temp(month, day, year);
	--(*this);
	return temp;
}

//Overload Operator []
int& Date::operator[](const int index)
{
	if (index == 0)
		return day;
	else if (index == 1)
		return month;
	else if (index == 2)
		return year;
	else
		cout << "Index can only be 0,1 or 2\n";
	int i = 0;
	return i;
}

//Storing values of monthNames
string Date::monthNames[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };