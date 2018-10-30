#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int main ()
{
	ios_base::sync_with_stdio(0); 
	priority_queue<int> mx;
	priority_queue< int,vector<int>,greater<int> > mn;
	int arr[100001],q,x,com;
	memset(arr,0,sizeof(arr));
	cin>>q;
	while(q--)
	{
		cin>>com;
		if(com==1)
		{
			cin>>x;
			arr[x]++;
			mx.push(x);
			mn.push(x);
		}
		else if(com==2)
		{
			cin>>x;
			if(arr[x]==0)
			cout<<"-1\n";
			else
			arr[x]--;
		}
		else if(com==3)
		{
			while(mx.size()&&arr[mx.top()]==0)
			mx.pop();
			if(mx.size())
			cout<<mx.top()<<"\n";
			else
			cout<<"-1\n";
		}
		else if(com==4)
		{
			while(mn.size()&&arr[mn.top()]==0)
			mn.pop();
			if(mn.size())
			cout<<mn.top()<<"\n";
			else
			cout<<"-1\n";
		}
	}
	return 0;
}
