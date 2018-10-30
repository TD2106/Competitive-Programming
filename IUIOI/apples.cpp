#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	long long ans=0,arr[20001],n,temp,sum=0,avg,temp1,temp2;
	cin>>n;
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		arr[i]=temp;
		sum+=temp;
	}
	for(int i=n;i<2*n;i++)
	arr[i]=arr[i-n];
	avg=sum/n;
	for(long long i=n;i<2*n;i++)
	{
		if(arr[i]==avg)
		continue;
		while(arr[i]<avg)
		{
			long long j,k,mn;
			temp=avg-arr[n+i];
			for(j=i+1;j<2*n;j++)
			{
				if(arr[j]>avg)
				break;
			}
			for(k=i-1;k>n-i;k--)
			{
				if(arr[k]>avg)
				break;
			}
			if(j==2*n)
			mn=k;
			else if(k==n-i)
			mn=j;
			else
			{
				if(j-i<i-k)
				mn=j;
				else
				mn=k;
			}
			temp=min(avg-arr[i],arr[mn]-avg);
			arr[i]+=temp;
			arr[mn]-=temp;
			if(mn<n)
			{
				ans+=temp*(i-mn);
				arr[mn+n]=arr[mn];
			}
			else
			{	
				ans+=temp*(mn-i);
				arr[mn-n]=arr[mn];
			}
		}
	}
	cout<<ans;
	return 0;
}
