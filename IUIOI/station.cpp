#include <iostream>
using namespace std;
int main ()
{
	int max=0,n,k,distance,mark,day=0;
	bool lodge[500005]={0},first=1;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>lodge[i];
		if(lodge[i]&&first)
		{
			first=0;
			mark=i;
		}
		else if (lodge[i])
		{
			distance=i-mark;
			if(distance>max)
			max=distance;
			mark=i;
		}
	}
	if(max>k)
	cout<<-1;
	else
	{
		max=0;
		for(int i=0;i<n;i++)
		{
			max=0;
			for(int j=1;j<=k;j++)
			{
				if(i+j>=n)
				break;
				if(lodge[i+j]==1)
				max=i+j;
			}
			i=max-1;
			day++;
			if(max==n-1)
			break;
		}
		cout<<day;
	}
	return 0;
}
