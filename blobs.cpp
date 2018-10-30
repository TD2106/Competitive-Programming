#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n,sum;
	cin>>n;
	float kg,result;
	while(n--)
	{
		sum=0;
		cin>>kg;
		result=ceil(log(kg)/log(2));
		cout<<result;
	}
	return 0;
}
