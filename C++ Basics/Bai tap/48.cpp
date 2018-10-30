#include <iostream>
using namespace std;
int main ()
{
	int s=0,a,max=0;
	for(int i=1;i<=10000;i++)
	{
		s=0;
		for(int j=1;j<=i;j++)
		if(i%j==0)
		s=s+j;
		if(s>max)
		{
			max=s;
			a=i;
		}
	}
	
	cout<<a;
}
