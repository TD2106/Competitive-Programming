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
	int arr[2][100001]={0};
	int n,maximum=0,length;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		length=1;
		cin>>arr[0][i];
		if(arr[0][i-1]<arr[0][i])
		arr[1][i]=1+arr[1][i-1];
		else
		arr[1][i]=1;
		maximum=max(arr[1][i],maximum);
	}
	cout<<maximum;
	return 0;
}
