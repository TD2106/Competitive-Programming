#include <iostream>
using namespace std;
int main ()
{
	int arr[100001]={0},be,en,avg,max=0,n,temp;
	long long sum[100001]={0};
	cin>>n>>avg;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		sum[i]+=sum[i-1]+arr[i];
		for(int j=1;j<=i;j++)
		{
			temp=sum[i]-sum[j-1];
			temp/=(i-j+1);
			if(temp>=avg)
			{
				if((i-j+1)>max)
				{
					max=i-j+1;
					be=j;
					en=i;
				}
				break;
			}
		}
	}
	cout<<max<<"\n"<<be<<" "<<en;
	return 0;
}
