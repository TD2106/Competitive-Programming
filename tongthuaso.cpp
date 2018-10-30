#include <iostream>
using namespace std;
double giaithua(double n)
{
	double tich;
	if(n==0||n==1)
	return 1;
	else
	return n*giaithua(n-1);
}
int main ()
{
	double a,b;
	cin>>a>>b;
	double sum=giaithua(a)+giaithua(b);
	printf("%.0lf",sum);
	return 0;
}
