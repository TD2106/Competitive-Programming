#include <iostream>
using namespace std;
int x[100],n,k;
void lietke(int n,int i,int k)
{
	for(int j=x[i-1]+1;j<=n-k+i+1;j++)
	{
		x[i]=j;
		if(i==k-1)
		{
			for(int l=0;l<k;l++)
			cout<<x[l]<<" ";
			cout<<endl; 
		}
		else
		{
			lietke(n,i+1,k);
		}
	}
}
int main ()
{
	cout<<"Nhap n: ";
	cin>>n;
	cout<<"Nhap k: ";
	cin>>k;
	lietke(n,0,k);
}
