#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	long long int N,x,y,k,t;
	cin>>N;
	while(N--)
	{
		cin>>x>>y>>k>>t;
		if(x%y==0)
		{
			x=x+1;
			t--;
			if(k>t)
			{
				x=(ceil(x*1.0/y)+t)*y;
				cout<<x<<"\n";
				continue;
			}
			else
			{
				x=(ceil(x*1.0/y)+(k-1))*y+(t-(k-1));
				cout<<x<<"\n";
				continue;
			}
		}
		else
		{
			if(k>t)
			{
				x=(ceil(x*1.0/y)+t)*y;
				cout<<x<<"\n";
				continue;
			}
			else
			{
				if(y>x)
				{
					if(t>(y-x))
					{
						long long int temp=x;
						x=(ceil(x*1.0/y)*y+1);
						t=t-(x-temp);
						if(k>t)
						{
							x=(ceil(x*1.0/y)+t)*y;
							cout<<x<<"\n";
							continue;
						}
						else
						{
							x=(ceil(x*1.0/y)+(k-1))*y+(t-(k-1));
							cout<<x<<"\n";
							continue;
						}
					}
					else
					{
						x=(ceil(x*1.0/y)+(k-1))*y+(t-(k-1));
						cout<<x<<"\n";
						continue;
					}
					
				}
				else
				{
					if(t>(ceil(x*1.0/y)*y-x))
					{
						long long int temp=x,x1;
						x1=(ceil(x*1.0/y)+(k-1))*y+(t-(k-1));
						x=(ceil(x*1.0/y)*y+1);
						t=t-(x-temp);
						if(k>t)
						{
							x=(ceil(x*1.0/y)+t)*y;
							if(x>x1)
							cout<<x<<"\n";
							else
							cout<<x1<<"\n";
							continue;
						}
						else
						{
							x=(ceil(x*1.0/y)+(k-1))*y+(t-(k-1));
							if(x>x1)
							cout<<x<<"\n";
							else
							cout<<x1<<"\n";
							continue;
						}
					}
					else
					{
						x=(ceil(x*1.0/y)+(k-1))*y+(t-(k-1));
						cout<<x<<"\n";
						continue;
					}
				}
			}
		}
	}
	return 0;
}