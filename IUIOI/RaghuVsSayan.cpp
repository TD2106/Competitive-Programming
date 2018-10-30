#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main ()
{
	int tc,a,b,n;
	vector<int> plate,sum;
	cin>>tc;
	while(tc--)
	{
		cin>>a>>b>>n;
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			plate.push_back(temp);
		}
		sort(plate.begin(),plate.end());
		sum.push_back(plate[0]);
		for(int i=1;i<n;i++)
		sum.push_back(sum[i-1]+plate[i]);
		int mn=min(a,b);
		int mx=max(a,b);
		vector<int>::iterator itrmn,itrmx;
		itrmn=upper_bound(sum.begin(),sum.end(),mn);
		itrmx=upper_bound(sum.begin(),sum.end(),mx);
		itrmn--;
		itrmx--;
		if(itrmn==itrmx)
		cout<<"Tie\n";
		else
		{
			if(mx==a)
			cout<<"Raghu Won\n";
			else
			cout<<"Sayan Won\n";
		}
		plate.clear();
		sum.clear();
	}
	return 0;
}
