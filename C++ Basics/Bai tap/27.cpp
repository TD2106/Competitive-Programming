#include <iostream>
#include <cmath>
using namespace std;
int check(int a)
{
	int check=3;
	while(a>0)
	{
		if(a%10==3)
		{
			break;
			check=1;
		}
		a=a/10;
	}
	return check;
}
int dem(int n)
{
	int i=0;
	while(n>0)
	{
		i++;
		n=n/10;
	}
	return i;
}
int dao(int n,int i)
{
	int j=i-1,s=0;
	while(n>0)
	{
		s=s+n%10*pow(10,j);
		n=n/10;
		j--;
	}
	return s;
}
int daodaucuoi(int n,int i)
{
	int a=n/pow(10,i-1);
	int s=n-a*pow(10,i-1)+n%10*pow(10,i-1)-n%10+a;
	return s;
}
int main()
{
	int n;
	cin>>n;
	int a=n*n;
	if(check(a))
	cout<<"Co so 3 "<<endl;
	else
	cout<<"Ko co so 3 "<<endl;
	cout<<dao(n,dem(n))<<endl;
	cout<<daodaucuoi(n,dem(n))<<endl;	
}
