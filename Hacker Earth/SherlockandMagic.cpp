#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <cstring>
using namespace std;
struct criminal
{
	int x,y;
	char dir;
};
struct obj
{
	int cri1,cri2;
	int when;
};
bool cmp(obj a,obj b)
{
	return (a.when<b.when);
}
bool cmp1st(criminal a,criminal b)
{
	return (a.dir<b.dir);
}
int checkmeet(criminal a,criminal b)
{
	if(a.dir==b.dir) return 0;
	if(a.dir=='E'&&b.dir=='S')
	{
		if(b.x-a.x==b.y-a.y&&b.x-a.x>0)
		return (b.x-a.x)*2;
		else return 0;
	}
	if(a.dir=='S'&&b.dir=='W')
	{
		if(b.x-a.x==a.y-b.y&&b.x-a.x>0)
		return (b.x-a.x)*2;
		else return 0;
	}
	if(a.dir=='N'&&b.dir=='S')
	{
		if(a.x==b.x&&a.y<b.y)
		return b.y-a.y;
		else return 0;
	}
	if(a.dir=='E'&&b.dir=='W')
	{
		if(a.y==b.y&&a.x<b.x)
		return b.x-a.x;
		else return 0;
	}
	if(a.dir=='E'&&b.dir=='N')
	{
		if(a.y-b.y==b.x-a.x&&b.x-a.x>0)
		return (b.x-a.x)*2;
		else return 0;
	}
	if(a.dir=='N'&&b.dir=='W')
	{
		if(b.x-a.x==b.y-a.y&&b.x-a.x>0)
		return (b.x-a.x)*2;
		else return 0;
	}
}
int main ()
{
	criminal input[51];
	int tc,ans,n;
	cin>>tc;
	while(tc--)
	{
		bitset<51> mark,cur;
		vector<obj> data;
		obj temp;
		memset(input,0,sizeof(input));
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>input[i].x>>input[i].y>>input[i].dir;
		sort(input,input+n,cmp1st);
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int ti=checkmeet(input[i],input[j]);
				if(ti)
				{
					temp.cri1=i;
					temp.cri1=j;
					temp.when=ti;
					data.push_back(temp);
				}
			}
		}
		sort(data.begin(),data.end(),cmp);
		for(int i=0;i<data.size();i++)
		{
			int sta=i;
			while(sta<data.size()&&data[sta].when==data[i].when)
			{
				if(mark[data[sta].cri1]|mark[data[sta].cri2])
				{
					sta++;
					continue;
				}
				cur[data[sta].cri1]=1;
				cur[data[sta].cri2]=1;
				sta++;
			}
			i=--sta;
			mark|=cur;
			cur.reset();
		}
		ans=0;
		for(int i=0;i<n;i++)
		if(!mark[i])
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}
