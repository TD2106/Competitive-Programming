#include <iostream>
using namespace std;
int main ()
{
	int n,m,L,R;
	long long int sum;
	cin>>n>>m;
	int arr[100005];
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	while(m--)
	{
		cin>>L>>R;
		sum=0;
		for(int i=L;i<=R;i++)
		sum+=arr[i];
		cout<<sum<<"\n";
	}
	return 0;
}
