#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
struct obj
{
	int value;
	int time;
};
bool cmp(obj a,obj b)
{
	return (a.value>b.value);
}
int main ()
{
	int n,q,temp,sum[100001]={0};
	obj arr[100001];
	memset(arr,0,sizeof(arr));
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>arr[i].time;
	for(int i=1;i<=n;i++)
	cin>>arr[i].value;
	sort(arr+1,arr+n+1,cmp);
	for(int i=1;i<=n;i++)
	sum[i]+=sum[i-1]+arr[i].time;
	while(q--)
	{
		cin>>temp;
		cout<<sum[temp]<<endl;
	}
}
