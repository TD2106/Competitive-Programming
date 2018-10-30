#include <iostream>
using namespace std;
int main ()
{
	int mi=0,ch=0,in1,in2,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>in1>>in2;
		if(in1>in2)
		mi++;
		else if(in1<in2)
		ch++;
	}
	if(mi>ch)
	cout<<"Mishka";
	else if(mi<ch)
	cout<<"Chris";
	else
	cout<<"Friendship is magic!^^";
	return 0;
}
