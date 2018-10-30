#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int testcase,temp,street,avenue,friends,tempx,tempy,a,b;
	vector<int> x;
	vector<int> y;
	freopen("855.txt","r",stdin);
	cin>>testcase;
	while(testcase--)
	{
		cin>>street>>avenue>>friends;
		while(friends--)
		{
			cin>>tempx;
			x.push_back(tempx);
			cin>>tempy;
			y.push_back(tempy);
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		if(x.size()%2)
		a=x[x.size()/2];
		else
		a=x[x.size()/2-1];
		if(y.size()%2)
		b=y[y.size()/2];
		else
		b=y[y.size()/2-1];
		cout<<"(Street: "<<a<<", Avenue: "<<b<<")\n";
		x.clear();
		y.clear();
	}
	return 0;
}
