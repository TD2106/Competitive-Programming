#include <iostream>
#include <cmath>
using namespace std;
int binary(int n,int i)
{
	int s;
	if(n==0)
	return 0;
	else
	return s=pow(10,i)*(n%2)+binary(n/2,i+1);
}
int dem(int n)
{
	int i=0;
	while (n!=0)
	{
		i++;
		n=n/10;
	}
	return i;
	
}
int dao(int n,int dem)
{
	int s=0;
	for (int i=1;i<=dem;i++)
	{
		s=s+(n%10)*pow(10,dem-i);
		n=n/10;
	}
	return s;
}

int main ()
{
	for(int i=1;i<pow(10,6);i++){
	if(i==dao(i,dem(i)))
	cout<<i<<" la so polindrom he co so 10 "<<endl;
	if(binary(i,0)==dao(binary(i,0),dem(binary(i,0))))
	cout<<i<<" la so polindrom he co so 2 "<<endl;
}
return 0;
}
