#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n,check=1;
	cin>>n;
	for(int i=1;i<=sqrt(n);i++)
	{
		for(int j=1;j<=i;j++)
		if(pow(i,2)+pow(j,2)==n)
		{
			cout<<i<<" "<<j<<endl;
			check=0;
		}
	}
	if(check)
	cout<<"So n ko thoa";
}
