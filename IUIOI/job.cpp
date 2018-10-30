#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
long long n,temp1,temp2,sum=0,greatest[100001];
struct obj
{
	long long value;
	long long deadline;
};
bool cmp(const obj& a, const obj& b)
{
	return (a.value>b.value);
}
long long findslot(long long i)
{
	if(i==greatest[i])
	return i;
	else
	{
		return greatest[i]=findslot(greatest[i]);
	}
}
void update (long long a, long long b)
{
	greatest[a]=b;
}
int main ()
{
	bitset<100001> mark;
	obj arr[100001],temp;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		greatest[i]=i;
		cin>>temp1>>temp2;
		arr[i].deadline=temp1;
		arr[i].value=temp2;
	}
	greatest[n]=n;
	sort(arr,arr+n,cmp);
	for(long long i=0;i<n;i++)
	{
		long long available=findslot(min(arr[i].deadline,n));
		if(available>0)
		{
			sum+=arr[i].value;
			update(available,findslot(available-1));
		}
	}
	cout<<sum;
	return 0;
}
