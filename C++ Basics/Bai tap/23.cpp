#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	float x;
	double tu=1,mau=1;
	cin>>x;
	for(int i=1;i<=6;i++)
	{
		tu=(x-pow(2,i)*1.0)*tu;
		mau=mau*(x-pow(2,i)*1.0+1.0);
	}
	cout<<tu/mau;
}
