#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
int main ()
{
	//freopen("test.txt","r",stdin);
	map<int,int> total;
	map<int,int> sub;
	int n,ele=0,elesub=0,arr[200010]={0};
	long long cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(total[arr[i]]==0)
		ele++;
		total[arr[i]]++;
	}
	int j=0;
	for(int i=0;i<n;i++)
	{
		while(j<n&&elesub<ele)
		{
			if(sub[arr[j]]==0)
			elesub++;
			sub[arr[j]]++;
			j++;
		}
		if(elesub==ele)
		cnt++;
		sub[arr[i]]--;
		if(sub[arr[i]]==0)
		elesub--;
	}
	cout<<cnt;
	return 0;
}
