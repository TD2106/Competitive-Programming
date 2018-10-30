#include <iostream>
#include <cmath>
using namespace std;
int check(int i)
{
	int check=1;
	if(i==1)
	return 0;
	else
	{
		if(i==2||i==3||i==5||i==7)
		return 1;
		else
		{
			for(int j=2;j<=sqrt(i);j++)
			if(i%j==0)
			{
				check=0;
				break;
			}
			return check;
		}
	}
}
int main ()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0&&check(i)==1)
		cout<<i<<" ";
	}
	return 0;
}
