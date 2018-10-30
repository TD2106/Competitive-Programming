#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;
long long arr[2000010];
vector<long long> num;
long long cal(long long n)
{
	return (n-1)*n/2;
}
int main ()
{
	long long temp,tc,n,ans;
	cin>>tc;
	while(tc--)
	{
		ans=0;
		cin>>n;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(temp<0)
			{
				temp*=-1;
				temp+=1000000;
			}
			if(arr[temp]==0)
			num.push_back(temp);
			arr[temp]++;
		}
		for(int i=0;i<num.size();i++)
		{
			if(arr[num[i]]==1)
			ans+=1;
			else
			ans+=arr[num[i]]+cal(arr[num[i]]);
		}
		cout<<ans<<endl;
		num.clear();
	}
	return 0;
}
