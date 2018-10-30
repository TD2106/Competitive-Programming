#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int testcase,n,m,temp;
	vector<int> an;
	vector<int> binh;
	cin>>testcase;
	while(testcase--)
	{
		long long int suman=0,sumbinh=0;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			an.push_back(temp);
		}
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			binh.push_back(temp);
		}
		sort(an.begin(),an.end());
		sort(binh.begin(),binh.end());
		for(int i=0;i<m;i++)
		{
			suman=suman+an[i];
			sumbinh=sumbinh+binh[n-1-i];
		}
		if(suman>sumbinh)
		cout<<"YES\n";
		else
		cout<<"NO\n";
		an.clear();
		binh.clear();
	}
	return 0;
}
