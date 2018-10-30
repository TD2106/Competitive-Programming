#include <iostream>
using namespace std;
void xuli(int a, int b)
{
	int temp1=a,temp2=b;
	while(a*b!=0)
	{
		if(a>=b)
		a=a-b;
		else
		b=b-a;
	}
	int uoc=a+b;
	cout<<temp1/uoc<<"/"<<temp2/uoc;
}
int main ()
{
	int a,b;
	cin>>a>>b;
	xuli(a,b);
}
