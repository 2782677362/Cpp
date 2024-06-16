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
	// ��Ϊ�����ڴ���룬����capacity���ܻ���ڴ���ַ����ĳ���
}

void test2()
{
	string s("hello world");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.clear(); //����ַ�������
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//��clear����ַ������ݺ�size���Ϊ0����capacity�����
}

void test3()
{
	string s("hello world");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(100); //����s�Ŀռ䣬��Ϊ�����ڴ���룬ʵ�����ݺ�ռ���ܻ����100
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

	s.resize(5); //��Сsize��ֵ��5
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// ��resize��Сsize��ֵ��size���Ϊ5��capacity����

	//s.resize(50); // ��ֵ����ԭ��size��ֵ����size����Ϊ50��capacity����
	s.resize(50,'x'); // ����һ���ַ����Σ������size����ķ�Χ��Ӧ�Ŀռ������ַ�
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void test5()
{
	string s("hello");
	cout << s << endl;

	//push_backֻ��β���ַ�������β���ַ���
	s.push_back(' ');          
	//s.push_back("world");
	cout << s << endl;

	//appendֻ��β���ַ���������β���ַ�
	s.append("world");
	//s.append('!');
	cout << s << endl;

	//+=�ȿ���β���ַ���Ҳ��β���ַ���
	s += '1';
	cout << s << endl;
	s += "234";
	cout << s << endl;
}

void test6()
{
	string s("13456");
    //s.insert(1, 'x'); ���벻ͨ������Ϊ����ֻ�ܲ����ַ��������ܲ����ַ�
	s.insert(1, "x");
	s.insert(1,	"xxx");
	cout << s << endl;

	string tmp("yyyyy");
	s.insert(6, tmp);
	cout << s << endl;

	//���±�Ϊ3��λ��ǰ����5���ַ�'z'
	s.insert(3, 5, 'z');
	cout << s << endl;
}

void test7()
{
	string s("hello world");
	//ɾ�����±�6��ʼ��3���ַ�
	s.erase(6, 3);
	cout << s << endl;

	//ɾ���±�4�����ߵ������ַ�
	s.erase(4);
	cout << s << endl;

	//��Ҫɾ�����ַ����ȹ�������ᰴ��һ�����������ɾ�����±����ߵ������ַ�
	s.erase(2, 100);
	cout << s << endl;

	s += "abcedfg";
	cout << s << endl;
	//������Ϊ���������ͣ���

	//ɾ���ô���һ���ַ�
	s.erase(s.begin());
	cout << s << endl;
	//ɾ����������ַ�
	s.erase(s.begin() + 3, s.end() - 3);
	cout << s << endl;


}

void test8()
{
	string s("hello world");
	// c_str��������һ��ָ������C�ַ�����ָ��, �����뱾string����ͬ
	const char* ch = s.c_str();
	cout << s << endl;         //����string�����ص�<<�������
	cout << ch << endl;        //ֱ�����const char*
	cout << s.c_str() << endl; //ֱ�����const char*

	s += '\0';
	s += "world";
	cout << s << endl;         //����string�����ص�<<�������  =>  �������������ַ������
	cout << s.c_str() << endl; //ֱ�����const char*   =>  ����'\0'ֹͣ���
}

void test9()
{
	string s("hello world");

	//Ѱ��ĳһ�ַ�(��)��λ�ã�
	//find:��ǰ�����ң������±�
	size_t pos1 = s.find('e');
	if (pos1 != string::npos)  //û�ҵ��᷵��string::npos
	{
		cout << pos1 << endl;
	}
	//rfind:�Ӻ���ǰ�ң������±�
	size_t pos2 = s.rfind('o');
	if (pos2 != string::npos)  
	{
		cout << pos2 << endl;
	}

	//Ҳ���Թ涨Ѱ�ҵ���ʼλ�ã�
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

	//Ҳ��Ѱ���ַ���
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

	//substr����ԭ��:substr (size_t pos = 0, size_t len = npos) const;
	
	//s1���±�Ϊ3(����3)��ʼ��5���ַ����Ƹ�s2:
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

	//���������ʵ�s�У������뵥���ÿո����

	//cin >> s; //�����ո���о�ֹͣ������ֻ��Ч�����˵�һ������
	//cout << s << endl; //��ʱֻ��ӡ��һ������

	//getline(cin, s); //�������вŽ���
	//cout << s << endl;

	//����'#'��Ϊ��������
	string s1;
	getline(cin, s1, '#');//����:aaa bbb ccc# ddd����Ч����aaa bbb ccc
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