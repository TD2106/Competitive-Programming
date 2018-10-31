#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main ()
{
	double a,b,x,y,min=pow(2,32),tempdis,tempspeed,speed,vas;
	int n;
	cin>>a>>b;
	a*=1.000000000;
	b*=1.000000000;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>tempspeed;
		x*=1.000000000;
		y*=1.000000000;
		tempspeed*=1.000000000;
		tempdis=sqrt(pow(x-a,2)+pow(y-b,2))*1.000000000;
		vas=tempdis/tempspeed;
		if(vas<min)
		{
			min=vas;
		}
	}
	printf("%.9llf",min);
	return 0;
}
