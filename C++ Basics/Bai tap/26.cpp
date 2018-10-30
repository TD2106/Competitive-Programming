#include <iostream>
using namespace std;
int main()
{
	int n,m,s=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		s=s+n%10;
		n=n/10;
	}
	cout<<s;
}
