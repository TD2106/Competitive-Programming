#include <iostream>
#include <vector>
using namespace std;
void xuli(string s)
{
	int temp1=-1,temp2,check,test;
	string s1;
	vector<int> a;
	vector<int> b;
	for(int i=0;i<s.size();i++)
	{
		if(i==s.size()-1)
		{
			temp2=i;
			check=temp2-temp1;
			test=1;
			for(int j=0;j<a.size();j++)
			{
				if(a[j]==check)
				{
					test=0;
					b[j]=b[j]+1;
					break;
			    }
			}
			if(test==1)
			    {
			    	a.push_back(check);
			        b.push_back(1);
				}
		}
		if(s[i]==' ')
		{
			temp2=i-1;
			check=temp2-temp1;
			temp1=i;
			test=1;
			for(int j=0;j<a.size();j++)
			{
				if(a[j]==check)
				{
					test=0;
					b[j]=b[j]+1;
					break;
			    }
			}
			if(test==1)
			    {
			    	a.push_back(check);
			        b.push_back(1);
				}
		}
	}
	cout<<"Chuoi co:  "<<endl;
	for(int i=0;i<a.size();i++)
	cout<<b[i]<<" tu "<<a[i]<<" chu"<<endl;
}
int main ()
{
	string s;
	cout<<"Nhap chuoi S"<<endl;
	getline(cin,s);
	xuli(s);
	return 0;
}
