#include <iostream>
#include <map>
using namespace std;
map<int,int> fibo;
int tinhfibo(int n)
{
	if(n==1||n==2)
	return 1;
	else
	{
		if(fibo.count(n))
		return fibo[n];
		else
		{
			if(n%2)
			return fibo[n]=(tinhfibo(n/2)*tinhfibo(n/2)+tinhfibo(n/2+1)*tinhfibo(n/2+1))%10;
			else
			return fibo[n]=(tinhfibo(n/2)*(2*tinhfibo(n/2+1)-tinhfibo(n/2)))%10;
		}
	}
}
int main ()
{
	int n;
	cin>>n;
	cout<<tinhfibo(n);
	return 0;
}
