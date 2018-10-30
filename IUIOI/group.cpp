#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n,m;
	cin>>n>>m;
	if(!(n%m))
	cout<<m<<" group(s) of "<<n/m;
	else
	{
		cout<<m-n%m<<" group(s) of "<<n/m<<"\n";
		cout<<n%m<<" group(s) of "<<n/m+1<<"\n";
	}
	return 0;
}
