#include <iostream>
using namespace std;

//class A {
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = (A*)operator new(sizeof(A));
//	A* p3 = new A();
//
//	free(p1);
//	operator delete(p2);
//	delete p3;
//	return 0;
//}
//malloc			      ==>  ����ռ�ɹ����ص�ַ��ʧ�ܷ���NULL��ַ
//operator new			  ==>  ����ռ�ɹ����ص�ַ��ʧ�����쳣        (malloc+���쳣)
//new					  ==>  (operator new + �����캯��)
//��������


//free					  
//operator delete		  ==>  ǰ����û����
//delete			      ==>  (���������� + free/operator delete)
//��������


//int main()
//{
//	A* p1 = new A(10);
//	delete p1;
//	
//	//ģ��ʵ���������д���:
//	A* p2 = (A*)operator new(sizeof(A));
//	p2 = new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//
//	return 0;
//}



//ģ��
//1.����ģ��
//template<typename T> //���� template<class T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
// // �������ν������õ���ͬһ�������𣺲���
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	double c = 1.11, d = 2.22;
//	Swap(c, d);
//
//	char e = '1', f = '2';
//	Swap(e, f);
//
//	return 0;
//}


//2.��ģ��
//C����ʵ��ջ��
typedef int STDateType;
typedef struct Stack_C
{
	STDateType* _a;
	int _top;
	int _capacity;
}ST;

void StackInit_C(ST* st)
{}
void StackPush_C(ST* st,int val)
{}
STDateType StackPop_C(ST* st)
{}
void StackDestory_C(ST* st)
{}

//C++ʵ��ջ��
template<class T>
class Stack_Cpp
{
public:
	Stack_Cpp()
	{}
	~Stack_Cpp()
	{}
	void StackPush_Cpp(int x)
	{}
	T StackPop_Cpp()
	{}
private:
	T* _a;
	int _top;
	int _capacity;
};
int main()
{
	// C����ʵ�ֵ�ջ��ȱ��				 		C++Ӧ�Է�ʽ
	// 1.�������ǳ�ʼ��������            ->     ���캯��+��������
	// 2.�ṹ���б������ױ��Ƿ��޸�      ->     ���еķ����޶���
	// 3.ͬʱʵ��������ͬ���͵�ջ����    ->     ��ģ��
	ST st_c;
	st_c._top = 0; //���׷Ƿ��޸�

	StackInit_C(&st_c);

	StackPush_C(&st_c, 1);
	StackPush_C(&st_c, 2);
	int a = StackPop_C(&st_c);

	StackDestory_C(&st_c);


	Stack_Cpp<int> st_cpp_int;
	Stack_Cpp<double> st_cpp_double;
	st_cpp_int.StackPush_Cpp(1);
	st_cpp_int.StackPush_Cpp(2);
	int b = st_cpp_int.StackPop_Cpp();

	st_cpp_double.StackPush_Cpp(1.11);
	st_cpp_double.StackPush_Cpp(2.22);
	double c = st_cpp_double.StackPop_Cpp();

	return 0;
}