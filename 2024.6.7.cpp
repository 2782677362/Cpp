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
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}


//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//
//void main()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
////�����û򷵻����ÿ������Ч��



///���������ã�
//void Swap(int* x, int* y)//��ָ��ʵ�ֽ���
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void Swap(int& x, int& y)//������ʵ�ֽ���
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




//�����������ã�
//int add(int a, int b)//����ֵ
//{
//	int c = a + b;
//	return c;
//}

//int& add(int a, int b)//��������
//{
//	int c = a + b;
//	return c;
//}

//int& add(int a, int b)//�������ã�cΪ��̬����
//{
//	static int c = a + b;
//	return c;
//}

//int main()
//{
//	int& ret = add(3, 5);
//	cout << ret << endl;//����������ӡ8
//	add(7, 9);
//	
//	cout << ret << endl;//�����ӡ16
//	//ԭ��:��һ�ε���addʱ������ջ֡��ret��Ӧ�ռ䴦�ڴ�ջ֡��add���ý�������ջ֡���٣�
//	//�ڶ�����addʱ���ٴ���һ��ջ֡����ջ֡���ܻ�����һ��addջ֡�Ŀռ��غϣ�����ret��Ӧ�Ŀռ�ֵ�����仯�������ٴδ�ӡret��仯
//	//����취���ں����У���Ҫ���ص�ֵ����Ϊ��̬�������� static int c = a + b;
//
//	return 0;
//}
//һ�㲻�������ã�����ȫ(���˺��������򣬷��ض����������)




//#define ADD(int x, int y) return x + y;
//#define ADD(x, y) return x + y;
//#define ADD(x, y) x + y;
//#define ADD(x, y) (x + y)
//#define ADD(x, y) (x) + (y)
//#define ADD(x, y) ((x) + (y));
//#define ADD(x, y) ((x) + (y))

// ���ȱ��
// 1�����׳����﷨ϸ�ڶ�
// 2�����ܵ���



//����������
//inline int Add(int x, int y)//����ǰ�� inline ���ŵ㣺���ý���ջ֡�����Ч��(�������ڱ����õ�ʱ��չ�����Կռ任ʱ��)
//{							//�������д���ܳ����ߴ��ڵݹ飬��ô��������inline
//	int c = x + y;			//inline���ڱ�����ֻ��һ�ֽ��飬��ʹ��inlineʱ������������ݺ�������ĳ����Լ��Ƿ�ݹ���ѡ���Ƿ�����
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




//auto��
int main()
{
	int a = 1;
	auto b = a;//b��������a��ͬ��Ϊint
	auto p1 = &a;//p1������Ϊint *
	auto* p2 = &b;//p2������Ϊint

	//��Χfor:
	int arr[] = {1,2,3,4,5};
	for (auto e : arr)//�����������ÿһ����
	{
		cout << e << endl;
	}

	return 0;
}
//auto������Ϊ�����βε����ͣ�Ҳ������Ϊ��������ֵ������