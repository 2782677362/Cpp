#include <iostream>

using namespace std;


//函数名前面加 extern "C" 可以让函数按照C语言的方式汇编，这样C程序和C++程序都能调用此函数
extern "C" int add(int x, int y)
{
	return x + y;
}



int main()
{
	//引用
	int a = 2;
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = ra2;
	//此时,a、ra1、ra2、ra3都表示同一个地址，四者相当于同一个空间的别名

	const int i = 1;
	//int& ri = i;//编译不通过，因为i是可读可写的，而ri为只读，给变量取别名时，变量的访问权限不能放大，但可以缩小
	const int& ri = i;//这样是可以的，因为i为只读，ri也是只读

	int j = 0;
	const int& rj = j;//可行，j为可读可写，rj为只读，变量的访问权限缩小

	int d = 3;
	double db = d;//这里发生隐式类型转换:先将d转换为一个只读double类型的变量，再将此转换后的变量赋值给db
	//double& rd = d;//编译不通过，因为此时d转换为一个只读的double类型的变量，而rd为可读可写，访问权限放大
	//long& rd1 = d;//编译不通过，理由同上。   值得注意的是：编译不通过与类型的长度是否相等无关

	const double& rd2 = d;//可以
	const long& rd2 = d; //可以

	return 0;
}
