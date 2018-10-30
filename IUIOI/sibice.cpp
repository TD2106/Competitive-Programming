#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n,w,h,temp;
	cin>>n>>w>>h;
	int length=(int)sqrt(w*w+h*h);
	while(n--)
	{
		cin>>temp;
		if(temp<=length)
		cout<<"DA\n";
		else
		cout<<"NE\n";
	}
	return 0;
}
