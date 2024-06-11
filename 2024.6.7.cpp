#include <iostream>

using namespace std;

#include <time.h>
struct A { int a[10000]; };

//void TestFunc1(A aa) {}
//
//void TestFunc2(A& aa) {}
//
//void main()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}


//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//
//void main()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
////传引用或返回引用可以提高效率



///函数传引用：
//void Swap(int* x, int* y)//传指针实现交换
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void Swap(int& x, int& y)//传引用实现交换
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 3;
//	int b = 5;
//
//	Swap(&a, &b);
//	cout << a << " " << b << endl;
//
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	
//	return 0;
//}




//函数返回引用：
//int add(int a, int b)//返回值
//{
//	int c = a + b;
//	return c;
//}

//int& add(int a, int b)//返回引用
//{
//	int c = a + b;
//	return c;
//}

//int& add(int a, int b)//返回引用，c为静态变量
//{
//	static int c = a + b;
//	return c;
//}

//int main()
//{
//	int& ret = add(3, 5);
//	cout << ret << endl;//这里正常打印8
//	add(7, 9);
//	
//	cout << ret << endl;//这里打印16
//	//原因:第一次调用add时，创建栈帧，ret对应空间处于此栈帧，add调用结束，此栈帧销毁，
//	//第二次用add时，再创建一个栈帧，该栈帧可能会与上一个add栈帧的空间重合，导致ret对应的空间值发生变化，所以再次打印ret会变化
//	//解决办法：在函数中，将要返回的值定义为静态变量，即 static int c = a + b;
//
//	return 0;
//}
//一般不返回引用，不安全(出了函数作用域，返回对象就销毁了)




//#define ADD(int x, int y) return x + y;
//#define ADD(x, y) return x + y;
//#define ADD(x, y) x + y;
//#define ADD(x, y) (x + y)
//#define ADD(x, y) (x) + (y)
//#define ADD(x, y) ((x) + (y));
//#define ADD(x, y) ((x) + (y))

// 宏的缺点
// 1、容易出错，语法细节多
// 2、不能调试



//内联函数：
//inline int Add(int x, int y)//函数前加 inline 的优点：不用建立栈帧，提高效率(函数会在被调用的时候展开，以空间换时间)
//{							//若函数中代码很长或者存在递归，那么不建议用inline
//	int c = x + y;			//inline对于编译器只是一种建议，当使用inline时，编译器会根据函数代码的长短以及是否递归来选择是否内联
//	return c;
//}
//
//int main()
//{
//	int ret1 = Add(1, 2);
//	
//	int ret2 = ADD(1, 2);
//
//	cout << ret1 << endl << ret2 << endl;
//
//	return 0;
//}




//auto：
int main()
{
	int a = 1;
	auto b = a;//b的类型与a相同，为int
	auto p1 = &a;//p1的类型为int *
	auto* p2 = &b;//p2的类型为int

	//范围for:
	int arr[] = {1,2,3,4,5};
	for (auto e : arr)//会遍历数组中每一个数
	{
		cout << e << endl;
	}

	return 0;
}
//auto不能作为函数形参的类型，也不能作为函数返回值的类型