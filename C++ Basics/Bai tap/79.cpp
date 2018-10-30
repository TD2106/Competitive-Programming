#include <iostream>
#include <string>

using namespace std;

int d(string s1, string s2)
{
	int i;
	int n = s1.size();
	int a = s2.size();
	for (i=0;i<n;i++)
	{
		int k=0;
		for (int j=0;j<a;j++)
		{
			if(s1[i+j]!=s2[j])
			k=1;
			if(k==1)
			break;
			
		}
		if(k==0)
		break;
	}
	return i;
}

int main ()
{
	string s1,s2;
	cout << " Nhap vao s1 ";
	getline(cin,s1);
	cout << " Nhap vao s2 ";
	getline(cin,s2);
	int a=s2.size();
	cout << " Chuoi s2 xuat hien o vi tri " <<  d(s1,s2)  << " toi vi tri " <<  d(s1,s2)+a-1  << " trong chuoi s1 " << endl;
	return 0;
}

