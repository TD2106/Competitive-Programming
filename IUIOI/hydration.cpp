#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
bool cmp(int a,int b)
{
	return (a>b);
}
int c[1000001]={0},t[1000001]={0};
int main ()
{
	int n,m,k,cnt=0,index=0,remaincow;
	bitset<1000001> mark;
	bool check=0;
	cin>>n>>m>>k;
	remaincow=n;
	for(int i=0;i<n;i++)
	cin>>c[i];
	for(int i=0;i<m;i++)
	cin>>t[i];
	if(m==0)
	{
		cout<<-1;
		return 0;
	}
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	sort(c,c+n,cmp);
	sort(t,t+m,cmp);
	if(c[0]<t[m-1]||c[n-1]-k>t[0])
	{
		cout<<-1;
		return 0;
	}
	while(remaincow)
	{
		check=1;
		index=0;
		for(int i=0;i<n;i++)
		{
			if(mark[i]||c[i]-k>t[index])
			continue;
			for(int j=index;j<m;j++)
			{
				if(c[i]-k<=t[j]&&c[i]>=t[j])
				{
					mark[i]=1;
					remaincow--;
					check=0;
					index=++j;
					break;
				}
			}
		}
		if(check)
		break;
		cnt++;
	}
	if(check)
	cout<<-1;
	else
	cout<<cnt;
}
