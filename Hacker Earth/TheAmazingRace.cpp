#include <iostream>
#include <stack>
#include <cstring>
#define mod 1000000007
using namespace std;
struct obj
{
	long long he;
	long long index;
};
long long back[100001],front[100001],tc,n;
obj h[100001];
int main ()
{
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		memset(back,0,sizeof(back));
		memset(front,0,sizeof(front));
		memset(h,0,sizeof(h));
		for(long long i=1;i<=n;i++)
		{
			cin>>h[i].he;
			h[i].index=i;
		}
		stack<obj> line;
		back[1]=0;
		line.push(h[1]);
		for(long long i=2;i<=n;i++)
		{
			while(!line.empty()&&h[i].he>line.top().he)
			line.pop();
			if(line.empty())
			back[i]=i-1;
			else
			back[i]=i-line.top().index;
			line.push(h[i]);
		}
		while(!line.empty())
		line.pop();
		front[n]=0;
		for(long long i=n;i>0;i--)
		{
			while(!line.empty()&&h[i].he>line.top().he)
			line.pop();
			if(line.empty())
			front[i]=n-i;
			else
			front[i]=line.top().index-i;
			line.push(h[i]);
		}
		long long mx=-1,ans;
		for(long long i=1;i<=n;i++)
		{
			long long point=(i)*(back[i]+front[i]);
			if(point>mx)
			{
				ans=i;
				mx=point;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
