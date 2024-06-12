#include <iostream>
using namespace std;

//class Date {
//public:
//	Date(int year = 0,int month = 1,int day =1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//
//	/*void f1()
//	{}
//	static void f2() // f2没有this指针，而调用f1时需要this指针，无法调用
//	{
//		f1();
//	}*/
//	//静态成员函数不可以调用非静态成员函数
//
//	static void f3()
//	{}
//	void f4() 
//	{
//		f3();
//	}
//	//非静态成员函数可以调用静态成员函数
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//
//	//d1.f2();
//	d1.f4();
//
//	return 0;
//}





//class A {
//public:
//	//void f1()//非静态函数由对象名.或者对象指针->调用
//	//{
//	//	_n++;
//	//}
//	//int RetN()
//	//{
//	//	return _n;
//	//}
//
//	static void f1()//静态成员函数则由类名::或者对象名.调用，没有this指针
//	{
//		_n++;
//	}
//	static int RetN()
//	{
//		return _n;
//	}
//private:
//	static int _n;
//};
//
//int A::_n = 0;
//
//int main()
//{
//	A::f1();
//	int ret = A::RetN();
//	cout << ret << endl;
//	return 0;
//}


class B
{
public:
	B(int q = 0)
		:_q(q)
		{}
private:
	int _q;
};

class A {

private:
	//声明时给缺省值(C++11语法)
	int _a = 1;
	int* _b = (int*)malloc(sizeof(int) * 5);
	B b1 = 10;
	//B b2(10); //错误
	//static int _n = 0; //错误，静态变量不能给缺省值
};