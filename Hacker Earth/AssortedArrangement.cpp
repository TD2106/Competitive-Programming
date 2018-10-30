#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,num[100010]={0},original[100010]={0},paint[51]={0};
bool check(int value,int startpoint)
{
	for(int i=startpoint;i<=m;i++)
	{
		if(value%paint[i]==0)
		return 0;
	}
	return 1;
}
int main (){
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	cin>>paint[i];
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		original[i]=paint[num[i]];
	}
	for(int i=1;i<=n;i++)
	{
		int j=original[i-1]/original[i]+1;
		while(original[i]<=original[i-1])
		{
			if(j*original[i]>original[i-1]&&check(j*original[i],num[i]+1))
			original[i]*=j;
			else j++;
		}
	}
	cout<<original[n]<<endl;
	return 0;
}
