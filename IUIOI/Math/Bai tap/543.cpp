#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>
int n;
using namespace std;
int main ()
{
	int test;
	//freopen("406.txt","r",stdin);
	bitset<1000001> mark;
	mark[0]=mark[1]=1;
	for(int i=2;i<=sqrt(1000000);i++)
	{
		if(!mark[i])
		{
			for(int j=2*i;j<=1000000;j+=i)
			mark[j]=1;
		}
	}
	while(cin>>n&&n)
	{
		
		int test=1;
		for(int i=n-1;i>=n/2;i-=2)
		{
			if(!mark[n-i]&!mark[i])
			{
				cout<<n<<" = "<<n-i<<" + "<<i<<"\n";
				test=0;
				break;
			}
		}
		if(test)
		{
			cout<<"Goldbach's conjecture is wrong.\n";
		}
	}
	return 0;	
}
