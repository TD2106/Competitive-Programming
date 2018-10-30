#include <iostream>
using namespace std;
int main ()
{
	long long int testcase,x,y,k,t;
	cin>>testcase;
	while(testcase--)
	{
		cin>>x>>y>>k>>t;
		if(y==1)
		cout<<x+t<<endl;
		else
		{
			long long int mul;
			if(x%y!=0)
			mul=x/y+1;
			else
			mul=x/y;
			if(k>t)
			{
				x=(mul+t)*y;
				cout<<x<<endl;
			}
			else
			{
				long long int x1,x2=0;
				x1=(mul+k-1)*y+t-(k-1);
				if(x+t>mul*y)
				{
					x2=mul*y+1;
					t=t-(x2-x);
					if(k>t)
					x2=(x2/y+1+t)*y;
					else
					x2=(x2/y+1+k-1)*y+t-(k-1);
				}
				if(x1>x2)
				cout<<x1<<endl;
				else
				cout<<x2<<endl;
			}
		}
	}
	return 0;
}
