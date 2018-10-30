#include <iostream>
#include <cmath>
using namespace std;
int giaithua(int n)
{
	if(n==0)
	return 1;
	else
	return n*giaithua(n-1);
}
int main()
{
	int n;
	cin>>n;
	float s=0;
	for(int i=1;i<=n;i++)
	s=s+pow(-1,i*(i-1)*1.0/2)*1.0/giaithua(i);
	cout<<s;
}
