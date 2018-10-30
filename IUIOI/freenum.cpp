#include <iostream>
#include <cstring>
#include  <cmath>
using namespace std;
int digit(int n)
{
	int digit=0;
	while(n)
	{
		digit++;
		n/=10;
	}
	return digit;
}
int main ()
{
	unsigned long long arr[20]={0};
	for(int i=1;i<=18;i++)
	arr[i]=(unsigned long long)pow(11,i);
}
