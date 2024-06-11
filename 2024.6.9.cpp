#include <iostream>

using namespace std;


class Date {
public:
	Date(int year = 0, int month = 1, int day = 1)//与类名同名的函数为构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print();
	

private:
	int _year = 10;
	int _month = 10;
	int _day = 10;   //类中的变量可以缺省
};

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int main()
{
	Date d1(2024, 6, 9);
	d1.Print();
	Date d2;
	d2.Print();

	return 0;
}