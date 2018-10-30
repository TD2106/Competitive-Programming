#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

string strcopy (string s1, string s2)
{
	s2=s1;
	return s2;
}

int main ()
{
	string s1,s2;
	cout << " Nhap chuoi s1 ";
	getline (cin,s1);
	cout << strcopy(s1,s2) << endl;
	return 0;
}

