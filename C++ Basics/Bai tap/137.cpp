#include <iostream>
using namespace std;
int check(int i)
{
	int s1=0,s2=0;
	for(int j=0;j<3;j++)
	{
		s1=s1+i%10;
		i=i/10;
	}
	for(int j=0;j<3;j++)
	{
		s2=s2+i%10;
		i=i/10;
	}
	if(s1==s2)
	return 1;
	else
	return 0;
}
int main ()
{
	for(int i=100000;i<=999999;i++)
	if(check(i))
	cout<<i<<" la so hanh phuc"<<endl;
	return 0;
}
