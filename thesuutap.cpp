#include <iostream>
using namespace std;
int uocchung(int a,int b)
{
	if(a*b==0)
	return a+b;
	else
	{
		uocchung(b%a,a);
	}
}
int main ()
{
	int N,a,b;
	cin>>N;
	while(N--)
	{
		cin>>a>>b;
		cout<<uocchung(a,b)<<endl;
	}
	return 0;
}
