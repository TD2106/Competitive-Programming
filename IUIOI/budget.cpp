#include <iostream>
#include <algorithm>
using namespace std;
long long cost[20][4]={0},mn=100000000000,e,t,h,f,n,sum,ex,food;
bool mark[20]={0};
void thu(int i)
{
	for(int j=0;j<2;j++)
	{
		mark[i]=j;
		if(i==n-1)
		{
			sum=h;
			ex=0;
			for(int k=0;k<n;k++)
			{
				if(mark[k])
				{
					ex+=cost[k][0];
				}
			}
			if(ex>=e)
			{
				for(int k=0;k<n;k++)
				{
					if(mark[k])
					sum=max(sum,cost[k][2]);
				}
				sum+=t;
				for(int k=0;k<n;k++)
				{
					if(mark[k])
					sum+=cost[k][1];
				}
				food=f;
				for(int k=0;k<n;k++)
				{
					if(mark[k])
					food-=cost[k][3];
				}
				if(food>=0)
				sum+=food;
				mn=min(sum,mn);
			}
			else
			continue;
		}
		else
		thu(i+1);
	}
}

int main ()
{
	cin>>e>>t>>h>>f;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		cin>>cost[i][j];
	}
	thu(0);
	cout<<mn;
	return 0;
}
