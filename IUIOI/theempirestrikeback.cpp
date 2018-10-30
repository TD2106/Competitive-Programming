#include <iostream>
using namespace std;
int main ()
{
	long long temp,n,k,sum=0;
	cin>>n>>k;
	while(n--)
	{
		cin>>temp;
		if(temp<=k)
		sum+=temp;
	}
	cout<<sum<<endl;
}
