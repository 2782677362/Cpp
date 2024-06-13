#include <iostream>
using namespace std;

////友元
//class Time {
//	friend class Date;//友元类，日期类中可以直接访问时间类中的私有对象
//public:
//	Time(int hour = 1, int minute = 1, int second = 1)
//		:_hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//	void Print()
//	{
//		cout << _hour << ":" << _minute << ":" << _second << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date {
//	friend ostream& operator<<(ostream& out, const Date& d);// 友元函数：函数声明前加friend
//	friend istream& operator>>(istream& in, Date& d);
//
//public:
//	Date(int year = 0,int month = 1,int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//	void f1()
//	{
//		_t._hour++;
//	}
//	void f2(Time& t)
//	{
//		t._hour++;
//		t._minute++;
//		t._second++;
//	}
//
//	//内部类,B天生就是Date的友元类
//	class B {
//	public:
//		B()
//		{}
//	private:
//		int _b1;
//		int _b2;
//	};
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "/" << d._month << "/" << d._day << endl;
//	return out;
//}
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//
//int main()
//{
//	Date d1(2024, 6, 13);
//	Date d2(2024, 6, 14);
//	cout << d1 << d2;
//	cin >> d1 >> d2;
//	cout << d1 << d2;
//
//	Time t1(10, 10, 10);
//	d1.f2(t1);
//	t1.Print(); // 11:11:11
//
//	return 0;
//}




//C++中的内存管理
int main()
{
	//C:
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int)*10);

	free(p1);
	free(p2);

	//C++:
	int* p3 = new int;        //动态申请一个int类型的空间
	int* p31 = new int(10);   //动态申请一个int类型的空间并初始化为10
	int* p4 = new int[10];    //动态申请10个int类型的空间

	delete p3;
	delete[] p4;

	return 0;
}
// malloc calloc realloc的区别？  
// malloc原型:void *malloc(unsigned int num_bytes);申请num_bytes大小空间
// calloc原型:void *calloc(size_t n, size_t size);申请n*size大小空间，并将空间全部初始化为0
// realloc原型:void realloc(void *ptr, size_t new_Size);对动态内存进行扩容,ptr为指向原来空间地址的指针,new_size为接下来需要扩充容量的大小。

// 既然已经有了malloc和free，那么new和delete有何意义？
// 对于内置类型(int,char,long...)效果一样
// 对于自定义类型，效果不一样：
// 在申请自定义类型的空间时，new申请空间+调用构造函数，delete调用析构函数+释放空间，而malloc与free不会调用构造函数和析构函数。
