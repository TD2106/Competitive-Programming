#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	int n,tempprice,q,query;
	vector<int> price;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tempprice;
		price.push_back(tempprice);
	}
	sort(price.begin(),price.end());
	cin>>q;
	while(q--)
	{
		cin>>query;
		vector<int>::iterator itr;
		itr=upper_bound(price.begin(),price.end(),query);
		if(itr==price.end())
		{
			if(query>=price[n-1])
			cout<<n<<"\n";
			else
			cout<<"0\n";
		}
		else
		{
			int ans=itr-price.begin();
			cout<<ans<<"\n";
		}
	}
	return 0;
}
