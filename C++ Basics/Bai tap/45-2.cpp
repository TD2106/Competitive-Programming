#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	float temp;
	double s=0;
	for(int i=1;i<=10;i++)
	{
		cin>>temp;
		s=s+pow(temp,i);
	}
	cout<<s;
}
