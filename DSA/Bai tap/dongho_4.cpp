#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	long long int n,x,y,k,t;
	cin>>n;
	while(n--)
	{
		cin>>x>>y>>k>>t;
		if(!x%y)
		{
			x++;
			t--;
		}
		if(k>t)
		{
			x=(ceil(x*1.0/y)+t)*y;
			cout<<x<<"\n";
			continue;
		}
		else
		{
			long long int x1;
			x1=(ceil(x*1.0/y)+(k-1))*y+(t-(k-1));
			if(x+t>ceil(x*1.0/y))
			{
				long long int temp;
				x=(ceil(x*1.0/y)*y+1);
				t=t-(x-temp);
				if(k>t)
				x=(ceil(x*1.0/y)+t)*y;
				else
				x=(ceil(x*1.0/y)+(k-1))*y+(t-(k-1));
			}
			if(x1>x)
			cout<<x1<<"\n";
			else
			cout<<x<<"\n";
		}
	}
}
