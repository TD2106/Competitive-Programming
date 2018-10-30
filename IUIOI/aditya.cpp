#include <iostream>
using namespace std;
int main ()
{
	long long n,sum=0,numof1=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		sum+=(i+1)/2+1;
		else
		sum+=(i+1)/2;
	}
	cout<<sum;
}
