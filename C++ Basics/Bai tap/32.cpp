#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	float s=0,sb=0,sc=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s=s+1.0/pow(i,5);
		sb=sb+pow(-1,i)*1.0/((2*i+1)*i);
		sc=sc+pow(-1,i+1)*1.0/((i+1)*i);
	}
	cout<<s<<" "<<sb<<" "<<sc;
	
}
