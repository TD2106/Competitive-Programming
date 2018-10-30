#include <iostream>
#include <string>

using namespace std;

string strrev(string s1)
{
	char b;
	int n=s1.size();
	int a=n-1;
	n=n/2;
	for (int i=0;i<n;i++)
	{
		b=s1[i];
		s1[i]=s1[a];
		s1[a]=b;
		a--;
	}
	return s1;
}


int main ()
{
	string s1;
	cout << " Nhap vao s1 ";
	getline(cin,s1);
	cout << strrev(s1) << endl;
	return 0;
}
