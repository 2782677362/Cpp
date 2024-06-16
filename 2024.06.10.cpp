#include <iostream>

using namespace std;

class Date {
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator==(const Date& d) const
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	bool operator<(const Date& d) const
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		else
			return false;
	}
	bool operator<=(const Date& d) const
	{
		return (*this == d) || (*this < d);
	}
	bool operator>(const Date& d) const
	{
		return !(*this <= d);
	}
	bool operator>=(const Date& d) const
	{
		return !(*this < d);
	}
	bool operator!=(const Date& d) const
	{
		return !(*this == d);
	}
	int GetMonthDay(int year, int month) const
	{
		int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			arr[1] = 29;
		}
		return arr[month - 1];
	}
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	Date operator+(int day) const
	{
		Date tmp = *this;
		tmp += day;
		return tmp;
	}
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
	Date operator-(int day) const
	{
		Date tmp = *this;
		tmp -= day;
		return tmp;
	}
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}
	int operator-(const Date& d) const
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this<d)
		{
			flag = -1;
			max = d;
			min = *this;
		}
		int day = 0;
		while (max != min)
		{
			max--;
			day++;
		}
		return day*flag;
	}
	const Date* operator&() const
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d0;
	Date d1(2024,6,10);
	Date d2(d1);
	Date d3 = d1;
	Date d4(2024,6,11);
	d0.Print();
	d1.Print();
	d2.Print();
	d3.Print();
	d4.Print();

	cout << (d1 == d2) << endl;
	cout << (d1.operator==(d4)) << endl;

	cout << (d1 < d4) << endl;
	cout << (d1 > d4) << endl;
	cout << (d1 == d4) << endl;
	cout << (d1 <= d4) << endl;
	cout << (d1 >= d4) << endl;
	cout << (d1 != d4) << endl;

	return 0;
}
