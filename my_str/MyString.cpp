#include "MyString.h"

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
	length = strlen(s);
	str = new char[length+1];
	strcpy_s(str, length+1, s);
	obj_сount++;
}

MyString::~MyString()
{
	delete[] str;
	obj_сount--;
}

MyString& MyString::operator=(const MyString& right)
{
	if (this != &right) 
	{
		delete[] str; 

		str = new char[right.length+1];
		length = right.length;

		strcpy_s(this->str, this->length + 1, right.str);
	}

	return *this;
}

int MyString::GetCount() const
{
	return obj_сount;
}

void MyString::Input()
{
	char* input_line = new char[100];
	cout << "Enter string: ";
	cin.getline(input_line, 100);

	delete[] str;

	length = strlen(input_line);
	str = new char[length+1];
	strcpy_s(str, length+1, input_line);

	delete[] input_line;
}

void MyString::Print() const
{
	cout << str << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	delete[] this->str;
	this->length = obj.length;
	this->str = new char[this->length+1];
	strcpy_s(this->str,this->length+1, obj.str);
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

int MyString::MyStrlen() const
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	int cat_length = length + b.length;

	char* cat = new char[cat_length+1];
	strcpy_s(cat, cat_length+1, str);
	strcat_s(cat, cat_length+1, b.str);
	delete[] str;
	str = cat;
	length = cat_length;

}

void MyString::MyDelChr(char c)
{
	if (str == nullptr) return; 

	int new_length = 0;
	for (int i = 0; i < length; i++) 
	{
		if (str[i] != c) 
		{
			new_length++;
		}
	}
	if (new_length == length) return;

	char* s = new char[new_length + 1];  
	int j = 0;
	for (int i = 0; i < length; i++) 
	{
		if (str[i] != c) 
		{
			s[j] = str[i];
			j++;
		}
	}
	s[new_length] = '\0';

	delete[] str;
	str = s;
	length = new_length;
	
}

int MyString::MyStrCmp(MyString& b)
{
	int result = strcmp(b.str, this->str);
	return result;
}
//
//MyString MyString::operator+(MyString& b) 
//{
//	MyString temp; 
//	temp.MyStrcpy(*this);
//	temp.MyStrCat(b);      
//	return temp;
//}
//
//MyString& MyString::operator++()
//{
//	int newLength = this->length+1;
//	char* newStr = new char[newLength + 1]; 
//
//	for (int i = 0; i < this->length; i++) 
//	{
//		newStr[i] = this->str[i];
//	}
//
//	newStr[this->length] = '0';
//
//	newStr[newLength] = '\0';
//	delete[] this->str;
//	this->str = newStr;
//	this->length = newLength;
//
//	return *this;
//}
//
//MyString& MyString::operator--()
//{
//	int newLength = this->length - 1;
//	char* newStr = new char[newLength  + 1];
//
//	for (int i = 0; i < this->length; i++)
//	{
//		newStr[i] = this->str[i];
//	}
//
//	newStr[newLength] = '\0';
//	delete[] this->str;
//	this->str = newStr;
//	this->length = newLength;
//
//	return *this;
//}
//
//MyString& MyString::operator+=(int b)
//{
//	int l = this->length + b;
//	char* s = new char[l + 1];
//
//	for (int i = 0; i < this->length; i++) 
//	{
//		s[i] = this->str[i];
//	}
//	for (int i = this->length; i < l+1; i++) 
//	{
//		s[i] = '0';
//	}
//	s[l] = '\0';
//
//	delete[] this->str;
//	this->str = s;
//	this->length = l;
//
//	return *this;
//}
//
//MyString& MyString::operator-=(int b)
//{
//	if (b >= this->length) 
//	{
//		delete[] this->str;
//		this->str = new char[1];  
//		this->str[0] = '\0';
//		this->length = 0;
//		return *this;
//	}
//	int l = this->length - b;
//	char* s = new char[l+1];
//
//	for (int i = 0; i < l; i++)
//	{
//		s[i] = this->str[i];
//	}
//	s[l] = '\0';
//
//	delete[] this->str;
//	this->str = s;
//	this->length = l;
//
//	return *this;
//}

bool MyString::operator>(MyString& b)
{
	return this->length > b.length;
}

bool MyString::operator<(MyString& b)
{
	return this->length < b.length;
}

bool MyString::operator==(MyString& b)
{
	return this->length == b.length;
}

bool MyString::operator!=(MyString& b)
{
	return this->length != b.length;
}

char& MyString::operator[](const unsigned int index)
{
	if (index < length && index >= 0)
	{
		return str[index];
	}
	return str[0];
}

MyString& MyString::operator()()
{
	this->Input();
	return *this;
}

MyString& operator+(MyString& a, char b)
{
	int newLength = a.MyStrlen() + 1;
	char* newStr = new char[newLength + 1];

	for (int i = 0; i < newLength-1; i++)
	{
		newStr[i] = a[i];
	}

	newStr[newLength - 1] = b;
	newStr[newLength] = '\0';

	MyString c(newStr);
	a.MyStrcpy(c);

	return a;
}

MyString& operator+(char b, MyString& a)
{
	int newLength = a.MyStrlen() + 1;
	char* newStr = new char[newLength + 1];

	for (int i = 0; i < newLength - 1; i++)
	{
		newStr[i+1] = a[i];
	}

	newStr[0] = b;
	newStr[newLength] = '\0';

	MyString c(newStr);
	a.MyStrcpy(c);

	return a;
}

MyString& operator+(MyString& a, const int b)
{
	int newLength = a.MyStrlen() + b;
	char* newStr = new char[newLength + 1];

	for (int i = 0; i < a.MyStrlen(); i++)
	{
		newStr[i] = a[i];
	}

	for (int i = a.MyStrlen(); i < newLength + 1; i++)
	{
		newStr[i] = '0';
	}
	
	newStr[newLength] = '\0';

	MyString c(newStr);
	a.MyStrcpy(c);

	return a;
}

MyString& operator+(const int b, MyString& a)
{
	int newLength = a.MyStrlen() + b;
	char* newStr = new char[newLength + 1];

	for (int i = 0; i < b; i++)
	{
		newStr[i] = '0';
	}

	for (int i = 0; i < newLength - b; i++)
	{
		newStr[i+b] = a[i];
	}

	newStr[newLength] = '\0';

	MyString c(newStr);
	a.MyStrcpy(c);

	return a;
}

MyString& operator++(MyString& a, int)
{
	int newLength = a.MyStrlen() + 1;
	char* newStr = new char[newLength + 1];

	for (int i = 0; i < newLength - 1; i++)
	{
		newStr[i] = a[i];
	}

	newStr[newLength-1] = '0';
	newStr[newLength] = '\0';

	MyString c(newStr);
	a.MyStrcpy(c);

	return a;
}

MyString& operator++(MyString& a)
{
	int newLength = a.MyStrlen() + 1;
	char* newStr = new char[newLength + 1];

	for (int i = 0; i < newLength - 1; i++)
	{
		newStr[i + 1] = a[i];
	}

	newStr[0] = '0';
	newStr[newLength] = '\0';

	MyString c(newStr);
	a.MyStrcpy(c);

	return a;
}

ostream& operator<<(ostream& os, const MyString& obj)
{
	os << "Size: " << obj.MyStrlen() << endl;
	os << "String: ";
	obj.Print();
	os << endl;
	return os;
}

istream& operator>>(istream& is, MyString& obj)
{
	obj.Input();
	return is;
}
