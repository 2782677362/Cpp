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
//	static void f2() // f2û��thisָ�룬������f1ʱ��Ҫthisָ�룬�޷�����
//	{
//		f1();
//	}*/
//	//��̬��Ա���������Ե��÷Ǿ�̬��Ա����
//
//	static void f3()
//	{}
//	void f4() 
//	{
//		f3();
//	}
//	//�Ǿ�̬��Ա�������Ե��þ�̬��Ա����
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
//	//void f1()//�Ǿ�̬�����ɶ�����.���߶���ָ��->����
//	//{
//	//	_n++;
//	//}
//	//int RetN()
//	//{
//	//	return _n;
//	//}
//
//	static void f1()//��̬��Ա������������::���߶�����.���ã�û��thisָ��
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
	//����ʱ��ȱʡֵ(C++11�﷨)
	int _a = 1;
	int* _b = (int*)malloc(sizeof(int) * 5);
	B b1 = 10;
	//B b2(10); //����
	//static int _n = 0; //���󣬾�̬�������ܸ�ȱʡֵ
};