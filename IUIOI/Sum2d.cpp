#include <iostream>
using namespace std;
int main ()
{
	int array[205][205],m,n,x,y,p,q,t;
	long long int sum;
	cin>>m>>n>>t;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>array[i][j];
	}
	while(t--)
	{
		sum=0;
		cin>>x>>y>>p>>q;
		for(int i=x;i<=p;i++)
		for(int j=y;j<=q;j++)
		sum=sum+array[i][j];
		cout<<sum<<"\n";
	}
	return 0;
}
