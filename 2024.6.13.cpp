#include <iostream>
using namespace std;

////��Ԫ
//class Time {
//	friend class Date;//��Ԫ�࣬�������п���ֱ�ӷ���ʱ�����е�˽�ж���
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
//	friend ostream& operator<<(ostream& out, const Date& d);// ��Ԫ��������������ǰ��friend
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
//	//�ڲ���,B��������Date����Ԫ��
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




//C++�е��ڴ����
int main()
{
	//C:
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int)*10);

	free(p1);
	free(p2);

	//C++:
	int* p3 = new int;        //��̬����һ��int���͵Ŀռ�
	int* p31 = new int(10);   //��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
	int* p4 = new int[10];    //��̬����10��int���͵Ŀռ�

	delete p3;
	delete[] p4;

	return 0;
}
// malloc calloc realloc������  
// mallocԭ��:void *malloc(unsigned int num_bytes);����num_bytes��С�ռ�
// callocԭ��:void *calloc(size_t n, size_t size);����n*size��С�ռ䣬�����ռ�ȫ����ʼ��Ϊ0
// reallocԭ��:void realloc(void *ptr, size_t new_Size);�Զ�̬�ڴ��������,ptrΪָ��ԭ���ռ��ַ��ָ��,new_sizeΪ��������Ҫ���������Ĵ�С��

// ��Ȼ�Ѿ�����malloc��free����ônew��delete�к����壿
// ������������(int,char,long...)Ч��һ��
// �����Զ������ͣ�Ч����һ����
// �������Զ������͵Ŀռ�ʱ��new����ռ�+���ù��캯����delete������������+�ͷſռ䣬��malloc��free������ù��캯��������������
