#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
int n,c;
bool check(int i)
{
	return (i>=n);
}
using namespace std;
int main ()
{
	//freopen("406.txt","r",stdin);
	vector<int> prime;
	bitset<1001> mark;
	prime.push_back(1);
	for(int i=2;i<=1000;i++)
	{
		if(!mark[i])
		{
			prime.push_back(i);
			for(int j=2*i;j<=1000;j+=i)
			mark[j]=1;
		}
	}
	
	while(cin>>n>>c)
	{
		vector<int>::iterator itr=find_if(prime.begin(),prime.end(),check);
		int size;
		if(*itr!=n)
		size=itr-prime.begin();
		else
		size=itr-prime.begin()+1;
		cout<<n<<" "<<c<<":";
		if(size%2)
		{
			if(c*2-1>=size)
			{
				for(int i=0;i<size;i++)
				cout<<" "<<prime[i];
				cout<<"\n";
			}
			else
			{
				for(int i=size/2-(c*2-1)/2;i<=size/2+(c*2-1)/2;i++)
				cout<<" "<<prime[i];
				cout<<"\n";
			}
		}
		else
		{
			if(c*2>=size)
			{
				for(int i=0;i<size;i++)
				cout<<" "<<prime[i];
				cout<<"\n";
			}
			else
			{
				for(int i=size/2-c;i<=size/2-1+c;i++)
				cout<<" "<<prime[i];
				cout<<"\n";
			}
		}
		cout<<"\n";
	}
	return 0;	
}
