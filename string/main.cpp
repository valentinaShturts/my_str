#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;
    char op;
    int op_index = -1;
    getline(cin, str1, '\n');

    if (str1.find('+') != string::npos)
    {
        op = '+';
        op_index = str1.find('+');
    }
    else if (str1.find('-') != string::npos)
    {
        op = '-';
        op_index = str1.find('-');
    }
    else { cout << "Operation not found" << endl; }
   
    if (op_index != -1)
    {
        string fNumber = str1.substr(0, op_index);
        string sNumber = str1.substr(op_index + 1, str1.length());

        int fNum = stoi(fNumber);
        int sNum = stoi(sNumber);
        if (op == '+') cout << fNum + sNum << endl;
        else { cout << fNum - sNum << endl; }
    }
}