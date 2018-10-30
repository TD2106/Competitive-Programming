#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	int pow2[32]={0};
	pow2[0]=1;
	for(int i=1;i<32;i++)
	{
		pow2[i]=pow2[i-1]*2;
	}
	int n,arr[100001],sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int temp=arr[i]+arr[j];
			for(int k=0;k<32,pow2[k]<=temp;k++)
			if(pow2[k]==temp)
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
