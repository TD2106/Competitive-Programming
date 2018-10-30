#include <iostream>
using namespace std;
int main ()
{
	long long arr[100]={0},min1=1000000000,min2=1000000001,m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>arr[i];
		if(arr[i]<min1)
		min1=arr[i];
		if(arr[i]!=min1&&arr[i]<min2)
		min2=arr[i];
	}
	for(int i=2;i<=min2;i++)
	{
		bool flag=1;
		long long temp=arr[0]%i;
		for(int j=1;j<m;j++)
		{
			if(arr[j]%i!=temp)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		cout<<i<<" ";
	}
	return 0;
}
