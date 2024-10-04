#pragma once
class MyString
{
	char* str;
	int length;
	static int obj_сount;
public:
	MyString();
	MyString(int size);
	MyString(const char* s);
	~MyString();
	int GetCount() const;
	void Input();
	void Print() const;
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* s);
	int MyChr(char c);
	int MyStrlen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
	MyString operator+(MyString& b);
	MyString& operator++();
	MyString& operator--();
	MyString& operator+=(int b);
	MyString& operator-=(int b);
	bool operator>(MyString& b);
	bool operator<(MyString& b);
	bool operator==(MyString& b);
	bool operator!=(MyString& b);
};

