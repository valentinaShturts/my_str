#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	MyString line("dfgadfg");
	cout << "Length: " << line.MyStrlen() << endl;
	//MyString line2("dfgadfg");
	line.Print();
	//cout << "index of a: " << line.MyChr('a') << endl;
	//MyString line1;
	//cout << "Length: " << line1.MyStrlen() << endl;
	//MyString line3 = line2 + line;
	//line3.Print();
	//
	//cout << "Does line contain gad: " <<line2.MyStrStr("dfgadfg") << endl;

	//line.MyDelChr('d');
	//line.Print();
	//cout << "my str cmp: " << line2.MyStrCmp(line) << endl;

	line += 4;
	cout << "Length: " << line.MyStrlen() << endl;
	line.Print();
}