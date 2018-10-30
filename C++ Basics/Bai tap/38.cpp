#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=sqrt(n);i++)
	{
		int a=pow(i,2),b=pow(i,3);
		if(n%a==0&&n%b!=0)
		cout<<i<<" ";
	}
	return 0;
}
