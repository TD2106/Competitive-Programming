#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;
int main ()
{
	long long tc,q,s,d,n,input,res;
	pair< vector<long long>::iterator,vector<long long>::iterator > bounds;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		vector< vector<long long> > grid;
		vector<long long> temp;
		for(int i=0;i<n;i++)
		{
			temp.clear();
			for(int j=0;j<n;j++)
			{
				cin>>input;
				temp.push_back(input);
			}
			sort(temp.begin(),temp.end());
			grid.push_back(temp);
		}
		cin>>q;
		while(q--)
		{
			res=1;
			cin>>s>>d;
			if(d-s!=n+1)
			{
				cout<<0<<endl;
				continue;
			}
			for(int i=0;i<n;i++)
			{
				bounds=equal_range(grid[i].begin(),grid[i].end(),s+1);
				bounds.second--;
				if(bounds.first==grid[i].end()||*bounds.first!=s+1)
				{
					res=0;
					break;
				}
				else
				{
					res*=(bounds.second-bounds.first+1);
					res%=1000000007;
					s++;
				}
			}
			cout<<res<<endl;
		}
	}
}
