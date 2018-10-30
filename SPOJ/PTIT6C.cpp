#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	if(n==0||n==1)
	cout<<4;
	else
	cout<<8*(n-1);
	return 0;
}
