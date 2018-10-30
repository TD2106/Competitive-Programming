#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	long long a,b,c,temp;
	cin>>a>>b>>c;
	while(a!=2*b)
	{
		if(a>2*b)
		{
			c-=a-2*b;
			a=2*b;
		}
		else
		{
			c-=b-a/2;
			b=a/2;			
		}
	}
	if(c<=0)
	{
		cout<<b;
	}
	else
	{
		if(c%3==0)
		cout<<b-c/3;
		else
		{
			cout<<b-c/3-1;
		}
	}
	return 0;
}
