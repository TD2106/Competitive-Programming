#include <iostream>     
#include <algorithm>    
#include <vector>    
#include <bitset>   
using namespace std;
int characterA[46];
int fibonacci[46];
bitset<46> checkA;
int fibo(int n,int k)
{
	if(k==0)
	return 0;
	if(k==fibonacci[n])
	{
		if(checkA[n])
		return characterA[n];
		else
		{
			checkA[n]=1;
			return characterA[n]=fibo(n-1,fibonacci[n-1])+fibo(n-2,fibonacci[n-2]);
		}
	}
	else
	{
		for(int i=n-2;i>=0;i-=2)
		{
			if(k>=fibonacci[i])
			{
				return fibo(i,fibonacci[i])+fibo(i+1,k-fibonacci[i]);
				break;
			}
		}
	}
}
int main ()
{
	checkA[0]=checkA[1]=1;
	characterA[0]=1;
	characterA[1]=0;
	fibonacci[0]=fibonacci[1]=1;
	for(int i=2;i<=45;i++)
	{
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
	}
	int testcase,n,k;
	cin>>testcase;
	while(testcase--)
	{
		cin>>n>>k;
		cout<<fibo(n,k)<<"\n";
	}
	return 0;
}
