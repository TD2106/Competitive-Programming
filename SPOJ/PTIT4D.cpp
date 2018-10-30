#include <iostream>
#include <cstring>
using namespace std;
int mark[1000001];
int times[1000001];
int main ()
{
	//freopen("4D.txt","r",stdin);
	char arr[1000001]={0};
	memset(mark,0,1000001*sizeof(int));
	memset(times,0,1000001*sizeof(int));
	times[0]=1;
	int k,n,temp,i;
	long long sum=0,zero=0;
	cin>>k;
	cin.ignore();
	for(i=1;cin>>arr[i];i++)
	{
		if(arr[i]=='1')
		mark[i]=1+mark[i-1];
		else
		mark[i]=mark[i-1];
		times[mark[i]]++;
	}
	i--;
	if(k==0)
	{
		temp=0;
		for(int j=1;j<=i;j++)
		{
			if(arr[j]=='1')
			{
				temp=0;
			}
			else
			{
				temp++;
				zero+=temp;
			}
		}
		cout<<zero;
		return 0;
	}
	temp=mark[i];
	while(temp>=k)
	{
		long long a=(long long)times[temp];
		long long b=(long long)times[temp-k];
		sum+=a*b;
		temp--;
	}
	cout<<sum;
	return 0;
}
