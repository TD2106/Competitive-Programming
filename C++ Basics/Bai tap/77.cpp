#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int a(string s1)
{

	return s1.size();
}

int main ()
{
	string s1;
	cout << " Nhap s1 ";
	getline(cin,s1);
	cout << a(s1) << endl;
	return 0;
}
