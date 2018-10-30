#include <iostream>
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
	int n,zigzag[50][2],arr[50]={0},total=0;
	cin>>n;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<50;j++)
		zigzag[j][i]=1;
	}
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			zigzag[i][0]=max(zigzag[i][0],1+zigzag[j][1]);
			else if(arr[j]>arr[i])
			zigzag[i][1]=max(zigzag[i][1],1+zigzag[j][0]);
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<50;j++)
		total=max(total,zigzag[j][i]);
	}
	cout<<total;
	return 0;
}
