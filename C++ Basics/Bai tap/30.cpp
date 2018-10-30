#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	float a=1,b=1;
	int n;
	cin>>n;
	float tong=1;
	for(int i=2;i<=n;i++)
	{
		a=0.5*(sqrt(b)+0.5*sqrt(a));
		b=2*pow(a,2)+b;
		tong=tong+a*b;
	}
	cout<<tong;
	return 0;
}
