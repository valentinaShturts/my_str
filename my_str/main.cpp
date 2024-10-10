#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
	MyString line;
	cin >> line;
	cout << line;

	MyString line2;
	line2 = line;
	cout << line2;

	line + 'T';
	'T' + line2;
	cout << line;
	cout << line2;

	line + 2;
	4 + line2;
	line++;
	++line2;
	cout << line;
	cout << line2;

	//line.Print();
	//cout << "index of 'a': " << line.MyChr('a') << endl;
	//cout << "Does line2 contain 'gad': " <<line2.MyStrStr("gad") << endl;
	//line.MyDelChr('d');
	//cout << "Deleting 'd': ";
	//line.Print();
	//cout << "my line2 & line cmp: " << line2.MyStrCmp(line) << endl;


	//++line2;
	//--line;
	//line += 6;
	//line -= 4;
	/*cout << "Length: " << line.MyStrlen() << endl;
	cout << "Length: " << line2.MyStrlen() << endl;
	line.Print();
	line2.Print();
	if (line > line2) 
	{
		cout << "line1 > line2" << std::endl;
	}

	if (line < line2) 
	{
		cout << "line1 < line2" << std::endl;
	}

	if (line == line2) 
	{
		cout << "line1 = line2" << std::endl;
	}

	if (line != line2) 
	{
		cout << "line1 != line2" << std::endl;
	}

	line.MyStrCat(line2);
	cout << "Length: " << line.MyStrlen() << endl;
	line.Print();*/
}