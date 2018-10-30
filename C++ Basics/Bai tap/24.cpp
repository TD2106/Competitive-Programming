#include <iostream>
using namespace std;
int main()
{
	int i=1;float a;
	cin>>a;
	float s=0;
	while(s<=a)
	{
		s=s+1.0/i;
		i++;
	}
	cout<<i;
}
