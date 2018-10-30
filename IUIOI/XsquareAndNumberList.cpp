#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
long long sum[500010];
void precompute()
{
	long long tich=1;
	sum[0]=1;
	sum[1]=2;
	for(int i=2;i<=500000;i++)
	{
		tich*=2;
		tich%=1000000007;
		sum[i]=(sum[i-1]+tich)%1000000007;
	}
}
int main ()
{
	ios_base::sync_with_stdio(false);
	char tmp;
	precompute();
	long long n,q,ask,temp,res;
	string s;
	vector<long long> taphop;
	vector<long long>::iterator itr;
	pair<vector<long long>::iterator,vector<long long>::iterator> bounds;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		taphop.push_back(temp);
	}
	taphop.push_back(0);
	sort(taphop.begin(),taphop.end());
	while(q--)
	{
		res=0;
		cin>>tmp>>temp;
		if(tmp=='>')
		{
			itr=upper_bound(taphop.begin(),taphop.end(),temp);
			if(itr==taphop.end())
			cout<<0<<endl;
			else
			{
				temp=itr-taphop.begin();
				temp--;
				res=sum[n]-sum[temp]+1000000007;
				cout<<res%1000000007<<endl;
			}
		}
		else if(tmp=='<')
		{
			itr=lower_bound(taphop.begin(),taphop.end(),temp);
			itr--;
			temp=itr-taphop.begin();
			res=sum[temp];
			cout<<res%1000000007<<endl;
		}
		else
		{
			bounds=equal_range(taphop.begin(),taphop.end(),temp);
			bounds.second--;
			if(bounds.first==taphop.end())
			cout<<0<<endl;
			else
			{
				long long temp2;
				temp=bounds.first-taphop.begin();
				temp2=bounds.second-taphop.begin();
				temp--;
				res=sum[temp2]-sum[temp]+1000000007;
				cout<<res%1000000007<<endl;
			}
		}
	}
	return 0;
}
