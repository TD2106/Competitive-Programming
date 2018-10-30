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
	int n,s=0,i=1;
	cin>>n;
	while(s!=n)
	{
		if(check(i))
		{
			s++;
			cout<<i<<" ";
		}
		i++;
	}
}
