#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q,inquiry;
	int temp,answer[100002]={0};
	vector< pair<int,int> > current;
	current.push_back(make_pair(0,0));
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		current.push_back(make_pair(i,temp));
	}
	while(n)
	{
		vector< pair<int,int> > next;
		next.push_back(make_pair(0,0));
		if(n==1)
		break;
		for(int i=1;i<=n;i+=2)
		{
			if(i==n)
			next.push_back(current[n]);
			else
			{
				answer[current[i].first]++;
				answer[current[i+1].first]++;
				if(current[i].second>current[i+1].second)
				next.push_back(current[i]);
				else
				next.push_back(current[i+1]);
			}
		}
		if(n%2)
		n=n/2+1;
		else
		n/=2;
		current=next;	
	}
	while(q--)
	{
		cin>>inquiry;
		cout<<answer[inquiry]<<endl;
	}
	return 0;
}
