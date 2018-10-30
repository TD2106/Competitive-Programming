#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	int first=1;
	bitset<102> prev;
	bitset<102> seat;
	bitset<102> res;
	int tc,n,m,pren=-1,prem=-1;
	cin>>tc;
	while(tc--)
	{
		bool temp;
		cin>>n>>m;
		seat.reset();
		for(int i=1;i<=n;i++)
		{
			cin>>temp;
			seat[i]=temp;
		}
		seat[0]=seat[n+1]=1;
		if(first==1)
		{
			prev=seat;
			prem=m;
			pren=n;
			first++;
		}
		else
		{
			if(prev==seat&&prem==m&&pren==n)
			{
				for(int i=1;i<=n;i++)
				cout<<res[i]<<" ";
				cout<<endl;
				continue;
			}
		}
		bitset<102> compare;
		while(m--)
		{
			compare=seat;
			for(int i=1;i<=n;i++)
			{
				if(compare[i-1]&compare[i+1])
				seat[i]=1;
				else
				seat[i]=0;
			}
			if(seat==compare)
			break;
		}
		for(int i=1;i<=n;i++)
		cout<<seat[i]<<" ";
		cout<<endl;
		res=seat;
	}
	return 0;
}
