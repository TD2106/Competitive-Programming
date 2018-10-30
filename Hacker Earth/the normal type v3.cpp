#include <iostream>
#include <map>
using namespace std;
int main ()
{
	long long cnt=0;
	int n,arr[200010]={0},j=0;
	map<int,int> total,sub;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		total[arr[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		j=max(j,i);
		while(j<n&&sub.size()<total.size())
		{
			sub[arr[j]]++;
			j++;
		}
		if(sub.size()==total.size())
		cnt+=n-(j-1);
		sub[arr[i]]--;
		if(sub[arr[i]]==0)
		sub.erase(arr[i]);
	}
	cout<<cnt<<endl;
	return 0;
}
