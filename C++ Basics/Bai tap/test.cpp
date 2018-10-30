#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int dem=0,n=0;
	while(dem<2)
	{
		dem=0;
		n++;
		for(int i=1;i<=pow(n,1./3);i++)
		{
			float j=(n*1.0-pow(i,3)*1.0);
			j=pow(j,1./3);
			int x=int(j);
			if(x<=i&&pow(i,3)+pow(x,3)==n)
			dem++;
		}
	}
	cout<<n;
}
