#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	// idea is like LCS in DP
	int h[1010]={0},g[1010]={0},acch[1010]={0},accg[1010]={0},n,maxgold=0,maxheight=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i],acch[i]=h[i];
	for(int i=1;i<=n;i++) cin>>g[i],accg[i]=g[i];
	maxgold=accg[1],maxheight=acch[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>0;j--)
		{
			if(h[i]<h[j])
			{
				if(accg[j]+g[i]>accg[i]) accg[i]=accg[j]+g[i],acch[i]=acch[j]+h[i];
				else if(accg[j]+g[i]==accg[i]) acch[i]=max(acch[i],acch[j]+h[i]);
			}
		}
		if(accg[i]>maxgold) maxgold=accg[i],maxheight=acch[i];
		else if(accg[i]==maxgold) maxheight=max(maxheight,acch[i]);
	}
	cout<<maxheight<<" "<<maxgold;
	return 0;
}
