#include <iostream>
using namespace std;
int main ()
{
	long long fibo[1001];
	fibo[0]=0;
	fibo[1]=1;
	for(int i=2;i<=1000;i++)
	{
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	int n;
	while(cin>>n)
	{
		cout<<fibo[n]<<"\n";
	}
	return 0;
}
