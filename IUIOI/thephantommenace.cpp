#include <iostream>
using namespace std;
int main ()
{
	int n,arr[10002]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	for(int i=1;i<=n;i++)
	{
		if(!arr[i])
		{
			for(int j=1;j<=4;j++)
			{
				if(j!=arr[i-1]&&j!=arr[i+1])
				{
					arr[i]=j;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	cout<<arr[i];
	return 0;
}
