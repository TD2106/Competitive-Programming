#include <iostream>
#include <bitset>
using namespace std;
int findmax(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int main ()
{
	int m,n;
	string A,B;
	cin>>m>>n>>A>>B;
	int length[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
			length[i][j]=0;
			else if(A[i-1]==B[j-1])
			length[i][j]=1+length[i-1][j-1];
			else
			length[i][j]=findmax(length[i][j-1],length[i-1][j]);
		}
	}
	cout<<length[m][n];
	return 0;
}
