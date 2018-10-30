#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int testcase;
	cin>>testcase;
	int n,a,b,min,max;
	while(testcase--)
	{
		cin>>n>>a>>b;
		min=a-b;
		if(min<0)
		min=0;
		max=n-b;
		if(max>a)
		max=a;
		cout<<min<<" "<<max<<"\n";
	}
	return 0;
}
