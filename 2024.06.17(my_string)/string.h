#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace zxy
{
	class string 
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity+1];
			strcpy(_str, str);
		}

		string(const string& s)
		{
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		const char* c_str() const
		{
			return _str;
		}

		string& operator=(const string& s)
		{
			char* tmp = new char[s._capacity + 1];
			strcpy(tmp, s._str);
			
			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;

			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				/*size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp,_str);
				delete[] _str;
				_str = tmp;
				_capacity = newcapacity;*/
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			if (_capacity < strlen(str) + _size)
			{
				/*size_t newcapacity = strlen(str) + _size;
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newcapacity;*/
				reserve(strlen(str) + _size);
			}
			strcpy(_str + _size, str);
			_size += strlen(str);
		}

		char operator[](size_t pos)
		{
			assert( pos < _size);
			return _str[pos];
		}

		const char operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void resize(size_t n,char ch = '\0')
		{
			if (n <= _size)
			{
				_str[_size] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;

		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_capacity < len + _size)
			{
				reserve(len + _size);
			}
			size_t end = _size + len;
			while (end > pos)
			{
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;

		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] = ch)
					return i;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0) const
		{
			assert(pos < _size);

			const char* p = strstr(_str + pos, str);
			if (p)
				return p - _str;
			else
				return npos;
		}

		string substr(size_t pos = 0, size_t len = npos)
		{
			string sub;
			if (_size < pos + len)
			{
				for (int i = pos; i < _size; i++)
					sub += _str[i];
			}
			else
			{
				for (int i = pos; i < pos + len; i++)
					sub += _str[i];
			}
			return sub;
		}

	private:
		char* _str;
		size_t _size;//已经存的有效字符
		size_t _capacity;//能存的有效字符
	public:
		static const int npos;
	};
	const int string::npos = -1;

	bool operator==(const string& s1, const string& s2)
	{
		int ret = strcmp(s1.c_str(), s2.c_str());
		return ret == 0;
	}
	bool operator<(const string& s1, const string& s2)
	{
		int ret = strcmp(s1.c_str(), s2.c_str());
		return ret < 0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return s1 == s2 || s1 < s2;
	}
	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch;
		ch = in.get();
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i = 127)
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}


	void string_test()
	{
		string s1("hello");
		string s2 = s1;
		s2 += (' ');
		s2 += ("world");
		cout << s1 << endl;
		cout << s2 << endl;

		s1.insert(2, 'a');
		s1.insert(4, "xxx");
		cout << s1 << endl;

		s1.erase(4);
		cout << s1 << endl;
		s1.erase(1,2);
		cout << s1 << endl;

		s1.clear();
		cout << s1 << endl;


	}
	
}
