#include <iostream>
using namespace std;
int tinhtong(int n,int a,int d)
{
	int s=0,i=a+(n-1)*d;
	if(n==0)
	{
		return 0;
	}
	else 
	return s=s+i+tinhtong(n-1,a,d);
}
int main ()
{
	cout<<tinhtong(5,12,3);
}
