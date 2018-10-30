#include <iostream>
#include <cstdio>
using namespace std;
double factorial(int n)
{
	if(n==1||n==0)
	return 1;
	else
	return n*factorial(n-1);
}
int main ()
{
	int n;
	cin>>n;
	if(n==3)
	cout<<"0";
	else
	printf("%.0lf",factorial(n)/(factorial(n-4)*24));
	return 0;
}
