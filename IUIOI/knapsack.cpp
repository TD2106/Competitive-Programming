#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int main ()
{
	int S,N,weight[5001],value[5001],**table;
	cin>>N>>S;
	table=(int**)malloc((N+1)*sizeof(int*));
	table[0]=(int*)malloc((S+1)*sizeof(int));
	for(int i=1;i<=N;i++)
	{
		table[i]=(int*)malloc((S+1)*sizeof(int));
		cin>>weight[i];
		cin>>value[i];
	}
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=S;j++)
		{
			if(i==0||j==0)
			table[i][j]=0;
			else
			{
			    table[i][j]=max(table[i-1][j],table[i][j-1]);
				if(weight[i]<=j)
				table[i][j]=max(table[i][j],value[i]+table[i-1][j-weight[i]]);
			}
		}
	}
	cout<<table[N][S];
	return 0;
}
