#include <iostream>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main ()
{
	bitset<46501> mark;
	mark[1]=1;
	vector<int> prime;
	for(int i=2;i<=46500;i++)
	{
		if(!mark[i])
		{
			prime.push_back(i);
			if(i<=sqrt(46500))
			{
				for(int j=2*i;j<=46500;j+=i)
				mark[j]=1;
			}
		}
	}
	int L,U,count,min,max,a,b,c,d;
	cout<<prime.size();
}
