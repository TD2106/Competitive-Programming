#include <iostream>
#include <bitset>
using namespace std;
int maximum(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}
int main ()
{
	int max=0;
	bitset<101> first;
	bitset<101> second;
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		first[i]=temp;
	}
	for(int i=0;i<n;i++)
	{
		second=first;
		for(int j=i;j<n;j++)
		{
			second[j]=!second[j];
			max=maximum(max,second.count());
		}
	}
	cout<<max;
	return 0;
}
