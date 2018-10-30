#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	float temp,max=0,min=100;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(temp>max)
		max=temp;
		if(temp<min)
		min=temp;
	}
	cout<<max-min;
}
