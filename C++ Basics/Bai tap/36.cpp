#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	float temp,s=0,r=0;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(temp<=1)
		r=r+temp;
		else
		s=s+temp;
	}
	cout<<(1+r)*1.0/(1+s);
}
