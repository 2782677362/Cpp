#include <iostream>
#include <string>
using namespace std;

void test1()
{
	string s1("hello");
	string s2("hello world");
	cout << s1.size() << endl;
	cout << s2.size() << endl;
	cout << s1.length() << endl;
	cout << s2.length() << endl;
	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;

	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;
	// 因为存在内存对齐，所以capacity可能会大于存的字符串的长度
}

void test2()
{
	string s("hello world");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.clear(); //清空字符串内容
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//用clear清空字符串内容后，size会变为0，但capacity不会变
}

void test3()
{
	string s("hello world");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(100); //扩容s的空间，因为存在内存对齐，实际扩容后空间可能会大于100
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void test4()
{
	string s("hello world");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(5); //缩小size的值至5
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// 用resize缩小size的值后，size会变为5，capacity不变

	//s.resize(50); // 若值大于原本size的值，则size增大为50，capacity增大
	s.resize(50,'x'); // 增加一个字符传参，则会在size增大的范围对应的空间存入此字符
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void test5()
{
	string s("hello");
	cout << s << endl;

	//push_back只能尾插字符，不能尾插字符串
	s.push_back(' ');          
	//s.push_back("world");
	cout << s << endl;

	//append只能尾插字符串，不能尾插字符
	s.append("world");
	//s.append('!');
	cout << s << endl;

	//+=既可以尾插字符，也能尾插字符串
	s += '1';
	cout << s << endl;
	s += "234";
	cout << s << endl;
}

void test6()
{
	string s("13456");
    //s.insert(1, 'x'); 编译不通过，因为这里只能插入字符串，不能插入字符
	s.insert(1, "x");
	s.insert(1,	"xxx");
	cout << s << endl;

	string tmp("yyyyy");
	s.insert(6, tmp);
	cout << s << endl;

	//在下标为3的位置前插入5个字符'z'
	s.insert(3, 5, 'z');
	cout << s << endl;
}

void test7()
{
	string s("hello world");
	//删除从下标6开始的3的字符
	s.erase(6, 3);
	cout << s << endl;

	//删除下标4及其后边的所有字符
	s.erase(4);
	cout << s << endl;

	//若要删除的字符长度过长，则会按上一种情况处理，即删除该下表及其后边的所有字符
	s.erase(2, 100);
	cout << s << endl;

	s += "abcedfg";
	cout << s << endl;
	//若参数为迭代器类型，则：

	//删除该处的一个字符
	s.erase(s.begin());
	cout << s << endl;
	//删除该区间的字符
	s.erase(s.begin() + 3, s.end() - 3);
	cout << s << endl;


}

void test8()
{
	string s("hello world");
	// c_str函数返回一个指向正规C字符串的指针, 内容与本string串相同
	const char* ch = s.c_str();
	cout << s << endl;         //调用string中重载的<<进行输出
	cout << ch << endl;        //直接输出const char*
	cout << s.c_str() << endl; //直接输出const char*

	s += '\0';
	s += "world";
	cout << s << endl;         //调用string中重载的<<进行输出  =>  将对象中所有字符都输出
	cout << s.c_str() << endl; //直接输出const char*   =>  遇到'\0'停止输出
}

void test9()
{
	string s("hello world");

	//寻找某一字符(串)的位置：
	//find:从前往后找，返回下标
	size_t pos1 = s.find('e');
	if (pos1 != string::npos)  //没找到会返回string::npos
	{
		cout << pos1 << endl;
	}
	//rfind:从后往前找，返回下标
	size_t pos2 = s.rfind('o');
	if (pos2 != string::npos)  
	{
		cout << pos2 << endl;
	}

	//也可以规定寻找的起始位置：
	size_t pos3 = s.find('l', 5);
	size_t pos4 = s.rfind('o', 6);
	if (pos3 != string::npos)  
	{
		cout << pos3 << endl;
	}
	if (pos3 != string::npos) 
	{
		cout << pos3 << endl;
	}

	//也可寻找字符串
	string s1("aaa bbb ccc ddd eee ccc");
	string s2("ccc");
	size_t pos5 = s1.find("ccc");
	size_t pos6 = s1.find(s2);
	size_t pos7 = s1.find(s2, 10);
	size_t pos8 = s1.rfind(s2, 15);
	if (pos5 != string::npos)
	{
		cout << pos5 << endl;
	}
	if (pos6 != string::npos)
	{
		cout << pos6 << endl;
	}
	if (pos7 != string::npos)
	{
		cout << pos7 << endl;
	}
	if (pos8 != string::npos)
	{
		cout << pos8 << endl;
	}
}

void test10()
{
	string s1("hello world");

	//substr函数原型:substr (size_t pos = 0, size_t len = npos) const;
	
	//s1中下标为3(包括3)开始的5个字符复制给s2:
	string s2 = s1.substr(3, 5);
	cout << s2 << endl;

	string s3;
	s3 = s1.substr(2);
	cout << s3 << endl;

	string s4;
	s4 = s1.substr();
	cout << s4 << endl;
}

void test11()
{
	string s;

	//输入多个单词到s中，单词与单词用空格隔开

	//cin >> s; //遇到空格或换行就停止，所以只有效存入了第一个单词
	//cout << s << endl; //此时只打印第一个单词

	//getline(cin, s); //遇到换行才结束
	//cout << s << endl;

	//若以'#'作为结束符：
	string s1;
	getline(cin, s1, '#');//输入:aaa bbb ccc# ddd，有效存入aaa bbb ccc
	cout << s1 << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	test11();

	return 0; 
}