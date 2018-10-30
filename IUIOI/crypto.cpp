#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main ()
{
	double n,p;
	while(cin>>n>>p)
	{
		printf("%.0lf\n",pow(p,1.0/n));
	}
	return 0;
}
