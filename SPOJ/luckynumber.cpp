#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	unsigned long long result[56]={0};
	result[1]=2;
	for(int i=2;i<=55;i++)
	{
		result[i]=result[i-1]+(unsigned long long)pow(2,i);
	}
	int n;
	cin>>n;
	cout<<result[n];
	return 0;
}
