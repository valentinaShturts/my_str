#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;


MyString::MyString()
{
	length = 80;
	str = new char[length];
}

MyString::MyString(int size)
{
	length = size;
	str = new char[length];
}

MyString::MyString(const char* s)
{
	length = strlen(s) +1;
	str = new char[length];
	strcpy_s(str, length, s);
}

MyString::~MyString()
{
	delete[] str;
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

}

bool MyString::MyStrStr(const char* str)
{
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
	int cat_size = this->length + b.length;
	char* cat = new char[cat_size];
	for (int i = 0; i < this->length; i++)
	{
		cat[i] = this->str[i];
	}
	for (int i = 0; i < b.length; i++)
	{
		cat[this->length+i] = b.str[i];
	}
	this->str = cat;
	this->length = cat_size;

	delete[]cat;
}

void MyString::MyDelChr(char c)
{
}

int MyString::MyStrCmp(MyString& b)
{
	return 0;
}
