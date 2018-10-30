#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;
int main ()
{
	map< string,vector<int> > data;
	int n,q,l,r;
	string s;
	cin>>n;
	cin.ignore();
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		data[s].push_back(i);
	}
	cin.ignore();
	cin>>q;
	while(q--)
	{
		cin>>l>>r>>s;
		if(data.count(s)>0)
		{
			pair<vector<int>::iterator,vector<int>::iterator> bounds;
			bounds.first=lower_bound(data[s].begin(),data[s].end(),l);
			if(bounds.first==data[s].end())
			cout<<"0"<<endl;
			else
			{
				bounds.second=upper_bound(data[s].begin(),data[s].end(),r);
				bounds.second--;
				cout<<bounds.second-bounds.first+1<<endl;
			}
		}
		else
		cout<<0<<endl;
	}
	return 0;
}
