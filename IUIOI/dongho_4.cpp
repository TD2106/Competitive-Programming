#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	long long int n,x,y,k,t;
	//freopen("dongho.txt","r",stdin);
	cin>>n;
	while(n--)
	{
		cin>>x>>y>>k>>t;
		if(y==1)
		{
			cout<<x+t<<endl;
			continue;
		}
		if(!x%y)
		{
			x++;
			t--;
		}
		if(k>t)
		{
			long long int check;
			check=x/y+1;
			x=(check+t)*y;
			cout<<x<<"\n";
		}
		else
		{
			long long int x1;
			long long int check;
			check=x/y+1;
			x1=(check+(k-1))*y+(t-(k-1));
			if(x+t>check*y)
			{
				long long int temp=x;
				x=(check*y+1);
				check=x/y+1;
				t=t-(x-temp);
				if(k>t)
				x=(check+t)*y;
				else
				x=(check+(k-1))*y+(t-(k-1));
			}
			if(x1>x)
			{
				cout<<x1<<"\n";
			}
			else
			{
				cout<<x<<"\n";
			}
		}
	}
	return 0;
}
