#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
void binary (int arr[],long long int n)
{
	if(n>=0)
	arr[0]=0;
	else
	{
		arr[0]=1;
		n=pow(2,31)+n;
	}
	int i=31;
	while(n)
	{
		arr[i]=n%2;
		n=n/2;
		i--;
	}
}
void reverse (int arr[],int result[])
{
	int i=0,j;
	for(int i=0,j=24;i<8;i++,j++)
	result[i]=arr[j];
	for(int i=8,j=16;i<16;i++,j++)
	result[i]=arr[j];
	for(int i=16,j=8;i<24;i++,j++)
	result[i]=arr[j];
	for(int i=24,j=0;i<32;i++,j++)
	result[i]=arr[j];
}
long long int decimal (int result[])
{
	long long int convert=0;
	for(int i=31;i>0;i--)
	convert=convert+result[i]*pow(2,31-i);
	if(result[0]==1)
	convert=convert-pow(2,31);
	return convert;
}

int main ()
{
	long long int input;
	while(cin>>input)
	{
		int arr[32]={0},result[32]={0};
		binary(arr,input);
		reverse(arr,result);
		cout<<input<<" converts to "<<decimal(result)<<"\n";
	}
	return 0;
}
