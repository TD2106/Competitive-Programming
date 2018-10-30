#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
using namespace std;

string strcat (string s_nhan, string s)
{
	s_nhan= s_nhan + s;
	return s_nhan;	
}

int main ()
{
	string s_nhan,s ;
	cout << " Nhap s_nhan ";
	getline(cin,s_nhan);
	cout << " Nhap s ";
	getline(cin,s);
	cout << strcat (s_nhan,s)<<endl;
	return 0;
}
