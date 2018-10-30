#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int a( string s, char b)
{
	int a=1000;
	for ( int i=0;i<s.size();i++)
	{
		if(s[i]==b)
		{
			a=i;
		}
		
	}
	
	return a;
	
}

int main ()
{
	string s;
	char b;
	cout<<" Nhap chuoi s ";
	getline(cin,s);
	cout <<" Nhap ky tu ";
	cin >> b;
	if( a(s,b)==1000)
	cout << "Ko co ki tu "<< b <<endl;
	else 
	cout << a(s,b)+1 << endl;
	return 0;
}


