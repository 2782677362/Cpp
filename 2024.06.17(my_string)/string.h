#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace zxy
{
	class string 
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		string(const string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		size_t size(const string& s)
		{
			return strlen(s._str);
		}

		char& operator[](int pos)
		{
			assert(pos < strlen(_str));
			return _str[pos];
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}
	private:
		char* _str;
	};
}
