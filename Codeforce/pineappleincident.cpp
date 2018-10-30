#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int x,t,s;
	cin>>t>>s>>x;
	if(x<t)
	cout<<"NO";
	else if(x==t)
	cout<<"YES";
	else
	{
		x-=t;
		if(x<s)
		cout<<"NO";
		else if(x%s==0||(x-1)%s==0)
		cout<<"YES";
		else
		cout<<"NO";
	}
	return 0;
}
