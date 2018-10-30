#include <iostream>
using namespace std;
int x[100];
void lietke(int n,int i)
{
	int *a=&x[i];
	for(int j=0;j<=1;j++)
	{
		*a=j;
		if(i==n-1)
		{
			for(int k=0;k<n;k++)
			cout<<x[k];
			cout<<endl;
		}
		else
		{
			lietke(n,i+1);
		}
	}
}
int main ()
{
	int n;
	cin>>n;
	lietke(n,0);
}
