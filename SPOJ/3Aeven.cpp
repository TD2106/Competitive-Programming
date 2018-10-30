#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool mycmp(int a,int b)
{
	return a>b;
}
int main ()
{
	char temp;
	long long unsigned n,k,value[27]={0},index=0,point=0;
	cin>>n>>k;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		value[temp-'A']++;
	}
	sort(value,value+27,mycmp);
	while(k)
	{
		if(value[index]>=k)
		{
			point+=k*k;
			k-=k;
		}
		else
		{
			point+=value[index]*value[index];
			k-=value[index];
			index++;
		}
	}
	cout<<point;
	return 0;
}
