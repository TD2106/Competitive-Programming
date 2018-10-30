#include <iostream>
using namespace std;
int main ()
{
	int i=0,s=0,n;
	cin>>n;
	while(n>0)
	{
		s=s+n%10;
		n=n/10;
		i++;
	}
	cout<<i<<endl;
	cout<<s<<endl;
}
