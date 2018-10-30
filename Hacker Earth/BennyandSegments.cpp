#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return (a.first<b.first||a.first==b.first&&a.second<b.second);
}
int main ()
{
	vector< pair<int,int> > input;
	int tc,n,l;
	pair<int,int> temp;
	cin>>tc;
	while(tc--)
	{
		bool check=0;
		cin>>n>>l;
		for(int i=0;i<n;i++)
		{
			cin>>temp.first>>temp.second;
			input.push_back(temp);
		}
		sort(input.begin(),input.end(),cmp);
		for(int i=0;i<input.size();i++)
		{
			int maxright=input[i].first+l;
			int right=input[i].second;
			for(int j=i+1;j<input.size();j++)
			{
				if(input[j].first<=right&&input[j].second<=maxright)
				right=max(input[j].second,right);
			}
			if(right==maxright)
			{
				check=1;
				break;
			}
		}
		if(check)
		cout<<"Yes\n";
		else
		cout<<"No\n";
		input.clear();
	}
	return 0;
}
