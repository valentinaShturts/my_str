#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

int MyString::obj_сount = 0;

MyString::MyString()
{
	length = 80;
	str = new char[length];
	obj_сount++;
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length];
	obj_сount++;
}

MyString::MyString(const char* s)
{
	length = strlen(s) +1;
	str = new char[length];
	strcpy_s(str, length, s);
	obj_сount++;
}

MyString::~MyString()
{
	delete[] str;
	obj_сount--;
}

int MyString::GetCount() const
{
	return obj_сount;
}

void MyString::Input()
{
	char* input_line = new char[100];
	cout << "Enter string: ";
	cin >> input_line;

	length = strlen(input_line) + 1;
	str = new char[length];
	strcpy_s(str, length, input_line);

	delete[] input_line;
}

void MyString::Print() const
{
	cout << str << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	this->length = obj.length;
	this->str = new char[this->length];
	strcpy_s(this->str,this->length, obj.str);
}

bool MyString::MyStrStr(const char* s)
{
	if (str == nullptr || s == nullptr) return false;

	int s_length = strlen(s);

	for (int i = 0; i <= length - s_length; i++) 
	{
		for (int j = 0; j < s_length; j++)
		{
			if (str[i + j] != s[j]) break;
			if (j == s_length-1) return true;
		}
	}

	return false;
}

int MyString::MyChr(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}

int MyString::MyStrlen()
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	int cat_length = length + b.length+1;

	char* cat = new char[cat_length];
	strcpy_s(cat, cat_length, str);
	strcat_s(cat, cat_length, b.str);
	delete[] str;
	str = cat;
	length = cat_length;

}

void MyString::MyDelChr(char c)
{
	if (str == nullptr) return;

	int new_length = 1;
	for (int i = 0; i < length; i++) 
	{
		if (str[i] != c) new_length++;
	}

	if (new_length == length) return;

	char* s = new char[new_length];
	int j = 0;
	for (int i = 0; i < length; i++) 
	{
		if (str[i] != c) 
		{
			s[j] = str[i]; 
			j++;
		}

	}
	s[new_length-1] = '\0';

	delete[] str;
	str = s;
	length = new_length;
	
}

int MyString::MyStrCmp(MyString& b)
{
	int result = strcmp(str, b.str);
	return result;
}

MyString MyString::operator+(MyString& b) 
{
	MyString temp; 
	temp.MyStrcpy(*this);
	temp.MyStrCat(b);      
	return temp;
}

MyString MyString::operator++(int)
{
	MyString temp(this->length + 1);
	for (int i = 0; i < this->length; i++)
	{
		temp.str[i] = this->str[i];
	}
	temp.str[this->length-1] = '0';
	temp.str[this->length ] = '\0';
	return temp;
}

MyString MyString::operator--(int)
{
	MyString temp(this->length - 1);
	for (int i = 0; i < this->length-2; i++)
	{
		temp.str[i] = this->str[i];
	}
	temp.str[this->length-2] = '\0';
	return temp;
}

MyString MyString::operator+=(int b)
{
	int l = this->length + b;
	MyString temp(l);
	for (int i = 0; i < this->length; i++)
	{
		temp.str[i] = this->str[i];
	}
	for (int i = this->length; i < l; i++)
	{
		temp.str[i] = '0';
	}
	temp.str[l] = '\0';
	return temp;
}

MyString MyString::operator-=(int b)
{
	return MyString();
}

bool MyString::operator>(MyString& b)
{
	return false;
}

bool MyString::operator<(MyString& b)
{
	return false;
}

bool MyString::operator==(MyString& b)
{
	return false;
}

bool MyString::operator!=(MyString& b)
{
	return false;
}


