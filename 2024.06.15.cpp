#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

////模板
//template <class T>
//class Vector {
//public:
//    Vector()
//        :_pData(nullptr)
//        ,_size(0)
//        ,_capacity(0)
//    {}
//    ~Vector()
//    {
//        if (_pData)
//            delete[] _pData;
//        _pData = nullptr;
//        _size = _capacity = 0;
//    }
//    void PushBack(const T& x);
//    T& Pop();
//    size_t size()
//    {
//        return _size;
//    }
//    T& operator[](size_t i)
//    {
//        return _pData[i];
//    }
//private:
//    T* _pData;
//    size_t _size;
//    size_t _capacity;
//};
//
//template <class T>
//void Vector<T>::PushBack(const T& x)
//{
//    if (_size == _capacity)
//    {
//        size_t newcapacity = (_capacity == 0) ? 2 : 2 * _capacity;
//        T* tmp = new T[newcapacity];
//        if (_pData)
//        {
//            memcpy(tmp, _pData, _size * sizeof(T));
//            delete[] _pData;
//        }
//        _pData = tmp;
//        _capacity = newcapacity;
//    }
//    _pData[_size] = x;
//    _size++;
//}
//
//template <class T>
//T& Vector<T>::Pop()
//{
//    assert(_size > 0);
//    _size--;
//    return _pData[_size];
//}
//
//
//int main()
//{
//    Vector<int> v1;
//    v1.PushBack(1);
//    v1.PushBack(2);
//    v1.PushBack(3);
//    v1.PushBack(4);
//
//    for (size_t i = 0; i < v1.size(); i++)
//    {
//        cout << v1[i] << " ";
//    }
//    cout << endl;
//
//    int pop1 = v1.Pop();
//    int pop2 = v1.Pop();
//    cout << pop1 << " " << pop2 << endl;
//
//    return 0;
//}


// string：
int main()
{
	//string s1;
	//string s2("hello");
	//string s3(s2);
	//string s4 = s3;
	//string s5("hello", 2);
	//string s6(s2, 2);
	//string s7(s2, 2, 2);
	//string s8(s2, 2, 10);
	//string s9(s2, 2, string::npos);
	//string s10(10, 'a');

	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;
	//cout << s5 << endl;
	//cout << s6 << endl;
	//cout << s7 << endl;
	//cout << s8 << endl;
	//cout << s9 << endl;
	//cout << s10 << endl;



	//string st("hello world");
	//// 遍历1：下标＋[]
	//for (size_t i = 0; i < st.size(); i++)
	//{
	//	cout << st[i] << " ";
	//}
	//cout << endl;

	//for (size_t i = 0; i < st.size(); i++)
	//{
	//	st[i] += 1;
	//}

	//for (size_t i = 0; i < st.size(); i++)
	//{
	//	cout << st[i] << " ";
	//}
	//cout << endl;
	//
	//// 遍历2：迭代器
	//string::iterator it = st.begin();
	////auto it = st.begin();
	//while (it != st.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	//it = st.begin();
	//while (it != st.end())
	//{
	//	*it -= 1;
	//	it++;
	//}

	//it = st.begin();
	//while (it != st.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	//// 遍历3：auto语法糖(C++11) -> 底层其实是迭代器
	//for (auto e : st)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//// 反向遍历？ 反向迭代器
	//string::reverse_iterator rit = st.rbegin();
	////auto rit = st.rbegin();
	//while (rit != st.rend())
	//{
	//	//*rit += 1; //可读可写
	//	cout << *rit << " ";
	//	rit++;
	//}
	//cout << endl;



	string st1("hello world");
	//const迭代器：可读不可改写
	string::const_iterator it = st1.begin();
	//auto it = st.begin();
	while (it != st1.end())
	{
		//*it += 1; //不可改写，编译不通过
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//反向遍历，可读不可写，const反向迭代器
	string::const_reverse_iterator rit = st1.rbegin();
	// auto rit = st1.rbegin();
	while (rit != st1.rend())
	{
		//*rit += 1;  //不可改写，编译不通过
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	return 0;
}
