#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	long long int tich=1,tong=0;
	for(int i=1;i<=n;i++)
	{
		tich=1;
		for(int j=i;j<=2*i;j++)
		{
			tich=tich*j;
		}
		tong=tong+tich;
	}
	cout<<tong;
}
