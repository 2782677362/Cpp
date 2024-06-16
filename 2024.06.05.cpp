#include <iostream>

//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

//using std::cout;
//using std::endl;
//
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

//int main()
//{
//	//std::cout << "hello world" << std::endl;
//
//	int a = 0;
//	float b = 0;
//
//	std::cin >> a >> b;
//	std::cout << a << std::endl << b << std::endl;
//
//	return 0;
//}



int add(int a, int b = 0)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

float add(int a, float b)
{
	return a + b;
}

float add(float a, int b)
{
	return a + b;
}

int main()
{
	std::cout << add(3, 5) << std::endl;
	std::cout << add(3) << std::endl;
	std::cout << add(3.1f, 3.2f) << std::endl;
	std::cout << add(1, 3.2f) << std::endl;
	float ret = add(1, 3.2f);
	return 0;
}
