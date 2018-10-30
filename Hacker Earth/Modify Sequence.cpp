#include <iostream>
using namespace std;

int main()
{
    int n,arr[10001]={0};
    bool flag=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    if(n==1)
   	{
   		flag=1;
	}
   	else if (arr[1]>arr[2]||arr[n-1]<arr[n])
   	{
   		flag=1;
	}
   	else
   	{
   		for(int i=1;i<=n-1;i++)
   		{
   			arr[i+1]-=arr[i];
   			arr[i]=0;
   			if(arr[i+1]<0)
   			{
   				flag=1;
   				break;
   			}
   		}
   		if(arr[n]>0)
   		{
   			flag=1;
		}
   	}
   	if(flag)
   	cout<<"NO\n";
   	else
   	cout<<"YES\n";
   	return 0;
}
