#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int strcmp (string s1, string s2)
{
	int n = s1.compare(s2);
	return n;
}

int main ()
{
	string s1,s2;
	cout << " Nhap chuoi s1 ";
	getline(cin,s1);
	cout << " Nhap chuoi s2 ";
	getline(cin,s2);
	cout << strcmp (s1,s2) << endl;
	return 0;
}
