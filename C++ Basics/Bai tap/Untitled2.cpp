#include <iostream>
#include <cmath>
using namespace std;
int check(long int n)
{
	int check = 1;
	if(n==1)
	return check = 0;
	if(n==3||n==5||n==7)
	return check=1;
	else
	{
		for(long int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			check = 0;
		}
	}
	return check;
}
int main ()
{
	cout <<check(9);
}
