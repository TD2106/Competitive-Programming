#include <iostream>
using namespace std;
int findmax(int a, int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int main ()
{
	int m,n,cost[500][500],length[500][500];
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>cost[i][j];
			if(i==0&&j==0)
			length[i][j]=cost[i][j];
			else if(i==0)
			length[i][j]=length[i][j-1]+cost[i][j];
			else if(j==0)
			length[i][j]=cost[i][j]+length[i-1][j];
			else
			{
				length[i][j]=cost[i][j]+findmax(length[i-1][j],length[i][j-1]);
			}
		}
	}
	cout<<length[m-1][n-1];
	return 0;
}
