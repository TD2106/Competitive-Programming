#include <iostream>
using namespace std;
int main ()
{
	int testcase,n,k;
	cin>>testcase;
	while(testcase--)
	{
		cin>>n>>k;
		printf("%d\n",k^(k>>1));
	}
	return 0;
}
