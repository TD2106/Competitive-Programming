#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	bitset<5005> mark;
	int n,sum=0,temp;
	cin>>n;
	sum=n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(!mark[temp]&&temp<=n)
		{
			mark[temp]=1;
			sum--;
		}
	}
	cout<<sum;
	return 0;
}
