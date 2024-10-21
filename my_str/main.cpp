#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

MyString ObjReturn(MyString obj)
{
	return obj;
}

int main()
{
	MyString line{ 'H', 'e', 'l', 'l' };
	cout << line;


	MyString line2{ 'W','o','r','d' };
	cout << line2;

	MyString line3 = ObjReturn(move(line));
	cout << line3;

	line2 = move(line3);
	cout << line2;
	return 0;
}