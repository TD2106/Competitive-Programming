#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int a,int b)
{
	return (a>b);
}
int main ()
{
	int tc,m,n,arr[1001],cnt;
	cin>>tc;
	while(tc--)
	{
		cnt=0;
		memset(arr,0,sizeof(arr));
		cin>>m>>n;
		for(int i=0;i<n;i++)
		cin>>arr[i];
		sort(arr,arr+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(arr[i]==0||arr[i]>m)
			continue;
			for(int j=i+1;j<n;j++)
			{
				if(arr[j]==0)
				continue;
				if(arr[i]+arr[j]<=m)
				{
					arr[j]=0;
					break;
				}
			}
			arr[i]=0;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
