#include <iostream>
#include <cmath>
using namespace std;
int uoc(int i,int n)
{
	if(n%i==0)
	return 1;
	else
	return 0;
}
int check(int i)
{
	int check=1;
	if(i==1)
	return 0;
	if(i==2||i==3||i==5||i==7)
	return 1;
	else
	{
		for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				check=0;
				break;
			}
		}
		return check;
	}
}
int main ()
{
	int n;
	cout<<"Nhap n ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(uoc(i,n))
		{
			if(check(i))
			cout<<i<<" ";
		}
	}
	return 0;
}
