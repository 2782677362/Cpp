#include <iostream>
using namespace std;

//class Time {
//public:
//	Time(int hour,int minute,int second)
//		:_hour(hour)
//		,_minute(minute)
//		,_second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date {
//public:
//	/*Date(int year = 0, int month = 1, int day = 1) // 构造函数赋初值
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	Date(int year = 0, int month = 1, int day = 1 ,int a, int n) // 初始化列表赋初值 
//		:_t1(1,2,3) // 成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关
//		,_a(a)
//		,_n(n)
//	{
//		 以下成员变量可通过初始化列表赋值，也可如下赋值
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	一下三类成员，必须使用初始化列表赋初值
//	Time _t1;      //没有默认构造函数
//	int& _a;       //引用成员变量
//	const int _n;  //const成员变量
//};


//class Date 
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		{}
//	//explicit Date& operator=(const Date& d)    //用explicit修饰构造函数，将会禁止构造函数的隐式转换。
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 6, 11);
//	Date d2(d1);
//	Date d3 = d1;
//	Date d4 = 2024;//此处调用 Date& operator=(const Date& d) 函数时发生隐式类型转换：Date tmp = (Date)2024;
//	               //再将tmp传参给 Date& operator=(const Date& d) 函数
//				   //用explicit修饰构造函数，将会禁止构造函数的隐式转换。
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	d4.Print();
//
//	return 0;
//}


//实现一个类，计算程序中创建出了多少个类对象(一)
//class A
//{
//public:
//	A()
//	{
//		_n++;
//	}
//	A(const A& a)
//	{
//		_n++;
//	}
//	static int _n;  // 此时_n必须公有，主函数中才能输出_n的值
//};
//
//int A::_n = 0;
//
//void main()
//{
//	A a1;
//	A a2;
//	A a3 = a1;
//	cout << A::_n << endl;
//}

//实现一个类，计算程序中创建出了多少个类对象(二)
class A
{
public:
	A() { ++_scount; }
	A(const A& t) { ++_scount; }
	~A() { --_scount; }
	static int GetACount() { return _scount; }
private:
	static int _scount;  //此时_scount不必公有，可以通过在类中创建函数来获取_scount的值
};
int A::_scount = 0;
void main()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}