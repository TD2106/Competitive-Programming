#include <iostream>
using namespace std;
int main ()
{
	int n,dem=0,i=1,j=2;
	cin>>n;
	float tich=1;
	while(dem!=n)
	{
		if(dem%2==0)
		{
			float a=j*1.0/i;
			tich=tich*a;
		}
		else
		{
			float a=i*1.0/j;
			tich=tich*a;
		}
		dem++;
		i++;
		j++;
	}
	cout<<tich;
	return 0;
}
