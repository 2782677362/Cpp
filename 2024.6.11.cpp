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
//	/*Date(int year = 0, int month = 1, int day = 1) // ���캯������ֵ
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	Date(int year = 0, int month = 1, int day = 1 ,int a, int n) // ��ʼ���б���ֵ 
//		:_t1(1,2,3) // ��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�
//		,_a(a)
//		,_n(n)
//	{
//		 ���³�Ա������ͨ����ʼ���б�ֵ��Ҳ�����¸�ֵ
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	һ�������Ա������ʹ�ó�ʼ���б���ֵ
//	Time _t1;      //û��Ĭ�Ϲ��캯��
//	int& _a;       //���ó�Ա����
//	const int _n;  //const��Ա����
//};


//class Date 
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		{}
//	//explicit Date& operator=(const Date& d)    //��explicit���ι��캯���������ֹ���캯������ʽת����
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
//	Date d4 = 2024;//�˴����� Date& operator=(const Date& d) ����ʱ������ʽ����ת����Date tmp = (Date)2024;
//	               //�ٽ�tmp���θ� Date& operator=(const Date& d) ����
//				   //��explicit���ι��캯���������ֹ���캯������ʽת����
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	d4.Print();
//
//	return 0;
//}


//ʵ��һ���࣬��������д������˶��ٸ������(һ)
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
//	static int _n;  // ��ʱ_n���빫�У��������в������_n��ֵ
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

//ʵ��һ���࣬��������д������˶��ٸ������(��)
class A
{
public:
	A() { ++_scount; }
	A(const A& t) { ++_scount; }
	~A() { --_scount; }
	static int GetACount() { return _scount; }
private:
	static int _scount;  //��ʱ_scount���ع��У�����ͨ�������д�����������ȡ_scount��ֵ
};
int A::_scount = 0;
void main()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}