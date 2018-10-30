#include <iostream>
#include <algorithm>
using namespace std;
int main  ()
{
	int n,arr[50]={0},sum1=0,sum2=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n/2;i++)
	sum1+=arr[i];
	for(int i=n/2;i<n;i++)
	sum2+=arr[i];
	cout<<sum2-sum1;
	return 0;
}
