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
//malloc			      ==>  申请空间成功返回地址，失败返回NULL地址
//operator new			  ==>  申请空间成功返回地址，失败抛异常        (malloc+抛异常)
//new					  ==>  (operator new + 调构造函数)
//三者区别


//free					  
//operator delete		  ==>  前两者没区别
//delete			      ==>  (调析构函数 + free/operator delete)
//三者区别


//int main()
//{
//	A* p1 = new A(10);
//	delete p1;
//	
//	//模拟实现上面两行代码:
//	A* p2 = (A*)operator new(sizeof(A));
//	p2 = new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//
//	return 0;
//}



//模板
//1.函数模板
//template<typename T> //或者 template<class T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
// // 下面三次交换调用的是同一个函数吗：不是
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


//2.类模板
//C语言实现栈：
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

//C++实现栈：
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
	// C语言实现的栈的缺陷				 		C++应对方式
	// 1.容易忘记初始化和销毁            ->     构造函数+析构函数
	// 2.结构体中变量容易被非法修改      ->     类中的访问限定符
	// 3.同时实现两个不同类型的栈很难    ->     类模板
	ST st_c;
	st_c._top = 0; //容易非法修改

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