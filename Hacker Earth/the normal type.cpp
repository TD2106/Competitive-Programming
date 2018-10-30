#include <iostream>
#include <map>
#include <set>
using namespace std;
int main ()
{
	int n,arr[200001]={0},j=0;
	long long ans=0;
	map<int,int> check;
	set<int> pa;
	set<int> ch;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		pa.insert(arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		j=max(i,j);
		while(j<n&&ch.size()!=pa.size())
		{
			if(check[arr[j]]==0)
			ch.insert(arr[j]);
			check[arr[j]]++;
			j++;
		}
		if(ch.size()==pa.size())
		{
			ans+=n-(j-1);
		}
		check[arr[i]]--;
		if(check[arr[i]]==0)
		ch.erase(arr[i]);
	}
	cout<<ans<<endl;
}
