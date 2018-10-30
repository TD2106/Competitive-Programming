#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	long long int N,x,y,k,t;
	//freopen("dongho.txt","r",stdin);
	cin>>N;
	while(N--)
	{
		cin>>x>>y>>k>>t;
		int i=0;
		for(i=0;i<=t;i++)
		{
			if(i!=0)
			x=x+1;
			if(k>0)
			{
				if(x%y==0)
				x=(ceil(x*1.0/y)+1)*y;
				else
				x=ceil(x*1.0/y)*y;
				k--;
			}
		}
		cout<<x<<"\n";
	}
	return 0;
}
