#include <iostream>
using namespace std;
int fibo(int i)
{
	if(i==1||i==2)
	return 1;
	else
	return fibo(i-1)+fibo(i-2);
}
int main ()
{
	int s=0,i=1,n;
	cin>>n;
	while(1)
	{
		s=s+fibo(i);
		if(s==n)
		break;
		if(s>n)
		{
			cout<<"Ko the hien so n bang day fibonacci dc";
			exit(0);
		}
		i++;
	}
	i=1,s=0;
	while(1)
	{
		s=s+fibo(i);
		if(s==n)
		{
			cout<<fibo(i)<<"="<<n;
			break;
		}
		else
		{
			cout<<fibo(i)<<"+";
		}
		i++;
	}
}
