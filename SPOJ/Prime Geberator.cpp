#include <iostream>
#include <cmath>
using namespace std;
int check(long int n)
{
	int check = 1;
	if(n==1)
	return check = 0;
	if(n==2||n==3||n==5||n==7)
	return check=1;
	else
	{
		if(n%2==0||n%3==0)
		return check =0;
		else
		{
		for(long int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				check = 0;
				break;
			}
		}
		}
	}
	return check;
}

int main ()
{
	int n;
	cin>>n;
	if(n>10)
	exit (0);
	long int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]>b[i]||b[i]-a[i]>100000||a[i]>1000000000||b[i]>1000000000||a[i]<1||b[i]<1)
		continue;
		for(long int j=a[i];j<=b[i];j++)
		{
			if(check(j))
			cout<<j<<endl;
		}
		cout<<endl;
	}
	return 0;
}
