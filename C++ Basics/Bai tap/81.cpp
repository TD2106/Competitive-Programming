#include <iostream>
#include <string>
#include <vector>
using namespace std;


void dem(string s1,string s2)
{
	int i,j,c=0;
	int n = s1.size();
	int a = s2.size();
	for (i=0;i<n;i++)
	{
		int k=0;
		for (j=0;j<a;j++)
		{
			if(s1[i+j]!=s2[j])
			{
				k=1;
				break;
			}
			
		}
		if (k==0)
		{
			cout << " Chuoi s2 xuat hien o vi tri " << i+1 << " toi " << i+a <<"\n";
		}
	}
	
}


int main ()
{
	string s1,s2;
	int i=0;
	cout <<" Nhap vao chuoi s1 ";
	getline (cin,s1);
	cout <<" Nhap vao chuoi s2 ";
	getline (cin,s2);
	dem(s1,s2);
	cout << endl;
}
