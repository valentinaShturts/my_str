#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	MyString line("dfgadfg");
	MyString line2("dfgadfg");
	line.Print();
	cout << "index of a: " << line.MyChr('a') << endl;
	MyString line1;
	cout << "Length: " << line1.MyStrlen() << endl;
	line.MyStrCat(line2);
	line.Print();
}