#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date 
{
	static string monthNames[13];
	int day;
	int year;
	int month;

	//Utility function checks that the class does not pass the limit for its variables
	bool limcheck(int m, int d, int y);

	//friend function overloading <<
	friend ostream& operator<<(ostream& out, Date&d1)
	{
		out << monthNames[d1.month] << " " << d1.day << ", " << d1.year;
		return out;
	}

	//friend function overloading >>
	friend istream& operator>>(istream& in, Date&d1)
	{
		//With checkers
		cout << "Enter month: ";
		in >> d1.month;
		if (d1.month > 12 || d1.month < 1)
		{
			cout << "Out of limit (Enter again): ";
			in >> d1.month;
		}
		cout << "Enter day: ";
		in >> d1.day;
		if (d1.day > 30 || d1.month < 1)
		{
			cout << "Out of limit (Enter again): ";
			in >> d1.day;
		}
		cout << "Enter year: ";
		in >> d1.year;
		if (d1.year > 9999 || d1.year < 1000 )
		{
			cout << "Out of limit (Enter again): ";
			in >> d1.year;
		}
		return in;
	}
public:
	//Default Constructor
	Date();
	//Overload Constructor
	Date(int m, int d, int y);

	//Operator Overload Functions
	bool operator==(Date&d1);
	Date operator+(int i);
	void operator=(Date&d1);
	Date& operator--();
	Date operator--(int);
	int& operator[](const int index);
};
