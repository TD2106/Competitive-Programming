#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main ()
{
	int tc,n,k,arr[101],down=101,up=0,ans=2000000000;
	cin>>tc;
	while(tc--)
	{
		ans=2000000000;
		memset(arr,0,sizeof(arr));
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			down=min(down,arr[i]);
			up=max(up,arr[i]);
		}
		for(int i=down;i<=up;i++)
		{
			int cost[101]={0};
			for(int j=0;j<n;j++)
			{
				if(arr[j]>i) cost[j]=(arr[j]-i)*5;
				else cost[j]=(i-arr[j])*3;
			}
			sort(cost,cost+n);
			int temp=0;
			for(int j=0;j<k;j++)
			temp+=cost[j];
			ans=min(temp,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
